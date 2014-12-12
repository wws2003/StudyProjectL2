//
//  PThreadWriteLockImpl.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__PThreadWriteLockImpl__
#define __MyReadWriteLock__PThreadWriteLockImpl__

#include <iostream>
#include <pthread.h>
#include "common.h"
#include "AbstractWriteLock.h"

class PThreadWriteLockImpl : public AbstractWriteLock {
public:
    PThreadWriteLockImpl();
    PThreadWriteLockImpl(pthread_cond_t* pCondVar);
    virtual ~PThreadWriteLockImpl();
    
protected:
    //@Override
    virtual void wait();
    
    //@Override
    virtual void signal();
    
private:
    pthread_cond_t* m_pCondVar;
    
};

#endif /* defined(__MyReadWriteLock__PThreadWriteLockImpl__) */
