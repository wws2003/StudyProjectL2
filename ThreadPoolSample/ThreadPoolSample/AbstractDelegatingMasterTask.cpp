//
//  AbstractDelegatingMasterTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractDelegatingMasterTask.h"
#include "IResultWaitDelegate.h"

AbstractDelegatingMasterTask::AbstractDelegatingMasterTask(IResultWaitDelegatePtr resultWaitDelegatePtr) : m_resultWaitDelegatePtr(resultWaitDelegatePtr) {
    
}

AbstractDelegatingMasterTask::~AbstractDelegatingMasterTask() {
    
}

//@Override
void AbstractDelegatingMasterTask::execute() {
    prepare();
    waitForResults();
    collectResults();
}

void AbstractDelegatingMasterTask::addSlaveTaskPtr(AbstractDelegatingSlaveTaskPtr slaveTaskPtr) {
    m_slaveTaskPtrs.push_back(slaveTaskPtr);
}

void AbstractDelegatingMasterTask::waitForResults() {
    m_resultWaitDelegatePtr->waitForResults(m_resultStoreRef, (unsigned int)m_slaveTaskPtrs.size());
}