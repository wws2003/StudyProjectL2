//
//  TypeDefs.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ThreadPoolSample_TypeDefs_h
#define ThreadPoolSample_TypeDefs_h

#include <vector>

class ITask;
typedef ITask* ITaskPtr;
typedef std::vector<ITaskPtr> ITaskPtrs;

class IMutex;
typedef IMutex* IMutexPtr;

class ICondVar;
typedef ICondVar* ICondVarPtr;

class AbstractThreadPool;
typedef AbstractThreadPool* AbstractThreadPoolPtr;

class TaskGroup;
typedef TaskGroup* TaskGroupPtr;

class AbstractChildTask;
typedef AbstractChildTask* AbstractChildTaskPtr;

class AbstractMasterTask;
typedef AbstractMasterTask* AbstractMasterTaskPtr;

typedef void* ResultPtr;

typedef std::vector<ResultPtr> ResultStore;

class AbstractRecursiveTask;
typedef AbstractRecursiveTask* AbstractRecursiveTaskPtr;
typedef std::vector<AbstractRecursiveTaskPtr> AbstractRecursiveTaskPtrs;

class ISubTaskDelegate;
typedef ISubTaskDelegate* ISubTaskDelegatePtr;

class IResultSignalDelegate;
typedef IResultSignalDelegate* IResultSignalDelegatePtr;

class IResultWaitDelegate;
typedef IResultWaitDelegate* IResultWaitDelegatePtr;

class ResultSignalDelegate;
typedef ResultSignalDelegate* ResultSignalDelegatePtr;

class ResultWaitDelegate;
typedef ResultWaitDelegate* ResultWaitDelegatePtr;

class AbstractDelegatingSlaveTask;
typedef AbstractDelegatingSlaveTask* AbstractDelegatingSlaveTaskPtr;
typedef std::vector<AbstractDelegatingSlaveTaskPtr> AbstractDelegatingSlaveTaskPtrs;

class AbstractDelegatingMasterTask;
typedef AbstractDelegatingMasterTask* AbstractDelegatingMasterTaskPtr;

enum CondVarErrorCode{
    COND_VAR_ERROR_NONE,
    SIGNAL_ERROR,
    BROADCAST_ERROR
};

enum ThreadPoolErrorCode{
    THREADPOOL_ERROR_NONE,
    INIT_THREAD_ERROR
};


#endif
