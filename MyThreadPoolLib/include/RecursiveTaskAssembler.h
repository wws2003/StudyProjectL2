//
//  RecursiveTaskAssembler.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__RecursiveTaskAssembler__
#define __ThreadPoolSample__RecursiveTaskAssembler__

#include <iostream>
#include "TypeDefs.h"

class RecursiveTaskAssembler {
public:
    RecursiveTaskAssembler(unsigned int numberOfThread);
    virtual ~RecursiveTaskAssembler();
    
    virtual void assembleRecursiveTask(AbstractRecursiveTaskPtr recursiveTaskPtr);
    
private:
    IResultDelegatePairFactoryPtr m_resultDelegatePairFactoryPtr;
    AbstractThreadPoolPtr m_threadPoolPtr;
    ISubTaskDelegatePtr m_subTaskDelegatePtr;
    
};

#endif /* defined(__ThreadPoolSample__RecursiveTaskAssembler__) */
