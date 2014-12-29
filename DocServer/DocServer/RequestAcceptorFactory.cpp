//
//  RequestAcceptorFactory.cpp
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestAcceptorFactory.h"
#include "RequestAcceptorBoostImpl.h"
#include "RequestProcessorFactory.h"
#include "RequestExecutorFactorySimpleImpl.h"
#include "RequestFromSocketFactoryNullImpl.h"
#include "RequestFromSocketFactoryNormalImpl.h"

#if INORMAL_PTR==1
IRequestAcceptorPtr RequestAcceptorFactory::createRequestAcceptor(int portNumber) {
    IRequestAcceptorPtr requestAcceptorPtr = NULL;
    
    IRequestProcessorPtr requestProcessorPtr = RequestProcessorFactory::createRequestProcessor();
    requestProcessorPtr->start();
    
    IRequestExecutorFactoryPtr requestExecutorFactory = new RequestExecutorFactorySimpleImpl();
    
    IRequestFromSocketFactoryPtr requestFromSocketFactory = new RequestFromSocketFactoryNormalImpl();
    
    requestAcceptorPtr = new RequestAcceptorBoostImpl(requestProcessorPtr, requestExecutorFactory, requestFromSocketFactory, portNumber);
    return requestAcceptorPtr;
}
#endif