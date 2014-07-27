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
#include "IResultSignalDelegate.h"
#include <vector>

class ResultSignalDelegate : public IResultSignalDelegate{
public:
    ResultSignalDelegate(IMutexPtr jobMutexPtr, ICondVarPtr condMutexPtr);
    virtual ~ResultSignalDelegate();
    
    //@Override
    virtual void reportResult(ResultStore& resultStoreRef, const ResultPtr resultPtr);
    
private:
    IMutexPtr m_jobMutexPtr;
    ICondVarPtr m_condMutexPtr;
};

#endif /* defined(__ThreadPoolSample__ResultSignalDelegate__) */
