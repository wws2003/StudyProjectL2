//
//  RequestQueueDequeImpl.h
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestQueueDequeImpl__
#define __DocServer__RequestQueueDequeImpl__

#include <iostream>
#include <deque>

#include "IRequestExecutorQueue.h"

class RequestExecutorQueueDequeImpl : public IRequestExecutorQueue {
public:
    virtual ~RequestExecutorQueueDequeImpl(){};
    
    virtual RequestExecutorQueueOperationErr pushToQueue(IRequestExecutorPtr executorPtr);
    virtual IRequestExecutorPtr front();
    virtual RequestExecutorQueueOperationErr popFront();
    virtual bool isEmpty();
    
private:
    std::deque<IRequestExecutorPtr> m_RequestExecutorQueue;
};




#endif /* defined(__DocServer__RequestQueueDequeImpl__) */
