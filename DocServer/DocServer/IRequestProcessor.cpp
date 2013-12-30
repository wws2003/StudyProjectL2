//
//  IRequestProcessor.cpp
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include "IRequestProcessor.h"

IRequestProcessor::IRequestProcessor(IRequestExecutorQueuePtr requestExecutorQueuePtr):m_pRequestExecutorQueue(requestExecutorQueuePtr) {
}

void IRequestProcessor::run() {
    while (1) {
        if(!m_pRequestExecutorQueue->isEmpty()) {
            IRequestExecutorPtr executor = m_pRequestExecutorQueue->front();
            if (executor != NULL) {
                executor->executeRequest();
            }
            m_pRequestExecutorQueue->popFront();
        }
    }
}

IRequestProcessor::RequestProcessorOperationErr IRequestProcessor::addJob(IRequestExecutorPtr executorPtr) {
    IRequestExecutorQueue::RequestExecutorQueueOperationErr queueErr = m_pRequestExecutorQueue->pushToQueue(executorPtr);
    return queueErr2ProcessorErr(queueErr);
}