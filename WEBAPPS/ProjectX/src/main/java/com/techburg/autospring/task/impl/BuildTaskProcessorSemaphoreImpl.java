package com.techburg.autospring.task.impl;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.List;
import java.util.concurrent.Semaphore;

import com.techburg.autospring.model.business.BuildInfo;
import com.techburg.autospring.task.abstr.IBuildTask;
import com.techburg.autospring.task.abstr.IBuildTaskProcessor;

public class BuildTaskProcessorSemaphoreImpl implements IBuildTaskProcessor {

	public BuildTaskProcessorSemaphoreImpl() {
		mWaitingTasks = new ArrayDeque<IBuildTask>();
		mQueueSemaphore = new Semaphore(1);
		mBuildThreadSemaphore = new Semaphore(1);
		mBuildingTask = null;
		mStopped = true;
	}

	@Override
	public int start() {
		int result = BuildTaskProcessorResult.START_SUCCESSFUL;
		try {
			mBuildThreadSemaphore.acquire();
			if(!mStopped) {
				result = BuildTaskProcessorResult.ALREADY_STARTED;
			}
			else {
				Runnable runnableTaskBuild = new Runnable() {	
					@Override
					public void run() {
						runBuildTasks();
					}
				};
				mBuildTaskThread = new Thread(runnableTaskBuild);
				mBuildTaskThread.start();
			}
			mBuildThreadSemaphore.release();
			return result;
		} 
		catch (InterruptedException e) {
			e.printStackTrace();
			return BuildTaskProcessorResult.START_FAILED;
		}
	}

	@Override
	public int addBuildTask(IBuildTask buildTask) {
		try {
			mQueueSemaphore.acquire();
			mWaitingTasks.add(buildTask);
			mQueueSemaphore.release();
			return BuildTaskProcessorResult.ADD_TASK_SUCCESSFUL;
		} catch (InterruptedException e) {
			e.printStackTrace();
			return BuildTaskProcessorResult.ADD_TASK_FAILED;
		}
	}

	@Override
	public int cancelTask(long taskId) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int cancelAllBuildTask() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int stop() {
		int result = BuildTaskProcessorResult.STOP_SUCCESSFUL;
		try {
			mBuildThreadSemaphore.acquire();
			if(mStopped) {
				result = BuildTaskProcessorResult.ALREADY_STOPPED;
			}
			else {
				mStopped = true;
				mBuildTaskThread.join();
			}
			mBuildThreadSemaphore.release();
		} catch (InterruptedException e) {
			e.printStackTrace();
			result = BuildTaskProcessorResult.STOP_FAILED;
		}
		
		return result;
	}

	@Override
	public void getBuildingBuildInfoList(List<BuildInfo> buildInfoList) {
		buildInfoList.clear();
		try {
			mQueueSemaphore.acquire();
			if(mBuildingTask != null) {
				BuildInfo buildingBuildInfo = new BuildInfo();
				mBuildingTask.storeToBuildInfo(buildingBuildInfo, false);
				buildInfoList.add(buildingBuildInfo);
			}
			mQueueSemaphore.release();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void getWaitingBuildInfoList(List<BuildInfo> buildInfoList) {
		buildInfoList.clear();
		try {
			mQueueSemaphore.acquire();
			for(IBuildTask waitingBuildTask : mWaitingTasks) {
				BuildInfo waitingBuildInfo = new BuildInfo();
				waitingBuildTask.storeToBuildInfo(waitingBuildInfo, false);
				buildInfoList.add(waitingBuildInfo);
			}
			mQueueSemaphore.release();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	private void runBuildTasks() {
		while(!mStopped) {
			try {
				mQueueSemaphore.acquire();
				IBuildTask nextBuildTask = mWaitingTasks.pop();
				mQueueSemaphore.release();

				if(nextBuildTask != null) {
					mBuildingTask = nextBuildTask;
					mBuildingTask.execute();
					BuildInfo buildInfo = new BuildInfo();
					mBuildingTask.storeToBuildInfo(buildInfo, true);
				}
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	private boolean mStopped;
	private Deque<IBuildTask> mWaitingTasks;
	private IBuildTask mBuildingTask;
	private Thread mBuildTaskThread = null;
	private Semaphore mQueueSemaphore;
	private Semaphore mBuildThreadSemaphore;
}
