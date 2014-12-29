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
    AbstractRecursiveTask();
    
    virtual ~AbstractRecursiveTask();
    
    //@Override
    virtual void execute();
    
    virtual void setParentResultStorePtr(ResultStorePtr parentResultStorePtr);
    virtual void setSubTaskDelegatePtr(ISubTaskDelegatePtr subTaskDelegatePtr);
    virtual void setResultSignalDelegatePtr(IResultSignalDelegatePtr resultSignalPtr);
    virtual void setResultDelegatePairFactoryPtr(IResultDelegatePairFactoryPtr resultDelegateFactoryPtr);
    
protected:
    virtual void prepare() = 0;
    
    virtual void getSubTaskPtrs(AbstractRecursiveTaskPtrs& subTaskPtrs, ResultStore& resultStoreRef) = 0;
    
    virtual ResultPtr collectResults(const ResultStore& subTaskResultStore) = 0;
    
    virtual void releaseSubResults(const ResultStore& subResultStoreRef) = 0;
    
private:
    void executeSubTasks(AbstractRecursiveTaskPtrs& subTaskPtrs, ResultStore& resultStoreRef);
    void waitForResults(IResultWaitDelegatePtr resultWaitDelegatePtr, const ResultStore& subResultStoreRef, const unsigned int numberOfJobTodo);
    void releaseSubTaskPtrs(const AbstractRecursiveTaskPtrs& subTaskPtrs);
    void reportResult(const ResultPtr resultPtr);
    
    ResultStorePtr m_parentResultStorePtr;
    IResultDelegatePairFactoryPtr m_resultDelegatePairFactoryPtr;
    ISubTaskDelegatePtr m_subTaskDelagatePtr;
    IResultSignalDelegatePtr m_resultSignalDelegatePtr;
};

#endif /* defined(__ThreadPoolSample__AbstractRecursiveTask__) */
