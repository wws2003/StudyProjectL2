//
//  ThreadPoolFactory.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ThreadPoolFactory.h"
#include "AbstractThreadPool.h"
#include "PThreadPool.h"
#include "PMutex.h"
#include "PCondVar.h"

AbstractThreadPoolPtr ThreadPoolFactory::getThreadPoolPtr(unsigned int numberOfThread) {
    IMutexPtr mutexPtr = new PMutex();
    ICondVarPtr condVarPtr = new PCondVar();
    AbstractThreadPoolPtr threadPoolPtr = new PThreadPool(mutexPtr, condVarPtr, numberOfThread);
    return threadPoolPtr;
}