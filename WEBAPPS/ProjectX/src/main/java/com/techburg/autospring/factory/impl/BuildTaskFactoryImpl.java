package com.techburg.autospring.factory.impl;

import org.springframework.beans.factory.annotation.Autowired;

import com.techburg.autospring.factory.abstr.IBuildTaskFactory;
import com.techburg.autospring.service.abstr.IPersistenceService;
import com.techburg.autospring.task.abstr.AbstractBuildTask;
import com.techburg.autospring.task.abstr.IBuildTask;
import com.techburg.autospring.task.impl.BuildTaskMockImpl;

public class BuildTaskFactoryImpl implements IBuildTaskFactory{
	private static final String gLogFilePrefix = "log";
	private static final String gLogFileExtension = "log";
	private IPersistenceService mPersistenceService;
	
	@Autowired
	public void setPersistenceService(IPersistenceService persistenceService) {
		mPersistenceService = persistenceService;
	}
	
	public IBuildTask getNewBuildTask() {
		AbstractBuildTask buildTask = new BuildTaskMockImpl(gLogFilePrefix, gLogFileExtension);
		buildTask.setPersistenceService(mPersistenceService);
		return buildTask;
	}
}
