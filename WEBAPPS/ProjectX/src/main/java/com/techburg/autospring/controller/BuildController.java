package com.techburg.autospring.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.techburg.autospring.factory.abstr.IBuildTaskFactory;
import com.techburg.autospring.model.BuildInfoPersistenceQuery;
import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.service.abstr.IBuildDataService;
import com.techburg.autospring.task.abstr.IBuildTask;
import com.techburg.autospring.task.abstr.IBuildTaskProcessor;

@Controller
public class BuildController {
	
	private static final String gServiceAvailableAttributeName = "serviceAvailable";
	private static final String gBuildingListAttributeName = "buildingList";
	private static final String gWaitingListAttributeName = "waitingList";
	private static final String gBuiltListAttributeName = "builtList";
	
	private IBuildDataService mBuildDataService;
	private IBuildTaskProcessor mBuildTaskProcessor;
	private IBuildTaskFactory mBuildTaskFactory;
	
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
	public String testAutowireInWebApp(Model model) {
		
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
}
