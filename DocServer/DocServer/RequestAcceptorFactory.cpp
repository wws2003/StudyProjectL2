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

#if INORMALPTR==1
IRequestAcceptorPtr RequestAcceptorFactory::createRequestAcceptor(int portNumber) {
    IRequestAcceptorPtr requestAcceptorPtr = NULL;
    IRequestProcessorPtr requestProcessorPtr = RequestProcessorFactory::createRequestProcessor();
    IRequestExecutorFactoryPtr requestExecutorFactory = new RequestExecutorFactorySimpleImpl();
    requestAcceptorPtr = new RequestAcceptorBoostImpl(requestProcessorPtr, requestExecutorFactory, portNumber);
    return requestAcceptorPtr;
}
#endif