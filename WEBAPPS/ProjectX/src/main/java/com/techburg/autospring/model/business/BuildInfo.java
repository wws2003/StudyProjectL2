package com.techburg.autospring.model.business;

import java.util.Date;

public class BuildInfo {
	public static class Status {
		public static final int SUCCESSFUL = 0;
		public static final int FAILED = -1;
		public static final int BUILDING = 1;
		public static final int WAITING = 2;
	}
	
	private long mId;
	private int mStatus;
	private Date mBeginBuildTime;
	private Date mEndBuildTime;
	private String mLogFilePath;
	
	public long getId() {
		return mId;
	}
	public void setId(long mId) {
		this.mId = mId;
	}
	public int getStatus() {
		return mStatus;
	}
	public void setStatus(int mStatus) {
		this.mStatus = mStatus;
	}
	public Date getBeginTimeStamp() {
		return mBeginBuildTime;
	}
	public void setBeginTimeStamp(Date mBeginTimeStamp) {
		this.mBeginBuildTime = mBeginTimeStamp;
	}
	public Date getEndTimeStamp() {
		return mEndBuildTime;
	}
	public void setEndTimeStamp(Date mEndTimeStamp) {
		this.mEndBuildTime = mEndTimeStamp;
	}
	public String getLogFilePath() {
		return mLogFilePath;
	}
	public void setLogFilePath(String mLogFilePath) {
		this.mLogFilePath = mLogFilePath;
	}
}
