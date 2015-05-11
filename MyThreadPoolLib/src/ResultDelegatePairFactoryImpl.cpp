//
//  ResultDelegatePairFactoryImpl.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ResultDelegatePairFactoryImpl.h"
#include "ResultSignalDelegate.h"
#include "ResultWaitDelegate.h"
#include "PCondVar.h"
#include "PMutex.h"

IResultDelegatePtrPair ResultDelegatePairFactoryImpl::getResultDelegatePtrPair() {
    IResultDelegatePtrPair pair;
    MutexPtr mutexPtr = new PMutex();
    CondVarPtr condVarPtr = new PCondVar();
    pair.first = new ResultWaitDelegate(mutexPtr, condVarPtr);
    pair.second = new ResultSignalDelegate(mutexPtr, condVarPtr);
    return pair;
}