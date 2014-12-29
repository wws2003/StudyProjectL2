//
//  AbstractDelegatingSlaveTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractDelegatingSlaveTask.h"
#include "IResultSignalDelegate.h"

AbstractDelegatingSlaveTask::AbstractDelegatingSlaveTask(IResultSignalDelegatePtr resultSignalDelegatePtr, ResultStore& resultStoreRef) : m_resultSignalDelegatePtr(resultSignalDelegatePtr), m_resultStoreRef(resultStoreRef){
    
}

AbstractDelegatingSlaveTask::~AbstractDelegatingSlaveTask() {
    
}

void AbstractDelegatingSlaveTask::execute() {
    ResultPtr resultPtr = mainExecute();
    reportResult(resultPtr);
}

void AbstractDelegatingSlaveTask::reportResult(ResultPtr resultPtr) {
    m_resultSignalDelegatePtr->reportResult(m_resultStoreRef, resultPtr);
}