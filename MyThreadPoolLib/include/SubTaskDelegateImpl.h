//
//  SubTaskDelegateImpl.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/25/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__SubTaskDelegateImpl__
#define __ThreadPoolSample__SubTaskDelegateImpl__

#include <iostream>
#include "ISubTaskDelegate.h"
#include "TypeDefs.h"

class SubTaskDelegateImpl : public ISubTaskDelegate {
public:
    SubTaskDelegateImpl(AbstractThreadPoolPtr threadPoolPtr);
    virtual ~SubTaskDelegateImpl();
    
    //@Override
    virtual unsigned int executeSubTasks(const AbstractRecursiveTaskPtrs& subTaskPtrs);
    
protected:
    AbstractThreadPoolPtr m_threadPoolPtr;
};

#endif /* defined(__ThreadPoolSample__SubTaskDelegateImpl__) */
