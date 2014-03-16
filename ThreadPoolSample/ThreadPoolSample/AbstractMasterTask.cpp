//
//  AbstractMasterTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractMasterTask.h"
#include "IMutex.h"
#include "ICondVar.h"

AbstractMasterTask::AbstractMasterTask(ResultStore& resultStoreRef, const unsigned int numberOfJobTodo, IMutexPtr jobMutexPtr, ICondVarPtr jobCondPtr) : m_resultStoreRef(resultStoreRef), m_numberOfJobTodo(numberOfJobTodo), m_jobMutexPtr(jobMutexPtr), m_jobCondPtr(jobCondPtr) {
    
}

AbstractMasterTask::~AbstractMasterTask() {
    
}


void AbstractMasterTask::execute() {
    m_jobMutexPtr->lock();
    while (m_resultStoreRef.size() < m_numberOfJobTodo) {
        m_jobCondPtr->wait(m_jobMutexPtr);
    }
    m_jobMutexPtr->unlock();
    collectResults();
}