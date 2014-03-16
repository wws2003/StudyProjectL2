//
//  AbstractChildTask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__AbstractChildTask__
#define __ThreadPoolSample__AbstractChildTask__

#include <iostream>
#include "ITask.h"
#include "IMutex.h"
#include "ICondVar.h"
#include <vector>

class AbstractChildTask : public ITask{
public:
    AbstractChildTask(ResultStore& resultStoreRef, ResultPtr resultPtr, const unsigned int numberOfJobTodo, IMutexPtr jobMutexPtr, ICondVarPtr condMutexPtr);
    virtual ~AbstractChildTask();
    
    //@Override
    virtual void execute();
    
protected:
    virtual void mainExecute() = 0;
    
    ResultStore& m_resultStoreRef;
    ResultPtr m_resultPtr;
    const unsigned int m_numberOfJobTodo;
    IMutexPtr m_jobMutexPtr;
    ICondVarPtr m_condMutexPtr;
};

#endif /* defined(__ThreadPoolSample__AbstractChildTask__) */
