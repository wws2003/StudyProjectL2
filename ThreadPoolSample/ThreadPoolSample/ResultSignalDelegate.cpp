//
//  ResultSignalDelegate.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ResultSignalDelegate.h"

ResultSignalDelegate::ResultSignalDelegate(ResultStore& resultStoreRef, ResultPtr resultPtr, const unsigned int numberOfJobTodo, IMutexPtr jobMutexPtr, ICondVarPtr condMutexPtr) :m_resultStoreRef(resultStoreRef), m_resultPtr(resultPtr), m_numberOfJobTodo(numberOfJobTodo), m_jobMutexPtr(jobMutexPtr), m_condMutexPtr(condMutexPtr)  {
    
}

ResultSignalDelegate::~ResultSignalDelegate() {
    
}

ResultPtr ResultSignalDelegate::getResultPtr() {
    return m_resultPtr;
}

void ResultSignalDelegate::reportResult() {
    m_jobMutexPtr->lock();
    m_resultStoreRef.push_back(m_resultPtr);
    if (m_resultStoreRef.size() == m_numberOfJobTodo) {
        m_condMutexPtr->signal();
    }
    m_jobMutexPtr->unlock();
}