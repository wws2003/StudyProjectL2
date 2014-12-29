//
//  ReadWriteLockTester.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <vector>
#include <exception>
#include <cstdio>
#include <ctime>
#include "ReadWriteLockTester.h"
#include "PThreadWriteLockImpl.h"
#include "LockScoper.h"

void* readThreadJob(void* arg);

void* readWriteThreadJob(void* arg);

void* writeWriteThreadJob(void* arg);

unsigned long getCurrentThreadId();

void randomSleepDurationInMicroseconds(long &microsecond);

void sleep(long microseconds);

ReadWriteLockTester::ReadWriteLockTester() : m_valueToTestRead(0), m_pReadLock(NULL) {
    
}

ReadWriteLockTester::~ReadWriteLockTester() {
    
}

void ReadWriteLockTester::setReadLockPtr(AbstractReadLockPtr pReadLock) {
    m_pReadLock = pReadLock;
}

void ReadWriteLockTester::setWriteLockPtr(AbstractWriteLockPtr pWriteLock) {
    m_pWriteLock = pWriteLock;
}

void ReadWriteLockTester::setValueToTestRW(int valueToTestRead) {
    m_valueToTestRead = valueToTestRead;
}

int ReadWriteLockTester::testReadRead() {
    return multiThreadTest(readThreadJob);
}

int ReadWriteLockTester::testReadWrite() {
    return multiThreadTest(readWriteThreadJob);
}

int ReadWriteLockTester::testWriteWrite() {
    return multiThreadTest(writeWriteThreadJob);
}

int ReadWriteLockTester::multiThreadTest(void * (*pRoutine)(void*)) {
    std::vector<pthread_t> threads;
    int ret = ERR_NONE;
    
    const int numberOfTestThread = 15;
    for (int i = 0; i < numberOfTestThread; i++) {
        pthread_t tid;
        int ret = pthread_create(&tid, NULL, pRoutine, this);
        if (ret == -1) {
            ret = ERR_THREAD_CREATE;
            break;
        }
        threads.push_back(tid);
    }
    
    for (pthread_t tid : threads) {
        void* result = NULL;
        pthread_join(tid, &result);
    }
    return ret;
}

void ReadWriteLockTester::doRead() {
    LockScoper scoper(m_pReadLock);
    scoper.lock();
    try {
        
        //printf("In read lock of thread %ld\n", getCurrentThreadId());
        //Block forvever
        //while (1) {
        //    ;
        //}
        
        printf("Read value %d at thread %ld\n", m_valueToTestRead, getCurrentThreadId());
    } catch (std::exception& e) {
        printf("Exception occurred %s\n", e.what());
    }
}

void ReadWriteLockTester::doWrite() {
    printf("Write task of thread %ld before get lock\n", getCurrentThreadId());
    LockScoper scoper(m_pWriteLock);
    scoper.lock();
    
    try {
        
        //printf("In write lock of thread %ld\n", getCurrentThreadId());
        //Block forvever
        //while (1) {
        //    ;
        //}
        
        m_valueToTestRead += 10;
        printf("Write value %d at thread %ld\n", m_valueToTestRead, getCurrentThreadId());
    } catch (std::exception& e) {
        printf("Exception occurred %s\n", e.what());
    }
}

//like-objectiveC-Category routines implementation

void* readThreadJob(void* arg)
{
    ReadWriteLockTester* pTester = (ReadWriteLockTester*)arg;
    long sleepDurationInMicroseconds;
    randomSleepDurationInMicroseconds(sleepDurationInMicroseconds);
    sleep(sleepDurationInMicroseconds);
    pTester->doRead();
    return NULL;
}

void* readWriteThreadJob(void* arg) {
    ReadWriteLockTester* pTester = (ReadWriteLockTester*)arg;
    long sleepDurationInMicroseconds;
    randomSleepDurationInMicroseconds(sleepDurationInMicroseconds);
    sleep(sleepDurationInMicroseconds);
    bool doRead = rand() % 2 == 0;
    if (doRead) {
        pTester->doRead();
    }
    else {
        pTester->doWrite();
    }
    return NULL;

}

void* writeWriteThreadJob(void* arg) {
    ReadWriteLockTester* pTester = (ReadWriteLockTester*)arg;
    long sleepDurationInMicroseconds;
    randomSleepDurationInMicroseconds(sleepDurationInMicroseconds);
    sleep(sleepDurationInMicroseconds);
    pTester->doWrite();
    return NULL;
}

void randomSleepDurationInMicroseconds(long &microseconds) {
    long max = 10000000;
    microseconds = random() % max;
}

void sleep(long microseconds) {
    struct timespec t1, t2;
    t1.tv_sec = 0;
    t1.tv_nsec = microseconds * 1000;
    nanosleep(&t1, &t2);
}

unsigned long getCurrentThreadId() {
    pthread_t selfThread = pthread_self();
#ifdef __APPLE__
    unsigned long long threadId;
    pthread_threadid_np(selfThread, &threadId);
    return threadId;
#elif __linux
    return (long)selfThread;
#endif
}