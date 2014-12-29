//
//  PThreadPool.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PThreadPool.h"
#include "IMutex.h"
#include "ICondVar.h"
#include <errno.h>
#include <pthread.h>
#include <assert.h>

void* start_thread(void* arg)
{
    PThreadPool* tp = (PThreadPool*) arg;
    tp->oneThreadJob();
    return NULL;
}

PThreadPool::PThreadPool(IMutexPtr mutexPtr, ICondVarPtr condVarPtr, int numberOfThreads) : AbstractThreadPool(mutexPtr, condVarPtr, numberOfThreads) {
    
}

PThreadPool::~PThreadPool() {
    //Need to explicitly destroy
    assert(m_isStopped);
}

ThreadPoolErrorCode PThreadPool::initAndStart(bool wait) {
    ThreadPoolErrorCode err = THREADPOOL_ERROR_NONE;
    m_isStopped = false;
    for (unsigned int i = 0; i < m_numberOfThreads; i++) {
        pthread_t tid;
        int ret = pthread_create(&tid, NULL, start_thread, this);
        if (ret == -1) {
            return INIT_THREAD_ERROR;
        }
        m_threads.push_back(tid);
    }
    if(wait)
        for (unsigned int i = 0; i < m_numberOfThreads; i++) {
            void* result = NULL;
            pthread_join(m_threads[i], &result);
        }
    return err;
}

ThreadPoolErrorCode PThreadPool::destroy() {
    m_taskMutexPtr->lock();
    m_isStopped = true;
    m_condVarPtr->broadcast();
    m_taskMutexPtr->unlock();
    for (unsigned int i = 0; i < m_threads.size(); i++) {
        void* result = NULL;
        pthread_join(m_threads[i], &result);
        m_condVarPtr->broadcast();
    }
    return THREADPOOL_ERROR_NONE;
}

unsigned long PThreadPool::currentThreadId() {
    pthread_t selfThread = pthread_self();
    unsigned long long threadId;
    pthread_threadid_np(selfThread, &threadId);
    return threadId;
}