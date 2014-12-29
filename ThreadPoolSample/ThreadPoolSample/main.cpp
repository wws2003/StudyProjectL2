//
//  main.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <iostream>
#include "RecursiveTaskAssembler.h"
#include "QuickSortRecursiveTask.h"
#include <unistd.h>

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    int array[] = {3, 4, 6, 2, 5, 1, 5, 64, 2, 0, 23, 2, -5, 5, 34, 23, 1, 42, 0, 44, 2, 12, 6, 7};
    int size = sizeof(array) / sizeof(int);
    
    QuickSortRecursiveTask* quickSortTask = new QuickSortRecursiveTask(array, size);
    RecursiveTaskAssembler* taskAssembler = new RecursiveTaskAssembler(4);
    taskAssembler->assembleRecursiveTask(quickSortTask);
    
    quickSortTask->execute();
    for (unsigned int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    
    delete taskAssembler;
    delete quickSortTask;
    return 0;
}

