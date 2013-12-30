//
//  RequestPostExecutorSendResponse.h
//  DocServer
//
//  Created by wws2003 on 12/31/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestPostExecutorSendResponse__
#define __DocServer__RequestPostExecutorSendResponse__

#include <iostream>
#include "Response.h"
#include "IResponseProcessor.h"
#include "IResponseSenderFactory.h"
#include "IRequestPostExecutor.h"

class RequestPostExecutorSendResponse : public IRequestPostExecutor{
public:
    RequestPostExecutorSendResponse(IResponseProcessorPtr responseProcessorPtr, IResponseSenderFactoryPtr responseSenderFactoryPtr);
    virtual ~RequestPostExecutorSendResponse(){};
    
    //@Override
    virtual bool onRequestExecutionEnd(ResponsePtr responsePtr);
    
private:
    IResponseProcessorPtr m_pResponseProcessor;
    IResponseSenderFactoryPtr m_pResponseSenderFactory;
};

#endif /* defined(__DocServer__RequestPostExecutorSendResponse__) */
