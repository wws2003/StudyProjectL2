//
//  AbstractRecursiveTask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/22/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__AbstractRecursiveTask__
#define __ThreadPoolSample__AbstractRecursiveTask__

#include <iostream>
#include "ITask.h"
#include "TypeDefs.h"
#include "AbstractDelegatingMasterTask.h"

class AbstractRecursiveTask : public AbstractDelegatingMasterTask{
public:
    AbstractRecursiveTask(ResultWaitDelegatePtr resultWaitPtr, ISubTaskDelegatePtr subTaskDelegatePtr);
    
    virtual ~AbstractRecursiveTask();
    
protected:
    virtual void getSubTaskPtrs(AbstractRecursiveTaskPtrs subTaskPtrs) = 0;
    
    //@Override
    virtual void prepare();
    
    ISubTaskDelegatePtr m_subTaskDelagatePtr;
};

#endif /* defined(__ThreadPoolSample__AbstractRecursiveTask__) */
