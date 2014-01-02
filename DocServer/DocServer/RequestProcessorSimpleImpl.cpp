//
//  RequestProcessorSimpleImpl.cpp
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestProcessorSimpleImpl.h"
#include <boost/thread.hpp>

RequestProcessorSimpleImpl::RequestProcessorSimpleImpl(IRequestExecutorQueuePtr requestExecutorQueuePtr) : IRequestProcessor(requestExecutorQueuePtr){
    
}

int RequestProcessorSimpleImpl::start() {
    boost::thread t(boost::bind(&RequestProcessorSimpleImpl::run, this));
    return 0;
}

RequestProcessorSimpleImpl::RequestProcessorOperationErr RequestProcessorSimpleImpl::queueErr2ProcessorErr(IRequestExecutorQueue::RequestExecutorQueueOperationErr queueErr) {
    if (queueErr == IRequestExecutorQueue::ERR_NONE) {
        return ERR_NONE;
    }
    return ERR_ADD_JOB_FAILED;
}

