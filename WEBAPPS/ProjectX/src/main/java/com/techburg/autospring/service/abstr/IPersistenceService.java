package com.techburg.autospring.service.abstr;

import java.util.List;

import com.techburg.autospring.model.BuildInfoPersistenceQuery;
import com.techburg.autospring.model.business.BuildInfo;

public interface IPersistenceService {
	public static class PersistenceResult {
		public static final int INVALID_QUERY = -1;
		public static final int PERSISTENCE_SUCCESSFUL = 0;
		public static final int PERSISTENCE_FAILED = 1;
		public static final int LOAD_SUCCESSFUL = 2;
		public static final int LOAD_FAILED = 3;
		public static final int REMOVE_SUCCESSFUL = 4;
		public static final int REMOVE_FAILED = 5;
	}
	
	public int persistBuildInfo(BuildInfo buildInfo);
	public int loadBuildInfo(List<BuildInfo> buildInfoList, BuildInfoPersistenceQuery query);
	public int removeBuildInfoByID(long id);
}
