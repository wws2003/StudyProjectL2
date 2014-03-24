//
//  SumMasterTask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__SumMasterTask__
#define __ThreadPoolSample__SumMasterTask__

#include <iostream>
#include "AbstractDelegatingMasterTask.h"

class SumMasterTask : public AbstractDelegatingMasterTask {
public:
    SumMasterTask(ResultWaitDelegatePtr resultWaitDelegatePtr);
    virtual ~SumMasterTask();
    
    //@Override
    virtual void prepare();
    //@Override
    virtual void collectResults();
};

#endif /* defined(__ThreadPoolSample__SumMasterTask__) */
