//
//  SubTaskDelegateImpl.cpp
//  ThreadPoolSample
//
//  Created by wws2003 on 3/25/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "SubTaskDelegateImpl.h"
#include "AbstractRecursiveTask.h"
#include "AbstractThreadPool.h"
#include "ITask.h"

SubTaskDelegateImpl::SubTaskDelegateImpl(AbstractThreadPoolPtr threadPoolPtr) : ISubTaskDelegate(), m_threadPoolPtr(threadPoolPtr) {
    
}

SubTaskDelegateImpl::~SubTaskDelegateImpl() {
    
}

//@Override
unsigned int SubTaskDelegateImpl::executeSubTasks(const AbstractRecursiveTaskPtrs& subRecursiveTaskPtrs) {
    ITaskPtrs subTaskPtrs;
    subTaskPtrs.insert(subTaskPtrs.begin(), subRecursiveTaskPtrs.begin(), subRecursiveTaskPtrs.end());
    
    //Add as much task to thread pool as possible, the remaining tasks will be executed in the current thread
    
    unsigned int numberOfTaskCanAddToThreadPool = m_threadPoolPtr->addTaskBatch(subTaskPtrs);
    for (unsigned int i = numberOfTaskCanAddToThreadPool; i < subTaskPtrs.size(); i++) {
        subTaskPtrs[i]->execute();
    }
    
    return (unsigned int)subTaskPtrs.size() - numberOfTaskCanAddToThreadPool;
}
