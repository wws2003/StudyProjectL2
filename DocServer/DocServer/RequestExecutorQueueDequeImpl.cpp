//
//  RequestQueueDequeImpl.cpp
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestExecutorQueueDequeImpl.h"

IRequestExecutorQueue::RequestExecutorQueueOperationErr RequestExecutorQueueDequeImpl::pushToQueue(IRequestExecutorPtr executorPtr) {
    m_RequestExecutorQueue.push_back(executorPtr);
    return ERR_NONE;
}

IRequestExecutorPtr RequestExecutorQueueDequeImpl::front() {
    return m_RequestExecutorQueue.front();
}

IRequestExecutorQueue::RequestExecutorQueueOperationErr RequestExecutorQueueDequeImpl::popFront() {
    m_RequestExecutorQueue.pop_front();
    return ERR_NONE;
}

bool RequestExecutorQueueDequeImpl::isEmpty() {
    return m_RequestExecutorQueue.empty();
}