package com.techburg.autospring.task.abstr;

import java.util.List;

import com.techburg.autospring.model.business.BuildInfo;

public interface IBuildTaskQueue {
	void addBuildTaskToQueue(IBuildTask buildTask);
	IBuildTask popBuildTaskFromQueue();
	void getBuildInfoListFromWaitingTaskList(List<BuildInfo> buildInfoList);
	void getBuildInfoListFromBuildingTask(List<BuildInfo> buildInfoList);
	
	void setBuildingTask(IBuildTask buildingTask);
	IBuildTask getBuildingTask();
}
