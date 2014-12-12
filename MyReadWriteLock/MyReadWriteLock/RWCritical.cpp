//
//  RWCritical.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RWCritical.h"

RWCritical::RWCritical() : m_pLock(NULL), m_isWritting(false), m_readSemaphore(0) {
    
}

RWCritical::~RWCritical() {
    
}

void RWCritical::setLockPtr(PLock pLock) {
    m_pLock = pLock;
}

PLock RWCritical::getLockPtr() {
    return m_pLock;
}

void RWCritical::acquireReadSemaphore() {
    m_readSemaphore++;
}

void RWCritical::releaseReadSemaphore() {
    m_readSemaphore--;
}

int RWCritical::getReadSemaphore() {
    return m_readSemaphore;
}

bool RWCritical::isWritting() {
    return m_isWritting;
}

void RWCritical::setWritting(bool isWritting) {
    m_isWritting = isWritting;
}