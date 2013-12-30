//
//  IRequestExecutorQueue.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef __DocServer__IRequestExecutorQueue__
#define __DocServer__IRequestExecutorQueue__

#include <iostream>
#include "IRequestExecutor.h"

class IRequestExecutorQueue {
public:
    enum RequestExecutorQueueOperationErr {
            ERR_NONE = 0,
    };
    
    virtual RequestExecutorQueueOperationErr pushToQueue(IRequestExecutorPtr executorPtr) = 0;
    virtual IRequestExecutorPtr front() = 0;
    virtual RequestExecutorQueueOperationErr popFront() = 0;
    virtual bool isEmpty() = 0;
};

#if INORMAL_PTR == 1
typedef IRequestExecutorQueue* IRequestExecutorQueuePtr;
#endif

#endif /* defined(__DocServer__IRequestExecutorQueue__) */
