//
//  RequestProcessorSimpleImpl.h
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestProcessorSimpleImpl__
#define __DocServer__RequestProcessorSimpleImpl__

#include <iostream>
#include "IRequestProcessor.h"

class RequestProcessorSimpleImpl : public IRequestProcessor{
public:
    RequestProcessorSimpleImpl(IRequestExecutorQueuePtr requestExecutorQueuePtr);
    virtual ~RequestProcessorSimpleImpl(){};
    
    //@Override
    virtual int start();
    
protected:
    virtual RequestProcessorOperationErr queueErr2ProcessorErr(IRequestExecutorQueue::RequestExecutorQueueOperationErr);
};

#endif /* defined(__DocServer__RequestProcessorSimpleImpl__) */
