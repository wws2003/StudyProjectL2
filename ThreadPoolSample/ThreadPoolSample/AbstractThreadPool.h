//
//  AbstractThreadPool.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__AbstractThreadPool__
#define __ThreadPoolSample__AbstractThreadPool__

#include <iostream>
#include <deque>
#include "TypeDefs.h"

class AbstractThreadPool {
public:
    AbstractThreadPool(IMutexPtr mutexPtr, ICondVarPtr condVarPtr, int numberOfThreads);
    virtual ~AbstractThreadPool();
    
    virtual ThreadPoolErrorCode initAndStart(bool wait = true) = 0;
    virtual ThreadPoolErrorCode destroy() = 0;
    
    virtual void addTask(ITask* taskPtr);
    virtual unsigned int addTaskBatch(const ITaskPtrs& taskPtrs);
    virtual void oneThreadJob();
    
protected:
    int m_numberOfThreads;
    IMutexPtr m_taskMutexPtr;
    ICondVarPtr m_condVarPtr;
    volatile bool m_isStopped;
    
    std::deque<ITaskPtr> m_taskPtrQueue;
};


#endif /* defined(__ThreadPoolSample__AbstractThreadPool__) */
