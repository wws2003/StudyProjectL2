//
//  AbstractWriteLock.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__AbstractWriteLock__
#define __MyReadWriteLock__AbstractWriteLock__

#include <iostream>
#include "common.h"
#include "ILock.h"

class AbstractWriteLock : public ILock {
public:
    AbstractWriteLock(){};
    virtual ~AbstractWriteLock(){};
    
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

#endif /* defined(__MyReadWriteLock__AbstractWriteLock__) */
