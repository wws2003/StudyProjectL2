//
//  IRequestAcceptor.cpp
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include "IRequestAcceptor.h"

IRequestAcceptor::IRequestAcceptor(IRequestProcessorPtr requestProcessorPtr, IRequestExecutorFactoryPtr requestExecutorFactory)
    : m_pRequestProcessor(requestProcessorPtr), m_pRequestExecutorFactory(requestExecutorFactory) {
    
}

bool IRequestAcceptor::onRequest(IRequestPtr newRequest) {
    IRequestExecutorPtr requestExecutorPtr = m_pRequestExecutorFactory->createRequestExecutor(newRequest);
    if (requestExecutorPtr == NULL) {
        return false;
    }
    IRequestProcessor::RequestProcessorOperationErr err = m_pRequestProcessor->addJob(requestExecutorPtr);
    return (err == IRequestProcessor::RequestProcessorOperationErr::ERR_NONE);
}