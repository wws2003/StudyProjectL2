package com.techburg.autospring.service.abstr;

import java.util.List;

import com.techburg.autospring.model.BuildInfoPersistenceQuery;
import com.techburg.autospring.model.business.BuildInfo;

public interface IBuildInfoPersistenceService {
	public int persistBuildInfo(BuildInfo buildInfo);
	public int loadBuildInfo(List<BuildInfo> buildInfoList, BuildInfoPersistenceQuery query);
	public int removeBuildInfoByID(long id);
}
