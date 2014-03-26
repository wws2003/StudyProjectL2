//
//  SumMasterTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "SumMasterTask.h"
#include <cstdio>

SumMasterTask::SumMasterTask(IResultWaitDelegatePtr resultWaitDelegatePtr, ResultStore& resultStoreRef, unsigned int numberOfSlaveTasks) : AbstractDelegatingMasterTask(resultWaitDelegatePtr, resultStoreRef, numberOfSlaveTasks)  {
    
}

SumMasterTask::~SumMasterTask() {
    for (unsigned int i = 0; i < m_resultStoreRef.size(); i++) {
        delete ((int*)m_resultStoreRef[i]);
    }
}

void SumMasterTask::prepare() {
    
}

void SumMasterTask::collectResults() {
    int sum = 0;
    for (unsigned int i = 0; i < m_resultStoreRef.size(); i++) {
        int r = *(int*)m_resultStoreRef[i];
        sum += r;
    }
    printf("Sum = %d\n", sum);
}