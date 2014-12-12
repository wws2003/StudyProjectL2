//
//  MyLock.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__MyLock__
#define __MyReadWriteLock__MyLock__

#include <iostream>
#include "LockException.h"

class ILock {
public:
    ILock(){};
    virtual ~ILock(){};
    
    virtual void lock() throw(LockException) = 0;
    virtual void trylock() throw(LockException) = 0;
    virtual void unlock()  throw(LockException) = 0;
};

#endif /* defined(__MyReadWriteLock__MyLock__) */
