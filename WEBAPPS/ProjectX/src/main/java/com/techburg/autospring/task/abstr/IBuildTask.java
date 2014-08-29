package com.techburg.autospring.task.abstr;

import com.techburg.autospring.model.business.BuildInfo;

public interface IBuildTask {
	public static class BuildTaskResult {
		public static final int SUCCESSFUL = 0;
		public static final int FAILED = 1;
	}
	int execute();
	void storeToBuildInfo(BuildInfo buildInfo, boolean toPersist);
	long getId();
}
