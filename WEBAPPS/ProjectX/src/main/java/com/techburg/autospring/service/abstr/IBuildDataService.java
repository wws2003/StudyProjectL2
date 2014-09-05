package com.techburg.autospring.service.abstr;

import java.util.List;

import com.techburg.autospring.model.business.BuildInfo;

public interface IBuildDataService {
	void getBuildingBuildInfoList(List<BuildInfo> buildInfoList);
	void getWaitingBuildInfoList(List<BuildInfo> buildInfoList);
}