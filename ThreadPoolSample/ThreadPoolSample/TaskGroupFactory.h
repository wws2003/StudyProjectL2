//
//  TaskGroupFactory.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__TaskGroupFactory__
#define __ThreadPoolSample__TaskGroupFactory__

#include <iostream>
#include "TypeDefs.h"

class TaskGroupFactory {
public:
    TaskGroupFactory(unsigned int numberOfThread, unsigned int numberOfTask = 0);
    virtual ~TaskGroupFactory();
    
    TaskGroupPtr getSampleTaskGroupPtr();
    
private:
    AbstractThreadPoolPtr m_threadPoolPtr;
    ResultStore m_resultStore;
    int* m_resultPtrs;
    IMutexPtr m_jobMutexPtr;
    ICondVarPtr m_jobCondPtr;
    std::vector<AbstractDelegatingSlaveTaskPtr> m_childTaskPtrs;
    AbstractDelegatingMasterTaskPtr m_masterTaskPtr;
};

#endif /* defined(__ThreadPoolSample__TaskGroupFactory__) */
