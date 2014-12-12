//
//  ReadLockAssembler.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__ReadLockAssembler__
#define __MyReadWriteLock__ReadLockAssembler__

#include <iostream>
#include <vector>
#include "common.h"
#include "PThreadReadLockImpl.h"
#include "PThreadMutexLockImpl.h"
#include "PThreadWriteLockImpl.h"
#include "concrete_typedef.h"

class ReadLockAssembler {
public:
    ReadLockAssembler();
    virtual ~ReadLockAssembler();
    
    virtual AbstractReadLockPtr getAbstractReadLockPtr();
    virtual void getReadWriteLockPair(AbstractReadLockPtr& pReadLock, AbstractWriteLockPtr& pWriteLock);
    
    virtual void cleanUp();
    
private:
    std::vector<RWCriticalPtr> m_pRWCriticals;
    std::vector<PThreadReadLockImplPtr> m_pReadLockPthreadImpls;
    std::vector<PThreadMutexLockImplPtr> m_pLockPthreadMutexImpls;
    std::vector<PThreadWriteLockImplPtr> m_pWriteLockPThreadImpls;
    std::vector<pthread_cond_t_ptr> m_pCondVars;
};


#endif /* defined(__MyReadWriteLock__ReadLockAssembler__) */
