package com.techburg.autospring.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.service.abstr.IBuildDataService;

@Controller
public class BuildController {
	
	private static final String gServiceAvailableAttributeName = "serviceAvailable";
	private static final String gBuildingListAttributeName = "buildingList";
	private static final String gWaitingListAttributeName = "waitingList";
	private static final String gBuiltListAttributeName = "builtList";
	
	//TODO Setting to autowired this property 
	private IBuildDataService mBuildDataService;
	
	@Autowired
	public void setBuildDataService(IBuildDataService buildDataService) {
		mBuildDataService = buildDataService;
	}
	
	@RequestMapping(value="/testbuild", method=RequestMethod.GET) 
	public String testAutowireInWebApp(Model model) {
		if(mBuildDataService != null) {
			model.addAttribute(gServiceAvailableAttributeName, true);
		}
		else {
			model.addAttribute(gServiceAvailableAttributeName, false);
		}
		return "build";
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
		mBuildDataService.getBuildingBuildInfoList(builtList);
		
		model.addAttribute(gBuildingListAttributeName, buildingList);
		model.addAttribute(gWaitingListAttributeName, waitingList);
		model.addAttribute(gBuiltListAttributeName, builtList);
		
		return "buildlist";
	}
}
