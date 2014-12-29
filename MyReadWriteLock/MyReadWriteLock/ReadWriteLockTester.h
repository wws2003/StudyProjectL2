//
//  ReadLockTester.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __MyReadWriteLock__ReadLockTester__
#define __MyReadWriteLock__ReadLockTester__

#include <iostream>
#include "AbstractReadLock.h"
#include "common.h"

class ReadWriteLockTester {
public:
    ReadWriteLockTester();
    virtual ~ReadWriteLockTester();
    
    void setReadLockPtr(AbstractReadLockPtr pReadLock);
    void setWriteLockPtr(AbstractWriteLockPtr pWriteLock);
    
    void setValueToTestRW(int valueToTestRead);
    
    int testReadRead();
    
    int testReadWrite();
    
    int testWriteWrite();
    
    void doRead();
    
    void doWrite();
    
    enum TEST_RESULT {
        ERR_NONE,
        ERR_THREAD_CREATE
    };

private:
    int multiThreadTest(void * (*pRoutine)(void*));
    
    int m_valueToTestRead;
    AbstractReadLockPtr m_pReadLock;
    AbstractWriteLockPtr m_pWriteLock;
};

#endif /* defined(__MyReadWriteLock__ReadLockTester__) */
