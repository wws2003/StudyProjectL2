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
import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.BuildInfoPersistenceQuery;
import com.techburg.autospring.model.BuildScriptPersistenceQuery;
import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.model.business.BuildScript;
import com.techburg.autospring.service.abstr.IBuildDataService;
import com.techburg.autospring.service.abstr.IBuildInfoPersistenceService;
import com.techburg.autospring.service.abstr.IBuildScriptPersistenceService;
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
	private IBuildInfoPersistenceService mBuildInfoPersistenceService;
	private IBuildScriptPersistenceService mBuildScriptPersistenceService;

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
	public void setBuildInfoPersistenceService(IBuildInfoPersistenceService persistenceService) {
		mBuildInfoPersistenceService = persistenceService;
	}
	
	@Autowired
	public void setBuildScriptPersistenceService(IBuildScriptPersistenceService buildScriptPersistenceService) {
		mBuildScriptPersistenceService = buildScriptPersistenceService;
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

	@RequestMapping(value="/testbuild/{numberOfBuildTask}", method=RequestMethod.GET) 
	public String testBuild(@PathVariable int numberOfBuildTask, Model model) {

		if(mBuildDataService == null) {
			model.addAttribute(gServiceAvailableAttributeName, false);
			return "buildlist";
		}
		
		for(int i = 0; i < numberOfBuildTask; i++) {
			long id = 1; // Just set an id for test
			BuildScript buildScript = getBuildScriptbyId(id);
			IBuildTask buildTask = mBuildTaskFactory.getNewBuildTask();
			buildTask.setBuildScript(buildScript);
			mBuildTaskProcessor.addBuildTask(buildTask);
		}
		
		return "redirect:/buildlist";
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
		if(mBuildDataService == null) {
			model.addAttribute(gServiceAvailableAttributeName, false);
			return "buildlist";
		}
		
		IBuildTask buildTask = mBuildTaskFactory.getNewBuildTask();
		long id = 1; //TODO In the future, read id from request params or something...
		BuildScript buildScript = getBuildScriptbyId(id);
		buildTask.setBuildScript(buildScript);
		mBuildTaskProcessor.addBuildTask(buildTask);
		
		return "hello";
	}

	@RequestMapping(value="/log/{buildId}", method=RequestMethod.GET) 
	public void showLog(@PathVariable long buildId, HttpServletResponse response) throws IOException {
		BuildInfoPersistenceQuery query = new BuildInfoPersistenceQuery();
		query.mDataRange = DataRange.ID_MATCH;
		query.id = buildId;

		List<BuildInfo> buildInfoList = new ArrayList<BuildInfo>();
		mBuildInfoPersistenceService.loadBuildInfo(buildInfoList, query);
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
	
	private BuildScript getBuildScriptbyId(long id) {
		List<BuildScript> buildScripts = new ArrayList<BuildScript>();
		if(mBuildScriptPersistenceService != null) {
			BuildScriptPersistenceQuery query = new BuildScriptPersistenceQuery();
			query.mDataRange = DataRange.ID_MATCH;
			query.id = id;
			mBuildScriptPersistenceService.loadBuildScript(buildScripts, query);
			return buildScripts.isEmpty() ? null : buildScripts.get(0);
		}
		return null;
	}
}
