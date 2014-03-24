//
//  AbstractTaskGroup.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "TaskGroup.h"
#include "AbstractThreadPool.h"
#include "AbstractDelegatingMasterTask.h"
#include "AbstractDelegatingSlaveTask.h"

TaskGroup::TaskGroup(AbstractThreadPoolPtr threadPoolPtr, AbstractDelegatingMasterTaskPtr masterTaskPtr, std::vector<AbstractDelegatingSlaveTaskPtr> childTaskPtrs) :m_threadPoolPtr(threadPoolPtr), m_masterTaskPtr(masterTaskPtr) {
    m_childTaskPtrs.clear();
    m_childTaskPtrs.insert(m_childTaskPtrs.begin(), childTaskPtrs.begin(), childTaskPtrs.end());
}

TaskGroup::~TaskGroup() {
    
}

void TaskGroup::execute() {
    m_threadPoolPtr->addTask(m_masterTaskPtr);
    for (unsigned int i = 0; i < m_childTaskPtrs.size(); i++) {
        AbstractDelegatingSlaveTaskPtr slaveTaskPtr = m_childTaskPtrs[i];
        m_threadPoolPtr->addTask(slaveTaskPtr);
    }
    m_threadPoolPtr->initAndStart();
}