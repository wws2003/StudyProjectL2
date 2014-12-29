//
//  RecursiveTaskAssembler.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RecursiveTaskAssembler.h"
#include "AbstractRecursiveTask.h"
#include "SubTaskDelegateImpl.h"
#include "ResultDelegatePairFactoryImpl.h"
#include "AbstractThreadPool.h"
#include "ThreadPoolFactory.h"

RecursiveTaskAssembler::RecursiveTaskAssembler(unsigned int numberOfThread) {
    m_resultDelegatePairFactoryPtr = new ResultDelegatePairFactoryImpl();
    m_threadPoolPtr = ThreadPoolFactory::getThreadPoolPtr(numberOfThread);
    m_threadPoolPtr->initAndStart(false);
    m_subTaskDelegatePtr = new SubTaskDelegateImpl(m_threadPoolPtr);
}

RecursiveTaskAssembler::~RecursiveTaskAssembler() {
    delete m_subTaskDelegatePtr;
    m_threadPoolPtr->destroy();
    delete m_threadPoolPtr;
    delete m_resultDelegatePairFactoryPtr;
}

void RecursiveTaskAssembler::assembleRecursiveTask(AbstractRecursiveTaskPtr recursiveTaskPtr) {
    recursiveTaskPtr->setResultDelegatePairFactoryPtr(m_resultDelegatePairFactoryPtr);
    recursiveTaskPtr->setSubTaskDelegatePtr(m_subTaskDelegatePtr);
}