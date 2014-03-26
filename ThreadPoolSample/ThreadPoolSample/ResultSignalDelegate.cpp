//
//  ResultSignalDelegate.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ResultSignalDelegate.h"

ResultSignalDelegate::ResultSignalDelegate(IMutexPtr jobMutexPtr, ICondVarPtr condMutexPtr) :m_jobMutexPtr(jobMutexPtr), m_condMutexPtr(condMutexPtr)  {
    
}

ResultSignalDelegate::~ResultSignalDelegate() {
    
}

void ResultSignalDelegate::reportResult(ResultStore& resultStoreRef, const ResultPtr resultPtr) {
    m_jobMutexPtr->lock();
    resultStoreRef.push_back(resultPtr);
    m_condMutexPtr->signal();
    m_jobMutexPtr->unlock();
}