//
//  LockException.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/12/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__LockException__
#define __MyReadWriteLock__LockException__

#include <iostream>

class LockException : public std::exception {
public:
    enum LOCK_EXCEPTION_TYPE {
        LOCK_EXCEPTION,
        TRYLOCK_EXCEPTION,
        UNLOCK_EXCEPTION
    };
    
    LockException(int exceptionType = LOCK_EXCEPTION);
    virtual ~LockException();

    //@Override
    virtual const char* what() const _NOEXCEPT;
    
private:
    int m_exceptionType;
};

#endif /* defined(__MyReadWriteLock__LockException__) */
