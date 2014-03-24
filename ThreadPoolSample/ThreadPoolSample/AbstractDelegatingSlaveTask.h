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
    AbstractDelegatingSlaveTask(ResultSignalDelegatePtr resultSignalDelegatePtr);
    virtual ~AbstractDelegatingSlaveTask();
    
    //@Override
    virtual void execute();
    
protected:
    virtual void mainExecute(ResultPtr resultPtr) = 0;
    
    ResultSignalDelegatePtr m_resultSignalDelegatePtr;
};

#endif /* defined(__ThreadPoolSample__AbstractDelegatingSlaveTask__) */
