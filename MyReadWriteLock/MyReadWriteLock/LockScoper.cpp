//
//  LockScoper.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "LockScoper.h"

LockScoper::LockScoper(PLock pLock) :m_pLock(pLock), m_isLocking(false) {
}

LockScoper::~LockScoper() {
    if (m_isLocking) {
        m_pLock->unlock();
    }
}

void LockScoper::lock() {
    m_isLocking = true;
    try {
        m_pLock->lock();
    } catch (LockException& le) {
        m_isLocking = false;
        throw le;
    }
    
}