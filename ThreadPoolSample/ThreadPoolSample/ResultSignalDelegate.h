//
//  ResultSignalDelegate.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__ResultSignalDelegate__
#define __ThreadPoolSample__ResultSignalDelegate__

#include <iostream>
#include "ITask.h"
#include "IMutex.h"
#include "ICondVar.h"
#include <vector>

class ResultSignalDelegate {
public:
    ResultSignalDelegate(ResultStore& resultStoreRef, ResultPtr resultPtr, const unsigned int numberOfJobTodo, IMutexPtr jobMutexPtr, ICondVarPtr condMutexPtr);
    virtual ~ResultSignalDelegate();
    
    virtual ResultPtr getResultPtr();
    virtual void reportResult();
    
private:
    ResultStore& m_resultStoreRef;
    ResultPtr m_resultPtr;
    const unsigned int m_numberOfJobTodo;
    IMutexPtr m_jobMutexPtr;
    ICondVarPtr m_condMutexPtr;
};

#endif /* defined(__ThreadPoolSample__ResultSignalDelegate__) */
