//
//  ReadLock.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__ReadLock__
#define __MyReadWriteLock__ReadLock__

#include <iostream>
#include "common.h"
#include "ILock.h"

class AbstractReadLock : public ILock {
public:
    AbstractReadLock(){};
    virtual ~AbstractReadLock(){};
    
    //@Override
    virtual void lock() throw(LockException);
    
    //@Override
    virtual void trylock() throw(LockException);
    
    //@Override
    virtual void unlock() throw(LockException);
    
    void setRWCriticalPtr(RWCriticalPtr pRWCritical);
    
protected:
    virtual void wait() = 0;
    virtual void signal() = 0;
    
    RWCriticalPtr m_pRWCritical;
};

#endif /* defined(__MyReadWriteLock__ReadLock__) */
