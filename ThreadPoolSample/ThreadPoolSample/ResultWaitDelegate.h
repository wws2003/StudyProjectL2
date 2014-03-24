//
//  ResultWaitDelegate.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__ResultWaitDelegate__
#define __ThreadPoolSample__ResultWaitDelegate__

#include <iostream>
#include "ITask.h"
#include "IMutex.h"
#include "ICondVar.h"
#include <vector>

class ResultWaitDelegate {
public:
    ResultWaitDelegate(ResultStore& resultStoreRef, const unsigned int numberOfJobTodo, IMutexPtr jobMutexPtr, ICondVarPtr jobCondPtr);
    virtual ~ResultWaitDelegate();
    
    virtual void waitForResult();
    virtual ResultStore& getResultStoreRef();
    
private:
    ResultStore& m_resultStoreRef;
    const unsigned int m_numberOfJobTodo;
    IMutexPtr m_jobMutexPtr;
    ICondVarPtr m_jobCondPtr;
};

#endif /* defined(__ThreadPoolSample__ResultWaitDelegate__) */
