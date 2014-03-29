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
#include "AbstractRecursiveTask.h"

//Test simple recursive task with quick sort problem

class QuickSortRecursiveTask : public AbstractRecursiveTask {
public:
    QuickSortRecursiveTask(int* array, unsigned int size);
    virtual ~QuickSortRecursiveTask();
    
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
};

#endif /* defined(__ThreadPoolSample__SimpleRecursiveTask__) */
