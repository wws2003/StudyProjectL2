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
    AbstractThreadPool(MutexPtr mutexPtr, CondVarPtr condVarPtr, int numberOfThreads);
    virtual ~AbstractThreadPool();
    
    virtual TaskExecutorErrorCode initAndStart(bool wait = true) = 0;
    virtual TaskExecutorErrorCode destroy();
    
    virtual void addTask(TaskPtr taskPtr);
    virtual unsigned int addTaskBatch(const TaskPtrs& taskPtrs);
    virtual void waitAllTaskComplete();
    
    //Each thread would run this method as main loop
    virtual void oneThreadJob();
    
protected:
    virtual void joinAllThreads() = 0;

    //Get the current thread id. This value is platform-dependent
    virtual unsigned long currentThreadId() = 0;
    
    int m_numberOfThreads;
    MutexPtr m_taskMutexPtr;
    CondVarPtr m_condVarPtr;
    volatile bool m_isStopped;
    
    std::deque<TaskPtr> m_taskPtrQueue;
    
private:
    virtual void sleep(long microsecond) = 0;
    int m_numberOfIncompletedTask;
};


#endif /* defined(__ThreadPoolSample__AbstractThreadPool__) */
