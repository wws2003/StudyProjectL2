//
//  RWCritical.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__RWCritical__
#define __MyReadWriteLock__RWCritical__

#include <iostream>
#include "common.h"

class RWCritical {
public:
    RWCritical();
    virtual ~RWCritical();
    
    void setLockPtr(PLock pLock);
    PLock getLockPtr();
    
    void acquireReadSemaphore();
    void releaseReadSemaphore();
    int getReadSemaphore();
    
    bool isWritting();
    void setWritting(bool isWritting = true);
    
private:
    int m_readSemaphore;
    bool m_isWritting;
    
    PLock m_pLock;
};

#endif /* defined(__MyReadWriteLock__RWCritical__) */
