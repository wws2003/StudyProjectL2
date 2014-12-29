//
//  PThreadReadLockImpl.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PThreadReadLockImpl.h"
#include "RWCritical.h"
#include "PThreadMutexLockImpl.h"

PThreadReadLockImpl::PThreadReadLockImpl() : m_pCondVar(NULL) {
   
}

PThreadReadLockImpl::PThreadReadLockImpl(pthread_cond_t* pCondVar) : m_pCondVar(pCondVar) {
    
}

PThreadReadLockImpl::~PThreadReadLockImpl() {
}

//@Override
void PThreadReadLockImpl::wait() {
    //temporally casting, consider other solution for this kind of problem
    PThreadMutexLockImpl* pMutex = dynamic_cast<PThreadMutexLockImpl*>(m_pRWCritical->getLockPtr());
    pthread_cond_wait(m_pCondVar, pMutex->getMutexPtr());
}

//@Override
void PThreadReadLockImpl::signal() {
    pthread_cond_broadcast(m_pCondVar);
}