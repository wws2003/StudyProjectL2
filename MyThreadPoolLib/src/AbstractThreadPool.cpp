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

AbstractThreadPool::AbstractThreadPool(IMutexPtr mutexPtr, ICondVarPtr condVarPtr, int numberOfThreads) : m_taskMutexPtr(mutexPtr), m_condVarPtr(condVarPtr), m_numberOfThreads(numberOfThreads), m_isStopped(true), m_numberOfIncompletedTask(0) {
    
}

AbstractThreadPool::~AbstractThreadPool() {
    delete m_condVarPtr;
    delete m_taskMutexPtr;
}

void AbstractThreadPool::addTask(ITaskPtr taskPtr) {
    m_taskMutexPtr->lock();
    
    m_taskPtrQueue.push_back(taskPtr);
    m_numberOfIncompletedTask = (int)m_taskPtrQueue.size();
    
    //printf("Added a new task\n");
    
    //Signal to wake up the thread blocking on m_condVarPtr
    //? Which thread to be waken up : Unknown from here?
    assert(m_condVarPtr->signal() == COND_VAR_ERROR_NONE);
    
    m_taskMutexPtr->unlock();
}

unsigned int AbstractThreadPool::addTaskBatch(const ITaskPtrs& taskPtrs) {
    m_taskMutexPtr->lock();
    
    unsigned int numberOfTaskAdded = 0;
    const unsigned int MAX_TASK_CAN_ADD = 10000000; //m_numberOfThreads;
    
    //To avoid deadlock, only conduct this operation if the task queue is empty
    
    if (m_taskPtrQueue.empty()) {
        for (ITaskPtrs::const_iterator tIter = taskPtrs.begin(); tIter != taskPtrs.end() && numberOfTaskAdded < MAX_TASK_CAN_ADD; tIter++) {
            //printf("Added a new task\n");
            ITaskPtr taskPtr = *tIter;
            m_taskPtrQueue.push_back(taskPtr);
            numberOfTaskAdded++;
        }
        assert(m_condVarPtr->signal() == COND_VAR_ERROR_NONE);
    }
    m_numberOfIncompletedTask = (int)m_taskPtrQueue.size();
    m_taskMutexPtr->unlock();
    return numberOfTaskAdded;
}

void AbstractThreadPool::waitAllTaskComplete() {
    while (m_numberOfIncompletedTask > 0) {
        this->sleep(5);
    }
}

ThreadPoolErrorCode AbstractThreadPool::destroy() {
    m_taskMutexPtr->lock();
    m_isStopped = true;
    m_condVarPtr->broadcast();
    m_taskMutexPtr->unlock();
    joinAllThreads();
    return THREADPOOL_ERROR_NONE;
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
        };
        if (!m_isStopped) {
            ITaskPtr currentTask = m_taskPtrQueue.front();
            m_taskPtrQueue.pop_front();
            
            //printf("To process a task in thread id = %ld\n", currentThreadId());
            //Unlock the queue while task is being executed
            m_taskMutexPtr->unlock();
            currentTask->execute();
            m_taskMutexPtr->lock();
            m_numberOfIncompletedTask = (int)m_taskPtrQueue.size();
        }
    }
    m_taskMutexPtr->unlock();
}