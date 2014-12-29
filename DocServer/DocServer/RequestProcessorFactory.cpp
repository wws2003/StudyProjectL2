//
//  RequestProcessorFactory.cpp
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestProcessorFactory.h"
#include "RequestProcessorSimpleImpl.h"
#include "RequestExecutorQueueFactory.h"

#if INORMAL_PTR==1
IRequestProcessorPtr RequestProcessorFactory::createRequestProcessor() {
    IRequestExecutorQueuePtr requestExecutorQueuePtr = RequestExecutorQueueFactory::createRequestExecutorQueue();
    IRequestProcessorPtr requestProcessorPtr = new RequestProcessorSimpleImpl(requestExecutorQueuePtr);
    return requestProcessorPtr;
}
#endif