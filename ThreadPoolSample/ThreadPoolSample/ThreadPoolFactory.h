//
//  ThreadPoolFactory.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__ThreadPoolFactory__
#define __ThreadPoolSample__ThreadPoolFactory__

#include <iostream>
#include "TypeDefs.h"

class ThreadPoolFactory {
public:
    static AbstractThreadPoolPtr getThreadPoolPtr(unsigned int numberOfThread);
};

#endif /* defined(__ThreadPoolSample__ThreadPoolFactory__) */
