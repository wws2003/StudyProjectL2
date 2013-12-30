//
//  IResponseProcessor.cpp
//  DocServer
//
//  Created by wws2003 on 12/31/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include "IResponseProcessor.h"

IResponseProcessor::IResponseProcessor(IResponseSenderQueuePtr responseSenderQueuePtr) : m_pResponseSenderQueue(responseSenderQueuePtr){
    
}

//@Override
void IResponseProcessor::run() {
    while (1) {
        if (!m_pResponseSenderQueue->isEmpty()) {
            IResponseSenderPtr nextResponseSenderPtr = m_pResponseSenderQueue->front();
            if (nextResponseSenderPtr != NULL) {
                nextResponseSenderPtr->sendResponse();
            }
            m_pResponseSenderQueue->popFront();
        }
    }
}

IResponseProcessor::ResponseProcessorOperationErr IResponseProcessor::addJob(IResponseSenderPtr responseSenderPtr) {
    IResponseSenderQueue::ResponseSenderQueueOperationErr err = m_pResponseSenderQueue->pushResponseSender(responseSenderPtr);
    return queueErr2ProcessorErr(err);
}