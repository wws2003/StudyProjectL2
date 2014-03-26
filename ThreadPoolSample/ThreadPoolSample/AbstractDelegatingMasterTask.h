//
//  AbstractDelegatingMasterTask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__AbstractDelegatingMasterTask__
#define __ThreadPoolSample__AbstractDelegatingMasterTask__

#include <iostream>
#include "TypeDefs.h"
#include "ITask.h"

class AbstractDelegatingMasterTask : public ITask {
public:
    AbstractDelegatingMasterTask(IResultWaitDelegatePtr resultWaitDelegatePtr);
    virtual ~AbstractDelegatingMasterTask();
    
    //@Override
    virtual void execute();

    virtual void addSlaveTaskPtr(AbstractDelegatingSlaveTaskPtr slaveTaskPtr);
    
protected:
    virtual void prepare() = 0;
    virtual void waitForResults();
    virtual void collectResults() = 0;
    
    AbstractDelegatingSlaveTaskPtrs m_slaveTaskPtrs;
    IResultWaitDelegatePtr m_resultWaitDelegatePtr;
    ResultStore m_resultStoreRef;
};

#endif /* defined(__ThreadPoolSample__AbstractDelegatingMasterTask__) */
