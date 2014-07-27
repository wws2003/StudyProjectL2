//
//  PMutex.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PMutex.h"

PMutex::PMutex() {
    pthread_mutex_init(&m_mutex, NULL);
}

PMutex::~PMutex() {
    pthread_mutex_destroy(&m_mutex);
}

void PMutex::lock() {
    pthread_mutex_lock(&m_mutex);
}

void PMutex::unlock() {
    pthread_mutex_unlock(&m_mutex);
}

pthread_mutex_t* PMutex::getMutexPtr() {
    return &m_mutex;
}