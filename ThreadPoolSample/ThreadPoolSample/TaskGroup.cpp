//
//  AbstractTaskGroup.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "TaskGroup.h"
#include "AbstractThreadPool.h"
#include "AbstractChildTask.h"
#include "AbstractMasterTask.h"

TaskGroup::TaskGroup(AbstractThreadPoolPtr threadPoolPtr, AbstractMasterTaskPtr masterTaskPtr, std::vector<AbstractChildTaskPtr> childTaskPtrs) :m_threadPoolPtr(threadPoolPtr), m_masterTaskPtr(masterTaskPtr) {
    m_childTaskPtrs.clear();
    m_childTaskPtrs.insert(m_childTaskPtrs.begin(), childTaskPtrs.begin(), childTaskPtrs.end());
}

TaskGroup::~TaskGroup() {
    
}

void TaskGroup::execute() {
    m_threadPoolPtr->addTask(m_masterTaskPtr);
    for (unsigned int i = 0; i < m_childTaskPtrs.size(); i++) {
        m_threadPoolPtr->addTask(m_childTaskPtrs[i]);
    }
    m_threadPoolPtr->initAndStart();
}