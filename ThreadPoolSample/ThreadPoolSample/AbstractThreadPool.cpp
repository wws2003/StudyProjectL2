//
//  AbstractThreadPool.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractThreadPool.h"
#include "IMutex.h"
#include "ITask.h"
#include "ICondVar.h"
#include <assert.h>
#include <cstdio>

AbstractThreadPool::AbstractThreadPool(IMutexPtr mutexPtr, ICondVarPtr condVarPtr, int numberOfThreads) : m_taskMutexPtr(mutexPtr), m_condVarPtr(condVarPtr), m_numberOfThreads(numberOfThreads), m_isStopped(true) {
    
}

AbstractThreadPool::~AbstractThreadPool() {
    delete m_condVarPtr;
    delete m_taskMutexPtr;
}

void AbstractThreadPool::addTask(ITask* taskPtr) {
    m_taskMutexPtr->lock();
    
    m_taskPtrQueue.push_back(taskPtr);
    
    printf("Added a new task\n");
    //Signal to wake up the thread blocking on m_condVarPtr
    //? Which thread to be waken up ?
    assert(m_condVarPtr->signal() == COND_VAR_ERROR_NONE);
    
    m_taskMutexPtr->unlock();
}

void AbstractThreadPool::oneThreadJob() {
    m_taskMutexPtr->lock();
    while (!m_isStopped) {
        while (!m_isStopped && m_taskPtrQueue.empty()) {
             //Block until signaled, i.e. a new task is added to queue
             //Is this situation possible ?
             //If the mutex is still locked, can not add task to queue !
             //->wait must explicitly/implicitly unlock the mutex
             m_condVarPtr->wait(m_taskMutexPtr);
            
            //After return from wait, the mutex is assumed to be locked again
        }
        if (!m_isStopped) {
            ITaskPtr currentTask = m_taskPtrQueue.front();
            m_taskPtrQueue.pop_front();
            
            printf("To process a task\n");
            //Unlock the queue while task is being executed
            m_taskMutexPtr->unlock();
            currentTask->execute();
            m_taskMutexPtr->lock();
        }
    }
    m_taskMutexPtr->unlock();
}