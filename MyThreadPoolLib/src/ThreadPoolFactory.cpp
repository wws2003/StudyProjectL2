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
#include "IPThreadConfigurator.h"
#include "RoundRobinPThreadConfigurator.h"

AbstractThreadPoolPtr ThreadPoolFactory::getThreadPoolPtr(unsigned int numberOfThread) {
    MutexPtr mutexPtr = new PMutex();
    CondVarPtr condVarPtr = new PCondVar();

    //TODO Instantiage pThreadConfigurator
    PThreadConfiguratorPtr pThreadConfigurator = new RoundRobinPThreadConfigurator();

    AbstractThreadPoolPtr threadPoolPtr = new PThreadPool(mutexPtr, condVarPtr, numberOfThread, pThreadConfigurator);
    return threadPoolPtr;
}
