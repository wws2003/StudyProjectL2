package com.techburg.autospring.controller;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.techburg.autospring.factory.abstr.IBuildTaskFactory;
import com.techburg.autospring.model.BuildInfoPersistenceQuery;
import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.service.abstr.IBuildDataService;
import com.techburg.autospring.service.abstr.IPersistenceService;
import com.techburg.autospring.task.abstr.IBuildTask;
import com.techburg.autospring.task.abstr.IBuildTaskProcessor;
import com.techburg.autospring.util.FileUtil;

@Controller
public class BuildController {

	private static final String gServiceAvailableAttributeName = "serviceAvailable";
	private static final String gBuildingListAttributeName = "buildingList";
	private static final String gWaitingListAttributeName = "waitingList";
	private static final String gBuiltListAttributeName = "builtList";

	private IBuildDataService mBuildDataService;
	private IBuildTaskProcessor mBuildTaskProcessor;
	private IBuildTaskFactory mBuildTaskFactory;
	private IPersistenceService mPersistenceService;

	@Autowired
	public void setBuildDataService(IBuildDataService buildDataService) {
		mBuildDataService = buildDataService;
	}

	@Autowired
	public void setBuildTaskProcessor(IBuildTaskProcessor buildTaskProcessor) {
		mBuildTaskProcessor = buildTaskProcessor;
	}

	@Autowired
	public void setBuildTaskFactory(IBuildTaskFactory buildTaskFactory) {
		mBuildTaskFactory = buildTaskFactory;
	}

	@Autowired
	public void setPersistenceService(IPersistenceService persistenceService) {
		mPersistenceService = persistenceService;
	}

	@RequestMapping(value="/buildlist", method=RequestMethod.GET) 
	public String listBuildInfo(Model model) {
		if(mBuildDataService == null) {
			model.addAttribute(gServiceAvailableAttributeName, false);
			return "buildlist";
		}
		model.addAttribute(gServiceAvailableAttributeName, true);

		List<BuildInfo> buildingList = new ArrayList<BuildInfo>();
		List<BuildInfo> waitingList = new ArrayList<BuildInfo>();
		List<BuildInfo> builtList = new ArrayList<BuildInfo>();

		mBuildDataService.getBuildingBuildInfoList(buildingList);
		mBuildDataService.getWaitingBuildInfoList(waitingList);

		BuildInfoPersistenceQuery query = new BuildInfoPersistenceQuery();
		query.mDataRange = DataRange.ALL;
		mBuildDataService.getBuiltBuildInfoList(builtList, query);

		model.addAttribute(gBuildingListAttributeName, buildingList);
		model.addAttribute(gWaitingListAttributeName, waitingList);
		model.addAttribute(gBuiltListAttributeName, builtList);

		return "buildlist";
	}


	@RequestMapping(value="/testbuild", method=RequestMethod.GET) 
	public String testBuild(Model model) {

		//Assume 10 build tasks added
		for(int i = 0; i < 10; i++) {
			IBuildTask buildTask = mBuildTaskFactory.getNewBuildTask();
			mBuildTaskProcessor.addBuildTask(buildTask);
		}

		if(mBuildDataService == null) {
			model.addAttribute(gServiceAvailableAttributeName, false);
			return "buildlist";
		}
		model.addAttribute(gServiceAvailableAttributeName, true);

		List<BuildInfo> buildingList = new ArrayList<BuildInfo>();
		List<BuildInfo> waitingList = new ArrayList<BuildInfo>();
		List<BuildInfo> builtList = new ArrayList<BuildInfo>();

		mBuildDataService.getBuildingBuildInfoList(buildingList);
		mBuildDataService.getWaitingBuildInfoList(waitingList);

		BuildInfoPersistenceQuery query = new BuildInfoPersistenceQuery();
		query.mDataRange = DataRange.ALL;
		mBuildDataService.getBuiltBuildInfoList(builtList, query);

		model.addAttribute(gBuildingListAttributeName, buildingList);
		model.addAttribute(gWaitingListAttributeName, waitingList);
		model.addAttribute(gBuiltListAttributeName, builtList);

		return "buildlist";
	}

	@RequestMapping(value="/build", method=RequestMethod.GET) 
	public String tryToBuildATask(Model model) {
		if(mBuildDataService == null) {
			model.addAttribute(gServiceAvailableAttributeName, false);
		}
		else {
			model.addAttribute(gServiceAvailableAttributeName, true);
		}
		return "build";
	}

	@RequestMapping(value="/build", method=RequestMethod.POST) 
	public String buildTask(Model model) {

		IBuildTask buildTask = mBuildTaskFactory.getNewBuildTask();
		mBuildTaskProcessor.addBuildTask(buildTask);

		if(mBuildDataService == null) {
			model.addAttribute(gServiceAvailableAttributeName, false);
			return "buildlist";
		}
		model.addAttribute(gServiceAvailableAttributeName, true);

		List<BuildInfo> buildingList = new ArrayList<BuildInfo>();
		List<BuildInfo> waitingList = new ArrayList<BuildInfo>();
		List<BuildInfo> builtList = new ArrayList<BuildInfo>();

		mBuildDataService.getBuildingBuildInfoList(buildingList);
		mBuildDataService.getWaitingBuildInfoList(waitingList);

		BuildInfoPersistenceQuery query = new BuildInfoPersistenceQuery();
		query.mDataRange = DataRange.ALL;
		mBuildDataService.getBuiltBuildInfoList(builtList, query);

		model.addAttribute(gBuildingListAttributeName, buildingList);
		model.addAttribute(gWaitingListAttributeName, waitingList);
		model.addAttribute(gBuiltListAttributeName, builtList);

		return "buildlist";
	}

	@RequestMapping(value="/log/{buildId}", method=RequestMethod.GET) 
	public void showLog(@PathVariable long buildId, HttpServletResponse response) throws IOException {
		BuildInfoPersistenceQuery query = new BuildInfoPersistenceQuery();
		query.mDataRange = DataRange.ID_MATCH;
		query.id = buildId;

		List<BuildInfo> buildInfoList = new ArrayList<BuildInfo>();
		mPersistenceService.loadBuildInfo(buildInfoList, query);
		if (buildInfoList.size() > 0) {
			BuildInfo buildInfo = buildInfoList.get(0);
			String logFilePath = buildInfo.getLogFilePath();
			try {
				writeLogFileContentToServletResponse(logFilePath, response);
			}
			catch (Exception e) {
				e.printStackTrace();
				response.getWriter().println("Some error occured");
			}
		}
	}

	private void writeLogFileContentToServletResponse(String logFilePath, HttpServletResponse response) throws Exception {
		InputStream logFileInputStream = null;
		FileUtil fileUtil = new FileUtil();
		try {
			logFileInputStream = new BufferedInputStream(new FileInputStream(logFilePath));
			StringBuilder outputBuilder = new StringBuilder();
			fileUtil.getStringFromInputStream(logFileInputStream, outputBuilder);
			response.getWriter().println(outputBuilder.toString());
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		finally {
			logFileInputStream.close();
		}
	}
}
