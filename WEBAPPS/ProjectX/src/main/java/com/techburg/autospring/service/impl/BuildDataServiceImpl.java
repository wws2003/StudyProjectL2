package com.techburg.autospring.service.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;

import com.techburg.autospring.model.BuildInfoPersistenceQuery;
import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.service.abstr.IBuildDataService;
import com.techburg.autospring.service.abstr.IPersistenceService;
import com.techburg.autospring.task.abstr.IBuildTaskProcessor;

public class BuildDataServiceImpl implements IBuildDataService {

	private IPersistenceService mPersistenceService = null;
	private IBuildTaskProcessor mBuildTaskProcessor = null;
	
	@Autowired
	public void setPersistenceService(IPersistenceService persistenceService) {
		mPersistenceService = persistenceService;
	}
	
	@Autowired
	public void setBuildTaskProcessor(IBuildTaskProcessor buildTaskProcessor) {
		mBuildTaskProcessor = buildTaskProcessor;
	}
	
	@Override
	public void getBuildingBuildInfoList(List<BuildInfo> buildInfoList) {
		mBuildTaskProcessor.getBuildingBuildInfoList(buildInfoList);
	}

	@Override
	public void getWaitingBuildInfoList(List<BuildInfo> buildInfoList) {
		mBuildTaskProcessor.getWaitingBuildInfoList(buildInfoList);
	}

	@Override
	public void getBuiltBuildInfoList(List<BuildInfo> buildInfoList,
			BuildInfoPersistenceQuery query) {
		mPersistenceService.loadBuildInfo(buildInfoList, query);
	}

}
