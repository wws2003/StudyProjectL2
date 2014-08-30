package com.techburg.autospring.task.abstr;

import java.util.Date;

import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.service.abstr.IPersistenceService;

public abstract class AbstractBuildTask implements IBuildTask{
	protected long mId;
	protected IPersistenceService mPersistenceService;

	private int mStatus;
	private Date mBeginBuildTime;
	private Date mEndBuildTime;
	private String mLogFilePathPrefix;

	public AbstractBuildTask(String logFilePathPrefix) {
		mLogFilePathPrefix = logFilePathPrefix;
	}

	public void setPersistenceService(IPersistenceService persistenceService) {
		mPersistenceService = persistenceService;
	}

	@Override
	public long getId() {
		return mId;
	}

	@Override
	public int execute() {
		mBeginBuildTime = new Date();
		int ret = mainExecute();
		mEndBuildTime = new Date();
		mStatus = ret;
		return ret;
	}

	@Override
	public void storeToBuildInfo(BuildInfo buildInfo, boolean toPersist) {
		buildInfo.setBeginTimeStamp(mBeginBuildTime);
		buildInfo.setEndTimeStamp(mEndBuildTime);
		buildInfo.setStatus(mStatus);
		
		String logFilePath = "Not known yet";
		//If this is already built, specified the log file path
		if(toPersist && mBeginBuildTime != null)
			logFilePath = mLogFilePathPrefix + "_" + mBeginBuildTime.getTime();
		buildInfo.setLogFilePath(logFilePath);

		if(toPersist && mPersistenceService != null) {
			System.out.println("--------------------------Trying to persist new build info---------------------");
			mPersistenceService.persistBuildInfo(buildInfo);
		}
	}

	protected abstract int mainExecute();
}
