//
//  AbstractDelegatingMasterTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractDelegatingMasterTask.h"
#include "ResultWaitDelegate.h"

AbstractDelegatingMasterTask::AbstractDelegatingMasterTask(ResultWaitDelegatePtr resultWaitDelegatePtr) : m_resultWaitDelegatePtr(resultWaitDelegatePtr), m_resultStoreRef(resultWaitDelegatePtr->getResultStoreRef()){
    
}

AbstractDelegatingMasterTask::~AbstractDelegatingMasterTask() {
    
}

//@Override
void AbstractDelegatingMasterTask::execute() {
    prepare();
    m_resultWaitDelegatePtr->waitForResult();
    collectResults();
}

