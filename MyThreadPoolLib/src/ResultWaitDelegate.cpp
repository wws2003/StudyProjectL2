//
//  ResultWaitDelegate.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ResultWaitDelegate.h"

ResultWaitDelegate::ResultWaitDelegate(MutexPtr jobMutexPtr, CondVarPtr jobCondPtr) :  m_jobMutexPtr(jobMutexPtr), m_jobCondPtr(jobCondPtr) {
    
}

ResultWaitDelegate::~ResultWaitDelegate() {
    
}

void ResultWaitDelegate::waitForResults(const ResultStore& resultStoreRef, const unsigned int numberOfJobTodo) {
    m_jobMutexPtr->lock();
    while (resultStoreRef.size() < numberOfJobTodo) {
        m_jobCondPtr->wait(m_jobMutexPtr);
    }
    m_jobMutexPtr->unlock();
}