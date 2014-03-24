//
//  SimpleChildTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "SimpleChildTask.h"

SimpleChildTask::SimpleChildTask(ResultSignalDelegatePtr resultSignalDelegatePtr, unsigned int inputNumber) : AbstractDelegatingSlaveTask(resultSignalDelegatePtr), m_inputNumber(inputNumber) {
    
}

SimpleChildTask::~SimpleChildTask() {
    
}

void SimpleChildTask::mainExecute(ResultPtr resultPtr) {
    *(int*)resultPtr = m_inputNumber * m_inputNumber;
}