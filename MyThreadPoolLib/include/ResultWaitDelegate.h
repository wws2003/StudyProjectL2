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
#include "IResultWaitDelegate.h"
#include <vector>

class ResultWaitDelegate : public IResultWaitDelegate{
public:
    ResultWaitDelegate(IMutexPtr jobMutexPtr, ICondVarPtr jobCondPtr);
    virtual ~ResultWaitDelegate();
    
    //@Override
    virtual void waitForResults(const ResultStore& resultStoreRef, const unsigned int numberOfJobTodo);
    
private:
    IMutexPtr m_jobMutexPtr;
    ICondVarPtr m_jobCondPtr;
};

#endif /* defined(__ThreadPoolSample__ResultWaitDelegate__) */
