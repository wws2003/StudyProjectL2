//
//  main.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <iostream>
#include "TaskGroupFactory.h"
#include "TaskGroup.h"
#include <unistd.h>

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    TaskGroupFactory* taskGroupFactory = new TaskGroupFactory(1, 12);
    TaskGroupPtr taskGroupPtr = taskGroupFactory->getSampleTaskGroupPtr();
    taskGroupPtr->execute();
    //sleep(10);
    delete taskGroupPtr;
    delete taskGroupFactory;
    return 0;
}

