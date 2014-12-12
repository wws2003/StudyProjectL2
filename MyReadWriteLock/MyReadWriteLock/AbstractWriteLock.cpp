//
//  AbstractWriteLock.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractWriteLock.h"
#include "RWCritical.h"

//@Override
void AbstractWriteLock::lock() throw(LockException) {
    m_pRWCritical->getLockPtr()->lock();
    while (m_pRWCritical->isWritting() || m_pRWCritical->getReadSemaphore() > 0) {
        wait();
    }
    m_pRWCritical->setWritting();
}

//@Override
void AbstractWriteLock::trylock() throw(LockException) {
    //TODO Implement this
}

//@Override
void AbstractWriteLock::unlock() throw(LockException) {
    m_pRWCritical->setWritting(false);
    m_pRWCritical->getLockPtr()->unlock();
    signal();
}

void AbstractWriteLock::setRWCriticalPtr(RWCriticalPtr pRWCritical) {
    m_pRWCritical = pRWCritical;
}