package com.techburg.autospring.factory.impl;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.InitializingBean;
import org.springframework.beans.factory.annotation.Autowired;

import com.techburg.autospring.factory.abstr.IBuildTaskFactory;
import com.techburg.autospring.model.BuildScriptPersistenceQuery;
import com.techburg.autospring.model.BasePersistenceQuery.DataRange;
import com.techburg.autospring.model.business.BuildScript;
import com.techburg.autospring.service.abstr.IBuildInfoPersistenceService;
import com.techburg.autospring.service.abstr.IBuildScriptPersistenceService;
import com.techburg.autospring.task.abstr.IBuildTask;
import com.techburg.autospring.task.impl.BuildTaskUnixScriptImpl;

public class UnixScriptBuildTaskFactoryImpl implements IBuildTaskFactory, InitializingBean {

	private IBuildInfoPersistenceService mPersistenceService;
	private IBuildScriptPersistenceService mBuildScriptPersistenceService;
	
	private static final String gLogFilePathPrefix = "log";
	private static final String gLogFileExtension = "log";
	
	private String mLogFileLocation;
	private String mDefaultScriptFileLocation;
	private String mDefaultScriptFileName;

	@Autowired
	public void setBuildInfoPersistenceService(IBuildInfoPersistenceService persistenceService) {
		mPersistenceService = persistenceService;
	}
	
	@Autowired
	public void setBuildScriptPersistenceService(IBuildScriptPersistenceService buildScriptPersistenceService) {
		mBuildScriptPersistenceService = buildScriptPersistenceService;
	}
	
	public void setLogFileLocation(String logFileLocation) {
		mLogFileLocation = logFileLocation;
	}
	
	public void setDefaultScriptFileLocation(String scriptFileLocation) {
		mDefaultScriptFileLocation = scriptFileLocation;
	}
	
	public void setDefaultScriptFileName(String scriptFileName) {
		mDefaultScriptFileName = scriptFileName;
	}

	@Override
	public IBuildTask getNewBuildTask() {
		BuildTaskUnixScriptImpl buildTask = new BuildTaskUnixScriptImpl(gLogFilePathPrefix, gLogFileExtension, mLogFileLocation, mDefaultScriptFileLocation, mDefaultScriptFileName);
		buildTask.setBuildInfoPersistenceService(mPersistenceService);
		return buildTask;
	}

	@Override
	public void afterPropertiesSet() throws Exception {
		//Fake to create a fixed script
		List<BuildScript> buildScripts = new ArrayList<BuildScript>();
		if(mBuildScriptPersistenceService != null) {
			BuildScriptPersistenceQuery query = new BuildScriptPersistenceQuery();
			query.mDataRange = DataRange.ID_MATCH;
			query.id = 1;
			mBuildScriptPersistenceService.loadBuildScript(buildScripts, query);
			if(buildScripts.isEmpty()) {
				BuildScript buildScript = new BuildScript();
				buildScript.setScriptFilePath(mDefaultScriptFileLocation + File.separator + mDefaultScriptFileName);
				mBuildScriptPersistenceService.persistBuildScript(buildScript);
			}
		}
	}

}
