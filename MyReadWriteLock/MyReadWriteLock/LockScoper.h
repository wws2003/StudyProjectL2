//
//  LockScoper.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__LockScoper__
#define __MyReadWriteLock__LockScoper__

#include <iostream>
#include "common.h"
#include "ILock.h"

class LockScoper {
public:
    LockScoper(PLock pLock);
    virtual ~LockScoper();
    
    void lock();
    
private:
    bool m_isLocking;
    PLock m_pLock;
};

#endif /* defined(__MyReadWriteLock__LockScoper__) */
