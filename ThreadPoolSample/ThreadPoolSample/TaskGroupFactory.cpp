//
//  TaskGroupFactory.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "TaskGroupFactory.h"
#include "TaskGroup.h"
#include "ThreadPoolFactory.h"
#include "IMutex.h"
#include "ICondVar.h"
#include "PMutex.h"
#include "PCondVar.h"
#include "SimpleChildTask.h"
#include "SumMasterTask.h"
#include "AbstractThreadPool.h"

TaskGroupFactory::TaskGroupFactory(unsigned int numberOfThread, unsigned int numberOfTask) {
    m_threadPoolPtr = ThreadPoolFactory::getThreadPoolPtr(numberOfThread + 1);
       m_jobMutexPtr = new PMutex();
    m_jobCondPtr = new PCondVar();
   
    numberOfTask = (numberOfTask == 0) ? numberOfThread : numberOfTask;
    m_resultPtrs = new int[numberOfTask];
    for (unsigned int i = 0; i < numberOfTask; i++) {
        AbstractChildTaskPtr childTaskPtr = new SimpleChildTask(m_resultStorePtr, &m_resultPtrs[i], numberOfTask, m_jobMutexPtr, m_jobCondPtr, i);
        m_childTaskPtrs.push_back(childTaskPtr);
    }
    
    m_masterTaskPtr = new SumMasterTask(m_resultStorePtr, numberOfTask, m_jobMutexPtr, m_jobCondPtr);
}

TaskGroupFactory::~TaskGroupFactory() {
    delete m_masterTaskPtr;
    for (unsigned int i = 0; i < m_childTaskPtrs.size(); i++) {
        delete m_childTaskPtrs[i];
    }
    m_childTaskPtrs.clear();
    delete m_jobCondPtr;
    delete m_jobMutexPtr;
    delete m_resultPtrs;
    m_threadPoolPtr->destroy();
    delete m_threadPoolPtr;
}

TaskGroupPtr TaskGroupFactory::getSampleTaskGroupPtr() {
    TaskGroupPtr taskGroupPtr = new TaskGroup(m_threadPoolPtr, m_masterTaskPtr, m_childTaskPtrs);
    return taskGroupPtr;
}