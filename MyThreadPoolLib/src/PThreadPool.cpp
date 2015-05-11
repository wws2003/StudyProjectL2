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
#include "IPThreadConfigurator.h"
#include <errno.h>
#include <pthread.h>
#include <assert.h>

void* start_thread(void* arg)
{
	PThreadPool* tp = (PThreadPool*) arg;
	tp->oneThreadJob();
	return NULL;
}

PThreadPool::PThreadPool(MutexPtr mutexPtr, CondVarPtr condVarPtr, int numberOfThreads, PThreadConfiguratorPtr pThreadConfigurator) : AbstractThreadPool(mutexPtr, condVarPtr, numberOfThreads) {
	m_tm1.tv_sec = 0;
	m_pThreadConfigurator = pThreadConfigurator;
}

PThreadPool::~PThreadPool() {
	//Need to explicitly destroy
	assert(m_isStopped);
}

TaskExecutorErrorCode PThreadPool::initAndStart(bool wait) {
	TaskExecutorErrorCode err = THREADPOOL_ERROR_NONE;
	m_isStopped = false;
	for (unsigned int i = 0; i < m_numberOfThreads; i++) {

		pthread_attr_t threadAttribute;
		pthread_attr_t* pThreadAttribute = NULL;

		if(m_pThreadConfigurator != NULL) {
			m_pThreadConfigurator->configThreadAttiribute(&threadAttribute);
			pThreadAttribute = &threadAttribute;
		}

		pthread_t tid;
		int ret = pthread_create(&tid, pThreadAttribute, start_thread, this);
		if (ret) {
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

void PThreadPool::joinAllThreads() {
	for (unsigned int i = 0; i < m_threads.size(); i++) {
		void* result = NULL;
		pthread_join(m_threads[i], &result);
		m_condVarPtr->broadcast();
	}
}

void PThreadPool::sleep(long microsecond) {
	struct timespec tm2;
	m_tm1.tv_nsec = microsecond * 1000;
	nanosleep(&m_tm1, &tm2);
}

unsigned long PThreadPool::currentThreadId() {
	pthread_t selfThread = pthread_self();
#ifdef __APPLE__
unsigned long long threadId;
pthread_threadid_np(selfThread, &threadId);
return threadId;
#elif __linux
return (long)selfThread;
#endif
}
