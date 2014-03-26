//
//  AbstractDelegatingSlaveTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractDelegatingSlaveTask.h"
#include "ResultSignalDelegate.h"

AbstractDelegatingSlaveTask::AbstractDelegatingSlaveTask(ResultSignalDelegatePtr resultSignalDelegatePtr) : m_resultSignalDelegatePtr(resultSignalDelegatePtr){
    
}

AbstractDelegatingSlaveTask::~AbstractDelegatingSlaveTask() {
    
}

void AbstractDelegatingSlaveTask::execute() {
    mainExecute(m_resultSignalDelegatePtr->getResultPtr());
    reportResult();
}

void AbstractDelegatingSlaveTask::reportResult() {
    m_resultSignalDelegatePtr->reportResult();
}