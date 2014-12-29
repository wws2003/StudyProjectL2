//
//  PCondVar.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PCondVar.h"
#include "PMutex.h"

PCondVar::PCondVar() {
    pthread_cond_init(&m_condVar, NULL);
}

PCondVar::~PCondVar() {
    pthread_cond_destroy(&m_condVar);
}

void PCondVar::wait(IMutexPtr mutexPtr) {
    //temporally casting, consider other solution for this kind of problem
    PMutex* pMutexPtr = dynamic_cast<PMutex*>(mutexPtr);
    pthread_cond_wait(&m_condVar, pMutexPtr->getMutexPtr());
}

CondVarErrorCode PCondVar::signal() {
    if(pthread_cond_signal(&m_condVar) != 0)
        return SIGNAL_ERROR;
    return COND_VAR_ERROR_NONE;
}

CondVarErrorCode PCondVar::broadcast() {
    if(pthread_cond_broadcast(&m_condVar) != 0)
        return BROADCAST_ERROR;
    return COND_VAR_ERROR_NONE;
}
