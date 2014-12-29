//
//  RequestExecutorQueueFactory.cpp
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestExecutorQueueFactory.h"
#include "RequestExecutorQueueDequeImpl.h"

#if INORMAL_PTR==1
IRequestExecutorQueuePtr RequestExecutorQueueFactory::createRequestExecutorQueue() {
    return new RequestExecutorQueueDequeImpl();
}
#endif