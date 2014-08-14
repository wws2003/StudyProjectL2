//
//  PThreadPool.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__PThreadPool__
#define __ThreadPoolSample__PThreadPool__

#include "TypeDefs.h"
#include "AbstractThreadPool.h"
#include <iostream>
#include <vector>

class PThreadPool : public AbstractThreadPool {
public:
    PThreadPool(IMutexPtr mutexPtr, ICondVarPtr condVarPtr, int numberOfThreads);
    virtual ~PThreadPool();
    
    //@Override
    virtual ThreadPoolErrorCode initAndStart(bool wait = false);
    
private:
    //@Override
    virtual void joinAllThreads();
    
     //@Override
    virtual void sleep(long microsecond);
    
    //@Override
    virtual unsigned long currentThreadId();
    std::vector<pthread_t> m_threads;
    
    struct timespec m_tm1;
};

#endif /* defined(__ThreadPoolSample__PThreadPool__) */
