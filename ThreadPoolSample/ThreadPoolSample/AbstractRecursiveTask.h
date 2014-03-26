//
//  AbstractRecursiveTask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/22/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__AbstractRecursiveTask__
#define __ThreadPoolSample__AbstractRecursiveTask__

#include <iostream>
#include "ITask.h"
#include "TypeDefs.h"

class AbstractRecursiveTask : public ITask{
public:
    AbstractRecursiveTask(IResultWaitDelegatePtr subTaskResultsWaitPtr, ISubTaskDelegatePtr subTaskDelegatePtr, IResultSignalDelegatePtr resultSignalPtr, ResultStore& parentTaskResultStoreRef);
    
    virtual ~AbstractRecursiveTask();
    
    //@Override
    virtual void execute();
    
protected:
    virtual void prepare() = 0;
    
    virtual void getSubTaskPtrs(AbstractRecursiveTaskPtrs subTaskPtrs) = 0;
    virtual unsigned int executeSubTasks(const AbstractRecursiveTaskPtrs& subTaskPtrs);
    virtual void waitForResults(const ResultStore& subResultStoreRef, const unsigned int numberOfJobTodo);
    
    virtual ResultPtr collectResults() = 0;
    
    virtual void releaseSubResults(const ResultStore& subResultStoreRef) = 0;
    virtual void releaseSubTaskPtrs(const AbstractRecursiveTaskPtrs& subTaskPtrs);
    
    virtual void reportResult(const ResultPtr resultPtr);
    
    IResultWaitDelegatePtr m_subTaskResultsWaitDelegatePtr;
    ISubTaskDelegatePtr m_subTaskDelagatePtr;
    IResultSignalDelegatePtr m_resultSignalDelegatePtr;
    ResultStore& m_parentResultStoreRef;
};

#endif /* defined(__ThreadPoolSample__AbstractRecursiveTask__) */
