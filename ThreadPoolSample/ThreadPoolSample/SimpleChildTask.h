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
#include "AbstractDelegatingSlaveTask.h"

class SimpleChildTask : public AbstractDelegatingSlaveTask {
public:
    SimpleChildTask(IResultSignalDelegatePtr resultSignalDelegatePtr, ResultStore& resultStoreRef, unsigned int inputNumber);
    
    virtual ~SimpleChildTask();
    
    //@Override
    virtual ResultPtr mainExecute();
    
private:
    int m_inputNumber;
};


#endif /* defined(__ThreadPoolSample__SimpleChildTask__) */
