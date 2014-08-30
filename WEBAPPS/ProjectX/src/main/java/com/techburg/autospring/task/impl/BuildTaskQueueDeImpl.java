package com.techburg.autospring.task.impl;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.List;
import java.util.NoSuchElementException;

import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.task.abstr.IBuildTask;
import com.techburg.autospring.task.abstr.IBuildTaskQueue;

public class BuildTaskQueueDeImpl implements IBuildTaskQueue {
	public BuildTaskQueueDeImpl() {
		mWaitingTasks = new ArrayDeque<IBuildTask>();
		mBuildingTask = null;
	}

	public synchronized void addBuildTaskToQueue(IBuildTask buildTask) {
		mWaitingTasks.add(buildTask);
	}

	public synchronized IBuildTask popBuildTaskFromQueue() {
		try {
			return mWaitingTasks.pop();
		}
		catch (NoSuchElementException e) {
			return null;
		}
	}

	public synchronized void getBuildInfoListFromWaitingTaskList(List<BuildInfo> buildInfoList) {
		for(IBuildTask waitingBuildTask : mWaitingTasks) {
			BuildInfo waitingBuildInfo = new BuildInfo();
			waitingBuildTask.storeToBuildInfo(waitingBuildInfo, false);
			buildInfoList.add(waitingBuildInfo);
		}
	}

	@Override
	public synchronized void getBuildInfoListFromBuildingTask(List<BuildInfo> buildInfoList) {
		BuildInfo buildingBuildInfo = new BuildInfo();
		if(mBuildingTask != null) {
			mBuildingTask.storeToBuildInfo(buildingBuildInfo, false);
			buildInfoList.add(buildingBuildInfo);
		}
	}

	@Override
	public synchronized void setBuildingTask(IBuildTask buildingTask) {
		mBuildingTask = buildingTask;
	}

	@Override
	public synchronized IBuildTask getBuildingTask() {
		return mBuildingTask;
	}

	private Deque<IBuildTask> mWaitingTasks;
	private IBuildTask mBuildingTask;
}
