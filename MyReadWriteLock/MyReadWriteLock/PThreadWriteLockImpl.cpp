//
//  PThreadWriteLockImpl.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PThreadWriteLockImpl.h"
#include "RWCritical.h"
#include "PThreadMutexLockImpl.h"

PThreadWriteLockImpl::PThreadWriteLockImpl(): m_pCondVar(NULL)  {
}

PThreadWriteLockImpl::PThreadWriteLockImpl(pthread_cond_t* pCondVar) : m_pCondVar(pCondVar){
    
}

PThreadWriteLockImpl::~PThreadWriteLockImpl() {
}

//@Override
void PThreadWriteLockImpl::wait() {
    //temporally casting, consider other solution for this kind of problem
    PThreadMutexLockImpl* pMutex = dynamic_cast<PThreadMutexLockImpl*>(m_pRWCritical->getLockPtr());
    
    pthread_cond_wait(m_pCondVar, pMutex->getMutexPtr());
}

//@Override
void PThreadWriteLockImpl::signal() {
    pthread_cond_broadcast(m_pCondVar);
}