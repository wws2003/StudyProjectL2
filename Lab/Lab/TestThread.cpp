//
//  TestThread.cpp
//  Lab
//
//  Created by wws2003 on 8/1/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <stdio.h>
#include "TestThread.h"
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct ThreadParams {
    pthread_cond_t* pCondVar;
    pthread_mutex_t* pMutex;
    const struct timespec * pAbstime;
} ThreadParams;

void initMutexAndCondvar(pthread_cond_t* pCondVar, pthread_mutex_t* pMutex) {
    pthread_mutex_init(pMutex, NULL);
    pthread_cond_init(pCondVar, NULL);
}

void initTimeSpec(struct timespec* pTimeSpec, const int timeOut) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    pTimeSpec->tv_sec = tv.tv_sec + timeOut;
    pTimeSpec->tv_nsec = 0;
}

void* jobOfThreadWaitingOnTime(void* pParam) {
    printf("Thread started\n");
    ThreadParams* pThreadParams = static_cast<ThreadParams*>(pParam);
    pthread_mutex_lock(pThreadParams->pMutex);
    int err = pthread_cond_timedwait(pThreadParams->pCondVar, pThreadParams->pMutex, pThreadParams->pAbstime);
    printf("Thread result %d\n", err);
    pthread_mutex_unlock(pThreadParams->pMutex);
    return  NULL;
    //Need to unlock mutex?
}

void wakeUpWaitingThread(pthread_cond_t* pCondVar, pthread_mutex_t* pMutex) {
    pthread_mutex_lock(pMutex);
    pthread_cond_broadcast(pCondVar);
    
    //Need to unlock mutex?
}

void testThreadWaitOnTimedCondVar() {
    //Create a thread which wait on a timed-wait condvar.
    pthread_cond_t condVar;
    pthread_mutex_t mutex;
    initMutexAndCondvar(&condVar, &mutex);

    int timeOut = 10;
    
    //Init time spec
    struct timespec pAbsTime;
    initTimeSpec(&pAbsTime, timeOut);
    
    ThreadParams threadParams;
    threadParams.pCondVar = &condVar;
    threadParams.pMutex = &mutex;
    threadParams.pAbstime = &pAbsTime;
    
    pthread_t tid;
    pthread_create(&tid, NULL, jobOfThreadWaitingOnTime, &threadParams);
    
    //After a time-out signal the waiting thread or join it
    bool toJoin = false;
    if (toJoin) {
        pthread_join(tid, NULL);
    }
    else {
        int beforeTimeOut = timeOut + 2;
        sleep(beforeTimeOut);
        wakeUpWaitingThread(&condVar, &mutex);
    }
}