package com.techburg.autospring.task.impl;

import com.techburg.autospring.model.business.BuildInfo.Status;
import com.techburg.autospring.task.abstr.AbstractBuildTask;

public class BuildTaskMockImpl extends AbstractBuildTask {

	public BuildTaskMockImpl(String logFilePathPrefix) {
		super(logFilePathPrefix);
	}

	@Override
	protected int mainExecute() {
		try {
			System.out.println("--------------------------Build task to be executed---------------------");
			Thread.sleep(10000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		return Status.BUILD_SUCCESSFUL;
	}

}
