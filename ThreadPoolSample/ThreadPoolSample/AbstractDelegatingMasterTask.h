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
    AbstractDelegatingMasterTask(ResultWaitDelegatePtr resultWaitDelegatePtr);
    virtual ~AbstractDelegatingMasterTask();
    
    //@Override
    virtual void execute();
    
    virtual void prepare() = 0;
    virtual void collectResults() = 0;
    
protected:
    ResultWaitDelegatePtr m_resultWaitDelegatePtr;
    ResultStore& m_resultStoreRef;
};

#endif /* defined(__ThreadPoolSample__AbstractDelegatingMasterTask__) */
