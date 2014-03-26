//
//  SimpleChildTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "SimpleChildTask.h"

SimpleChildTask::SimpleChildTask(IResultSignalDelegatePtr resultSignalDelegatePtr, ResultStore& resultStoreRef, unsigned int inputNumber) : AbstractDelegatingSlaveTask(resultSignalDelegatePtr, resultStoreRef), m_inputNumber(inputNumber) {
    
}

SimpleChildTask::~SimpleChildTask() {
    
}

ResultPtr SimpleChildTask::mainExecute() {
    int* resultPtr = new int();
    *resultPtr = m_inputNumber * m_inputNumber;
    return resultPtr;
}