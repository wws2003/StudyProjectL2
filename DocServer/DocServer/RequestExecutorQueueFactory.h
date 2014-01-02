//
//  RequestExecutorQueueFactory.h
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestExecutorQueueFactory__
#define __DocServer__RequestExecutorQueueFactory__

#include <iostream>
#include "IRequestExecutorQueue.h"

class RequestExecutorQueueFactory {
public:
    static IRequestExecutorQueuePtr createRequestExecutorQueue();
};

#endif /* defined(__DocServer__RequestExecutorQueueFactory__) */
