//
//  ReadLockAssembler.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <cassert>
#include "ReadLockAssembler.h"
#include "RWCritical.h"

template <class T>
static void releaseVector(std::vector<T*>& vector) {
    for (typename std::vector<T*>::iterator iter = vector.begin(); iter != vector.end();) {
        T* p = *iter;
        iter = vector.erase(iter);
        delete p;
    }
    assert(vector.size() == 0);
};

ReadLockAssembler::ReadLockAssembler() {
    
}

ReadLockAssembler::~ReadLockAssembler() {
    cleanUp();
}

AbstractReadLockPtr ReadLockAssembler::getAbstractReadLockPtr() {
    PThreadReadLockImpl* pReadLock = new PThreadReadLockImpl();
    RWCriticalPtr pRWCritical = new RWCritical();
    PThreadMutexLockImpl* pLockForRWCritical = new PThreadMutexLockImpl();
    pRWCritical->setLockPtr(pLockForRWCritical);
    pReadLock->setRWCriticalPtr(pRWCritical);
    
#if NORMAL_PTR
    m_pLockPthreadMutexImpls.push_back(pLockForRWCritical);
    m_pRWCriticals.push_back(pRWCritical);
    m_pReadLockPthreadImpls.push_back(pReadLock);
#endif
    
    return pReadLock;
}

void ReadLockAssembler::getReadWriteLockPair(AbstractReadLockPtr& pReadLock, AbstractWriteLockPtr& pWriteLock) {
    pthread_cond_t_ptr pCondVar = new pthread_cond_t();
    pthread_cond_init(pCondVar, NULL);
    
    RWCriticalPtr pRWCritical = new RWCritical();
    PThreadMutexLockImpl* pLockForRWCritical = new PThreadMutexLockImpl();
    pRWCritical->setLockPtr(pLockForRWCritical);
    
    PThreadReadLockImpl* pReadLockPThreadImpl = new PThreadReadLockImpl(pCondVar);
    pReadLockPThreadImpl->setRWCriticalPtr(pRWCritical);
    PThreadWriteLockImpl* pWriteLockPThreadImpl = new PThreadWriteLockImpl(pCondVar);
    pWriteLockPThreadImpl->setRWCriticalPtr(pRWCritical);
    
#if NORMAL_PTR
    m_pLockPthreadMutexImpls.push_back(pLockForRWCritical);
    m_pRWCriticals.push_back(pRWCritical);
    m_pReadLockPthreadImpls.push_back(pReadLockPThreadImpl);
    m_pWriteLockPThreadImpls.push_back(pWriteLockPThreadImpl);
    m_pCondVars.push_back(pCondVar);
#endif
    
    pReadLock = pReadLockPThreadImpl;
    pWriteLock = pWriteLockPThreadImpl;
    
}

void ReadLockAssembler::cleanUp() {
    for (pthread_cond_t_ptr pCondVar : m_pCondVars) {
        pthread_cond_destroy(pCondVar);
    }
#if NORMAL_PTR
    releaseVector<RWCritical>(m_pRWCriticals);
    releaseVector<PThreadMutexLockImpl>(m_pLockPthreadMutexImpls);
    releaseVector<PThreadReadLockImpl>(m_pReadLockPthreadImpls);
    releaseVector<PThreadWriteLockImpl>(m_pWriteLockPThreadImpls);
    releaseVector<pthread_cond_t>(m_pCondVars);
#endif
}