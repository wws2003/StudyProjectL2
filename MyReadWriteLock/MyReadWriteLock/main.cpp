//
//  main.cpp
//  MyReadWriteLock
//
//  Created by wws2003 on 12/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "ReadLockAssembler.h"
#include "ReadWriteLockTester.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    srand((unsigned int)time(NULL));
    
    ReadLockAssembler lockAssembler;
    AbstractReadLockPtr pReadLock;
    AbstractWriteLockPtr pWriteLock;
    lockAssembler.getReadWriteLockPair(pReadLock, pWriteLock);
    
    ReadWriteLockTester tester;
    tester.setReadLockPtr(pReadLock);
    tester.setWriteLockPtr(pWriteLock);
    
    for (int i = 0; i < 10; i++) {
        std::cout << "Test result " << tester.testReadWrite() << std::endl;
    }

    return 0;
}

