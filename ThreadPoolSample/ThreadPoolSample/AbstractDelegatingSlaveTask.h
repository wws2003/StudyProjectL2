//
//  AbstractDelegatingSlaveTask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__AbstractDelegatingSlaveTask__
#define __ThreadPoolSample__AbstractDelegatingSlaveTask__

#include <iostream>
#include "TypeDefs.h"
#include "ITask.h"

class AbstractDelegatingSlaveTask : public ITask{
public:
    AbstractDelegatingSlaveTask(IResultSignalDelegatePtr resultSignalDelegatePtr, ResultStore& resultStoreRef);
    virtual ~AbstractDelegatingSlaveTask();
    
    //@Override
    virtual void execute();
    
protected:
    virtual ResultPtr mainExecute() = 0;
    virtual void reportResult(ResultPtr resultPtr);
    
    IResultSignalDelegatePtr m_resultSignalDelegatePtr;
    ResultStore& m_resultStoreRef;
};

#endif /* defined(__ThreadPoolSample__AbstractDelegatingSlaveTask__) */
