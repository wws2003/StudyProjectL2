//
//  RequestPostExecutorSendResponse.cpp
//  DocServer
//
//  Created by wws2003 on 12/31/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include "RequestPostExecutorSendResponse.h"

RequestPostExecutorSendResponse::RequestPostExecutorSendResponse(IResponseProcessorPtr responseProcessorPtr, IResponseSenderFactoryPtr responseSenderFactoryPtr) : m_pResponseProcessor(responseProcessorPtr), m_pResponseSenderFactory(responseSenderFactoryPtr){
    
}

bool RequestPostExecutorSendResponse::onRequestExecutionEnd(ResponsePtr responsePtr) {
    IResponseSenderPtr responseSenderPtr = m_pResponseSenderFactory->createResponseSenderPtr(responsePtr);
    if (responseSenderPtr == NULL) {
        return false;
    }
    IResponseProcessor::ResponseProcessorOperationErr err = m_pResponseProcessor->addJob(responseSenderPtr);
    return (err == IResponseProcessor::ResponseProcessorOperationErr::ERR_NONE);
}