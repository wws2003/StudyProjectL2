//
//  PThreadMutexLockImpl.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__PThreadMutexLockImpl__
#define __MyReadWriteLock__PThreadMutexLockImpl__

#include <iostream>
#include "ILock.h"
#include "common.h"
#include <pthread.h>

class PThreadMutexLockImpl : public ILock {
public:
    PThreadMutexLockImpl();
    virtual ~PThreadMutexLockImpl();
    
    //@Override
    virtual void lock() throw(LockException);
    
    //@Override
    virtual void trylock() throw(LockException);
    
    //@Override
    virtual void unlock() throw(LockException);

    inline pthread_mutex_t* getMutexPtr() {return &m_mutex;};
    
private:
    pthread_mutex_t m_mutex;
    
};

#endif /* defined(__MyReadWriteLock__PThreadMutexLockImpl__) */
