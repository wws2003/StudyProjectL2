package com.techburg.autospring.factory.impl;

import org.springframework.beans.factory.annotation.Autowired;

import com.techburg.autospring.factory.abstr.IBuildTaskFactory;
import com.techburg.autospring.service.abstr.IPersistenceService;
import com.techburg.autospring.task.abstr.IBuildTask;
import com.techburg.autospring.task.impl.BuildTaskUnixScriptImpl;

public class UnixScriptBuildTaskFactoryImpl implements IBuildTaskFactory {

	private IPersistenceService mPersistenceService;
	private static final String gLogFilePathPrefix = "log";
	private static final String gLogFileExtension = "log";
	
	private String mLogFileLocation;
	private String mScriptFileLocation;
	private String mScriptFileName;

	@Autowired
	public void setPersistenceService(IPersistenceService persistenceService) {
		mPersistenceService = persistenceService;
	}
	
	public void setLogFileLocation(String logFileLocation) {
		mLogFileLocation = logFileLocation;
	}
	
	public void setScriptFileLocation(String scriptFileLocation) {
		mScriptFileLocation = scriptFileLocation;
	}
	
	public void setScriptFileName(String scriptFileName) {
		mScriptFileName = scriptFileName;
	}

	@Override
	public IBuildTask getNewBuildTask() {
		BuildTaskUnixScriptImpl buildTask = new BuildTaskUnixScriptImpl(gLogFilePathPrefix, gLogFileExtension, mLogFileLocation, mScriptFileLocation, mScriptFileName);
		buildTask.setPersistenceService(mPersistenceService);
		return buildTask;
	}

}
