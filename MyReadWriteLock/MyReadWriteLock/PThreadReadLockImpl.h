//
//  PThreadReadLockImpl.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__PThreadReadLockImpl__
#define __MyReadWriteLock__PThreadReadLockImpl__

#include <iostream>
#include <pthread.h>
#include "AbstractReadLock.h"
#include "ILock.h"

class PThreadReadLockImpl : public AbstractReadLock {
public:
    PThreadReadLockImpl();
    PThreadReadLockImpl(pthread_cond_t* pCondVar);
    virtual ~PThreadReadLockImpl();
    
protected:
    //@Override
    virtual void wait();
    
    //@Override
    virtual void signal();
    
private:
    pthread_cond_t* m_pCondVar;
};

#endif /* defined(__MyReadWriteLock__PThreadReadLockImpl__) */
