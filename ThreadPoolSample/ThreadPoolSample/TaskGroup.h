//
//  AbstractTaskGroup.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__AbstractTaskGroup__
#define __ThreadPoolSample__AbstractTaskGroup__

#include <iostream>
#include <vector>
#include "TypeDefs.h"

class TaskGroup {
public:
    TaskGroup(AbstractThreadPoolPtr threadPoolPtr, AbstractMasterTaskPtr masterTaskPtr, std::vector<AbstractChildTaskPtr> childTaskPtrs);
    
    virtual ~TaskGroup();
    virtual void execute();
protected:
    AbstractThreadPoolPtr m_threadPoolPtr;
    AbstractMasterTaskPtr m_masterTaskPtr;
    std::vector<AbstractChildTaskPtr> m_childTaskPtrs;
};

#endif /* defined(__ThreadPoolSample__AbstractTaskGroup__) */
