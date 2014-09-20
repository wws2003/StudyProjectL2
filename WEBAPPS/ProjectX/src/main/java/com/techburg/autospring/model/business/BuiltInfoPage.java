package com.techburg.autospring.model.business;

import java.util.List;

public class BuiltInfoPage {
	public static final int BUILD_INFO_PER_PAGE = 20;
	private int mPage;
	private long mFirstId;
	private long mLastId;
	private long mMaxId;
	private List<BuildInfo> mBuiltInfoList;
	
	public int getPage() {
		return mPage;
	}
	public void setPage(int page) {
		this.mPage = page;
	}
	
	public long getFirstId() {
		return mFirstId;
	}
	public void setFirstId(long firstId) {
		this.mFirstId = firstId;
	}
	
	public long getLastId() {
		return mLastId;
	}
	public void setLastId(long lastId) {
		this.mLastId = lastId;
	}
	
	public long getMaxId() {
		return mMaxId;
	}
	public void setMaxId(long maxId) {
		this.mMaxId = maxId;
	}
	
	public List<BuildInfo> getBuiltInfoList() {
		return mBuiltInfoList;
	}
	public void setBuiltInfoList(List<BuildInfo> buildInfoList) {
		this.mBuiltInfoList = buildInfoList;
	}
	
	public int getLastPage() {
		int page = (int) (mMaxId / BUILD_INFO_PER_PAGE);
		return mMaxId % BUILD_INFO_PER_PAGE == 0 ? page : page + 1;
	}
	
	public int getFirstPage() {
		return 1;
	}
	
}
