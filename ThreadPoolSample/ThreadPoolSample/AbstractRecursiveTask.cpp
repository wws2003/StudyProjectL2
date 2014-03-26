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

AbstractRecursiveTask::AbstractRecursiveTask(IResultWaitDelegatePtr subTaskResultsWaitPtr, ISubTaskDelegatePtr subTaskDelegatePtr, IResultSignalDelegatePtr resultSignalPtr, ResultStore& parentTaskResultStoreRef) :  m_subTaskResultsWaitDelegatePtr(subTaskResultsWaitPtr), m_subTaskDelagatePtr(subTaskDelegatePtr), m_resultSignalDelegatePtr(resultSignalPtr), m_parentResultStoreRef(parentTaskResultStoreRef) {
    
}

AbstractRecursiveTask::~AbstractRecursiveTask() {
    
}

void AbstractRecursiveTask::execute() {
    prepare();
    
    AbstractRecursiveTaskPtrs subTaskPtrs;
    getSubTaskPtrs(subTaskPtrs);
    
    //All sub tasks share the same result signal delegate ptr?
    
    unsigned int numberOfSubTaskNeedToWait = executeSubTasks(subTaskPtrs);
    ResultStore subResultStore;
    waitForResults(subResultStore, numberOfSubTaskNeedToWait);
    releaseSubResults(subResultStore);
    
    releaseSubTaskPtrs(subTaskPtrs);
    
    ResultPtr resultPtr = collectResults();
    reportResult(resultPtr);
}

unsigned int AbstractRecursiveTask::executeSubTasks(const AbstractRecursiveTaskPtrs& subTaskPtrs) {
    return m_subTaskDelagatePtr->executeSubTasks(subTaskPtrs);
}

void AbstractRecursiveTask::waitForResults(const ResultStore& subResultStoreRef, const unsigned int numberOfJobTodo) {
    m_subTaskResultsWaitDelegatePtr->waitForResults(subResultStoreRef, numberOfJobTodo);
}

void AbstractRecursiveTask::releaseSubTaskPtrs(const AbstractRecursiveTaskPtrs& subTaskPtrs) {
    for (unsigned int i = 0; i < subTaskPtrs.size(); i++) {
        delete subTaskPtrs[i];
    }
}

void AbstractRecursiveTask::reportResult(const ResultPtr resultPtr) {
    if(m_resultSignalDelegatePtr)
        m_resultSignalDelegatePtr->reportResult(m_parentResultStoreRef, resultPtr);
}