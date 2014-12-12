//
//  LockException.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/12/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "LockException.h"

LockException::LockException(int exceptionType) : std::exception(), m_exceptionType(exceptionType) {
    
}

LockException::~LockException() {
    
}

//@Override
const char* LockException::what() const _NOEXCEPT {
    return "Lock exception"; //TODO Make use of m_exceptionType
}