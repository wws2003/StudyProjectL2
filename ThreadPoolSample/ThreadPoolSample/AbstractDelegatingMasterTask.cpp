//
//  AbstractDelegatingMasterTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractDelegatingMasterTask.h"
#include "IResultWaitDelegate.h"

AbstractDelegatingMasterTask::AbstractDelegatingMasterTask(IResultWaitDelegatePtr resultWaitDelegatePtr, ResultStore& resultStoreRef, unsigned int numberOfSlaveTasks) : m_resultWaitDelegatePtr(resultWaitDelegatePtr), m_resultStoreRef(resultStoreRef), m_numberOfSlaveTasks(numberOfSlaveTasks) {
    
}

AbstractDelegatingMasterTask::~AbstractDelegatingMasterTask() {
    
}

//@Override
void AbstractDelegatingMasterTask::execute() {
    prepare();
    waitForResults();
    collectResults();
}

void AbstractDelegatingMasterTask::waitForResults() {
    m_resultWaitDelegatePtr->waitForResults(m_resultStoreRef, m_numberOfSlaveTasks);
}