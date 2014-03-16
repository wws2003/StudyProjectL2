//
//  SimpleChildTask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__SimpleChildTask__
#define __ThreadPoolSample__SimpleChildTask__

#include <iostream>
#include "AbstractChildTask.h"

class SimpleChildTask : public AbstractChildTask {
public:
    SimpleChildTask(ResultStore& resultStoreRef, ResultPtr resultPtr, const unsigned int numberOfJobTodo, IMutexPtr jobMutexPtr, ICondVarPtr condMutexPtr, int inputNumber);
    
    virtual ~SimpleChildTask();
    
    //@Override
    virtual void mainExecute();
    
private:
    int m_inputNumber;
};


#endif /* defined(__ThreadPoolSample__SimpleChildTask__) */
