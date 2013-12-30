//
//  IResponseProcessor.h
//  DocServer
//
//  Created by wws2003 on 12/31/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef __DocServer__IResponseProcessor__
#define __DocServer__IResponseProcessor__

#include "IResponseSenderQueue.h"
#include "IRunable.h"
#include "IResponseSender.h"

class IResponseProcessor : public IRunable{
public:
    enum ResponseProcessorOperationErr{
        ERR_NONE = 0,
    };
    IResponseProcessor(IResponseSenderQueuePtr reponseSenderQueuePtr);
    virtual ~IResponseProcessor(){};
    
    //@Override
    void run();
    
    ResponseProcessorOperationErr addJob(IResponseSenderPtr responseSenderPtr);
    
protected:
    virtual ResponseProcessorOperationErr queueErr2ProcessorErr(IResponseSenderQueue::ResponseSenderQueueOperationErr err) = 0;
    
    IResponseSenderQueuePtr m_pResponseSenderQueue;
};

#if INORMAL_PTR==1
    typedef IResponseProcessor* IResponseProcessorPtr;
#endif

#endif /* defined(__DocServer__IResponseProcessor__) */
