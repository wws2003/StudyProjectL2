package com.techburg.autospring.factory.impl;

import org.springframework.beans.factory.annotation.Autowired;

import com.techburg.autospring.factory.abstr.IBuildTaskFactory;
import com.techburg.autospring.service.abstr.IBuildInfoPersistenceService;
import com.techburg.autospring.task.abstr.AbstractBuildTask;
import com.techburg.autospring.task.abstr.IBuildTask;
import com.techburg.autospring.task.impl.BuildTaskMockImpl;

public class BuildTaskFactoryImpl implements IBuildTaskFactory{
	private static final String gLogFilePrefix = "log";
	private static final String gLogFileExtension = "log";
	private IBuildInfoPersistenceService mPersistenceService;
	
	@Autowired
	public void setBuildInfoPersistenceService(IBuildInfoPersistenceService persistenceService) {
		mPersistenceService = persistenceService;
	}
	
	public IBuildTask getNewBuildTask() {
		AbstractBuildTask buildTask = new BuildTaskMockImpl(gLogFilePrefix, gLogFileExtension);
		buildTask.setBuildInfoPersistenceService(mPersistenceService);
		return buildTask;
	}
}
