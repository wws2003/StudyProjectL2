//
//  SimpleChildTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "SimpleChildTask.h"

SimpleChildTask::SimpleChildTask(ResultStore& resultStoreRef, ResultPtr resultPtr, const unsigned int numberOfJobTodo, IMutexPtr jobMutexPtr, ICondVarPtr condMutexPtr, int inputNumber) : AbstractChildTask(resultStoreRef, resultPtr, numberOfJobTodo, jobMutexPtr, condMutexPtr), m_inputNumber(inputNumber) {
    
}

SimpleChildTask::~SimpleChildTask() {
    
}

void SimpleChildTask::mainExecute() {
    *(int*)m_resultPtr = m_inputNumber * m_inputNumber;
}