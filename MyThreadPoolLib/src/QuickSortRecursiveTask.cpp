//
//  SimpleRecursiveTask.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "QuickSortRecursiveTask.h"

QuickSortRecursiveTask::QuickSortRecursiveTask(int* array, unsigned int size) : AbstractRecursiveTask(), m_array(array), m_size(size), m_pivot(0) {
    
}

QuickSortRecursiveTask::~QuickSortRecursiveTask() {
    
}

//@Override
void QuickSortRecursiveTask::prepare() {
    int pVar = m_array[0];
    int pivot = 0;
    for (unsigned int i = 1; i < m_size; i++) {
        if (m_array[i] < pVar) {
            m_array[pivot] = m_array[i];
            m_array[i] = m_array[pivot + 1];
            m_array[pivot + 1] = pVar;
            pivot = pivot + 1;
        }
    }
    m_pivot = pivot;
}

//@Override
void QuickSortRecursiveTask::getSubTaskPtrs(AbstractRecursiveTaskPtrs& subTaskPtrs, ResultStore& resultStoreRef) {
    subTaskPtrs.clear();
    int start = 0;
    int end = m_size - 1;
    if(end <= start)
        return;
    else {
        int* subArray1 = m_array;
        unsigned int subSize1 = m_pivot - start;
        QuickSortRecursiveTask* subTaskPtr1 = new QuickSortRecursiveTask(subArray1, subSize1);
        subTaskPtrs.push_back(subTaskPtr1);
        int* subArray2 = m_array + m_pivot + 1;
        unsigned int subSize2 = end - m_pivot;
        QuickSortRecursiveTask* subTaskPtr2 = new QuickSortRecursiveTask(subArray2, subSize2);
        subTaskPtrs.push_back(subTaskPtr2);
    }
}

//@Override
ResultPtr QuickSortRecursiveTask::collectResults(const ResultStore& subTaskResultStore) {
    return NULL;
}

//@Override
void QuickSortRecursiveTask::releaseSubResults(const ResultStore& subResultStoreRef) {
    return;
}