//
//  SimpleRecursiveTask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__QuickSortRecursiveTask__
#define __ThreadPoolSample__QuickSortRecursiveTask__

#include <iostream>
#include <new>
#include "AbstractRecursiveTask.h"

//Test simple recursive task with quick sort problem

class QuickSortRecursiveTask : public AbstractRecursiveTask {
public:
    QuickSortRecursiveTask(int* array, unsigned int size);
    virtual ~QuickSortRecursiveTask();
    
    //@Override
    void* operator new (size_t size) throw (std::bad_alloc);
    
    //@Override
    void operator delete(void* objectPtr);
    
protected:
    //@Override
    virtual void prepare();
    
    //@Override
    virtual void getSubTaskPtrs(AbstractRecursiveTaskPtrs& subTaskPtrs, ResultStore& resultStoreRef);
    
    //@Override
    virtual ResultPtr collectResults(const ResultStore& subTaskResultStore);
    
    //@Override
    virtual void releaseSubResults(const ResultStore& subResultStoreRef);

    
private:
    int* m_array;
    unsigned int m_size;
    int m_pivot;
    static ObjectPoolPtr g_pObjectPool;
};

#endif /* defined(__ThreadPoolSample__SimpleRecursiveTask__) */
