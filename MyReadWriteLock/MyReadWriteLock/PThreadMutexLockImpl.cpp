//
//  PThreadMutexLockImpl.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PThreadMutexLockImpl.h"

PThreadMutexLockImpl::PThreadMutexLockImpl() {
    pthread_mutex_init(&m_mutex, NULL);
}

PThreadMutexLockImpl::~PThreadMutexLockImpl() {
    pthread_mutex_destroy(&m_mutex);
}

//@Override
void PThreadMutexLockImpl::lock() throw(LockException){
    int rtLock = pthread_mutex_lock(&m_mutex);
    if (rtLock != 0) {
        LockException le(LockException::LOCK_EXCEPTION);
        throw le;
    }
}

//@Override
void PThreadMutexLockImpl::trylock() throw(LockException) {
    int rtTryLock = pthread_mutex_trylock(&m_mutex);
    if (rtTryLock != 0) {
        LockException le(LockException::TRYLOCK_EXCEPTION);
        throw le;
    }
}

//@Override
void PThreadMutexLockImpl::unlock() throw(LockException) {
    int rtUnlock = pthread_mutex_unlock(&m_mutex);
    if (rtUnlock != 0) {
        LockException le(LockException::UNLOCK_EXCEPTION);
        throw le;
    }
}