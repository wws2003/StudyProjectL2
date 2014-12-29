//
//  AbstractRecursiveTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/22/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractRecursiveTask.h"
#include "IResultWaitDelegate.h"
#include "IResultSignalDelegate.h"
#include "ISubTaskDelegate.h"
#include "ITask.h"
#include "IResultDelegatePairFactory.h"

AbstractRecursiveTask::AbstractRecursiveTask() : m_parentResultStorePtr(NULL),m_resultDelegatePairFactoryPtr(NULL), m_resultSignalDelegatePtr(NULL), m_subTaskDelagatePtr(NULL) {
    
}

AbstractRecursiveTask::~AbstractRecursiveTask() {
    
}

void AbstractRecursiveTask::execute() {
    prepare();
    
    AbstractRecursiveTaskPtrs subTaskPtrs;
    ResultStore subResultStore;
    
    getSubTaskPtrs(subTaskPtrs, subResultStore);
    
    executeSubTasks(subTaskPtrs, subResultStore);
    
    releaseSubTaskPtrs(subTaskPtrs);
    
    ResultPtr resultPtr = collectResults(subResultStore);
    releaseSubResults(subResultStore);
    reportResult(resultPtr);
}

void AbstractRecursiveTask::setParentResultStorePtr(ResultStorePtr parentResultStorePtr) {
    m_parentResultStorePtr = parentResultStorePtr;
}

void AbstractRecursiveTask::setSubTaskDelegatePtr(ISubTaskDelegatePtr subTaskDelegatePtr) {
    m_subTaskDelagatePtr = subTaskDelegatePtr;
}

void AbstractRecursiveTask::setResultSignalDelegatePtr(IResultSignalDelegatePtr resultSignalPtr) {
    m_resultSignalDelegatePtr = resultSignalPtr;
}

void AbstractRecursiveTask::setResultDelegatePairFactoryPtr(IResultDelegatePairFactoryPtr resultDelegateFactoryPtr) {
    m_resultDelegatePairFactoryPtr = resultDelegateFactoryPtr;
}

void AbstractRecursiveTask::executeSubTasks(AbstractRecursiveTaskPtrs& subTaskPtrs, ResultStore& subTaskResultStoreRef) {
    
    if (subTaskPtrs.empty()) {
        return;
    }
    
    //Call factory method to retrieve pair of wait delegate and sub task 's signal delegate
    IResultDelegatePtrPair resultDelegatePtrPair = m_resultDelegatePairFactoryPtr->getResultDelegatePtrPair();
    
    IResultWaitDelegatePtr subTaskResultWaitDelegatePtr = resultDelegatePtrPair.first;
    IResultSignalDelegatePtr subTaskResultSignalDelegatePtr = resultDelegatePtrPair.second;
    
    //All sub tasks share the same result signal delegate ptr
    for (AbstractRecursiveTaskPtrs::const_iterator tIter = subTaskPtrs.begin(); tIter != subTaskPtrs.end(); tIter++) {
        AbstractRecursiveTaskPtr subTaskPtr = *tIter;
        subTaskPtr->setParentResultStorePtr(&subTaskResultStoreRef);
        subTaskPtr->setSubTaskDelegatePtr(m_subTaskDelagatePtr);
        subTaskPtr->setResultDelegatePairFactoryPtr(m_resultDelegatePairFactoryPtr);
        subTaskPtr->setResultSignalDelegatePtr(subTaskResultSignalDelegatePtr);
    }
    
    //Execute sub tasks and wait for results
    unsigned int numberOfSubTaskNeedToWait = m_subTaskDelagatePtr->executeSubTasks(subTaskPtrs);
    waitForResults(subTaskResultWaitDelegatePtr, subTaskResultStoreRef, numberOfSubTaskNeedToWait);
    
    delete subTaskResultWaitDelegatePtr;
    delete subTaskResultSignalDelegatePtr;
}

void AbstractRecursiveTask::waitForResults(IResultWaitDelegatePtr resultWaitDelegatePtr, const ResultStore& subResultStoreRef, const unsigned int numberOfJobTodo) {
    resultWaitDelegatePtr->waitForResults(subResultStoreRef, numberOfJobTodo);
}

void AbstractRecursiveTask::releaseSubTaskPtrs(const AbstractRecursiveTaskPtrs& subTaskPtrs) {
    for (unsigned int i = 0; i < subTaskPtrs.size(); i++) {
        TASKPTR_DELETE(subTaskPtrs[i]);
    }
}

void AbstractRecursiveTask::reportResult(const ResultPtr resultPtr) {
    if(m_resultSignalDelegatePtr)
        m_resultSignalDelegatePtr->reportResult(*m_parentResultStorePtr, resultPtr);
}