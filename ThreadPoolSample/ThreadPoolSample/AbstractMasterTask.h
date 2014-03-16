//
//  AbstractMasterTask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__AbstractMasterTask__
#define __ThreadPoolSample__AbstractMasterTask__

#include <iostream>
#include "TypeDefs.h"
#include "ITask.h"

class AbstractMasterTask : public ITask {
public:
    AbstractMasterTask(ResultStore& resultStoreRef, const unsigned int numberOfJobTodo, IMutexPtr jobMutexPtr, ICondVarPtr jobCondPtr);
    virtual ~AbstractMasterTask();
    
    //@Override
    virtual void execute();
    
    virtual void collectResults() = 0;
    
protected:
    ResultStore& m_resultStoreRef;
    const unsigned int m_numberOfJobTodo;
    IMutexPtr m_jobMutexPtr;
    ICondVarPtr m_jobCondPtr;
};

#endif /* defined(__ThreadPoolSample__AbstractMasterTask__) */
