//
//  IRequestProcessor.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef __DocServer__IRequestProcessor__
#define __DocServer__IRequestProcessor__

#include <iostream>
#include "IRequestExecutorQueue.h"
#include "IRequestExecutor.h"
#include "IRunable.h"
#include "PointerDef.h"

class IRequestProcessor : public IRunable {
public:
    enum RequestProcessorOperationErr {
        ERR_NONE = 0,
        ERR_ADD_JOB_FAILED
    };
    
    IRequestProcessor(IRequestExecutorQueuePtr requestExecutorQueuePtr);
    virtual ~IRequestProcessor(){};
    
    //@Override
    virtual int start() = 0;
    
    //@Override
    void run();
    
    RequestProcessorOperationErr addJob(IRequestExecutorPtr executorPtr);
    
protected:
    virtual RequestProcessorOperationErr queueErr2ProcessorErr(IRequestExecutorQueue::RequestExecutorQueueOperationErr) = 0;
    IRequestExecutorQueuePtr m_pRequestExecutorQueue;
};

#endif /* defined(__DocServer__IRequestProcessor__) */
