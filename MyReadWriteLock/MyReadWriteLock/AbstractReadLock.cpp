//
//  ReadLock.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractReadLock.h"
#include "RWCritical.h"

//@Override
void AbstractReadLock::lock() throw(LockException) {
    m_pRWCritical->getLockPtr()->lock();
    m_pRWCritical->acquireReadSemaphore();
    while (m_pRWCritical->isWritting()) {
        wait();
    }
    m_pRWCritical->getLockPtr()->unlock();
}

//@Override
void AbstractReadLock::trylock() throw(LockException) {
    //TODO Implement this
}

//@Override
void AbstractReadLock::unlock() throw(LockException) {
    m_pRWCritical->getLockPtr()->lock();
    m_pRWCritical->releaseReadSemaphore();
    m_pRWCritical->getLockPtr()->unlock();
    signal();
}

void AbstractReadLock::setRWCriticalPtr(RWCriticalPtr pRWCritical) {
    m_pRWCritical = pRWCritical;
}