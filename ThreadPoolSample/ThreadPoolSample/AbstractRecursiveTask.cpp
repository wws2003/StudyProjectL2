//
//  AbstractRecursiveTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/22/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractRecursiveTask.h"
#include "ResultWaitDelegate.h"
#include "ISubTaskDelegate.h"

AbstractRecursiveTask::AbstractRecursiveTask(ResultWaitDelegatePtr resultWaitPtr, ISubTaskDelegatePtr subTaskDelegatePtr) : AbstractDelegatingMasterTask(resultWaitPtr), m_subTaskDelagatePtr(subTaskDelegatePtr){
    
}

AbstractRecursiveTask::~AbstractRecursiveTask() {
    
}

void AbstractRecursiveTask::prepare() {
    AbstractRecursiveTaskPtrs subTaskPtrs;
    getSubTaskPtrs(subTaskPtrs);
    for (AbstractRecursiveTaskPtrs::const_iterator tIter = subTaskPtrs.begin(); tIter != subTaskPtrs.end(); tIter++) {
        AbstractRecursiveTaskPtr subTaskPtr = *tIter;
        m_subTaskDelagatePtr->executeTask(subTaskPtr);
    }
}
