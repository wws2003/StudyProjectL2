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
#include <algorithm>
#include <memory>

class IMutex;
typedef IMutex* MutexPtr;

class ICondVar;
typedef ICondVar* CondVarPtr;

class AbstractThreadPool;
typedef AbstractThreadPool* AbstractThreadPoolPtr;

class ITask;

#if SHARED_PTR == 0
typedef ITask* TaskPtr;
typedef std::vector<TaskPtr> TaskPtrs;

class TaskGroup;
typedef TaskGroup* TaskGroupPtr;

class AbstractChildTask;
typedef AbstractChildTask* AbstractChildTaskPtr;

class AbstractMasterTask;
typedef AbstractMasterTask* AbstractMasterTaskPtr;

class AbstractRecursiveTask;
typedef AbstractRecursiveTask* AbstractRecursiveTaskPtr;
typedef std::vector<AbstractRecursiveTaskPtr> AbstractRecursiveTaskPtrs;

class AbstractDelegatingSlaveTask;
typedef AbstractDelegatingSlaveTask* AbstractDelegatingSlaveTaskPtr;
typedef std::vector<AbstractDelegatingSlaveTaskPtr> AbstractDelegatingSlaveTaskPtrs;

class AbstractDelegatingMasterTask;
typedef AbstractDelegatingMasterTask* AbstractDelegatingMasterTaskPtr;

class IPThreadConfigurator;
typedef IPThreadConfigurator* PThreadConfiguratorPtr;

#define TASKPTR_DELETE(taskPtr) delete taskPtr

#else
typedef std::shared_ptr<ITask> TaskPtr;
typedef std::vector<TaskPtr> TaskPtrs;

class TaskGroup;
typedef std::shared_ptr<TaskGroup> TaskGroupPtr;

class AbstractChildTask;
typedef std::shared_ptr<AbstractChildTask> AbstractChildTaskPtr;

class AbstractMasterTask;
typedef std::shared_ptr<AbstractMasterTask> AbstractMasterTaskPtr;

class AbstractRecursiveTask;
typedef std::shared_ptr<AbstractRecursiveTask> AbstractRecursiveTaskPtr;
typedef std::vector<AbstractRecursiveTaskPtr> AbstractRecursiveTaskPtrs;

class AbstractDelegatingSlaveTask;
typedef std::shared_ptr<AbstractDelegatingSlaveTask> AbstractDelegatingSlaveTaskPtr;
typedef std::vector<AbstractDelegatingSlaveTaskPtr> AbstractDelegatingSlaveTaskPtrs;

class AbstractDelegatingMasterTask;
typedef std::shared_ptr<AbstractDelegatingMasterTask> AbstractDelegatingMasterTaskPtr;

#define TASKPTR_DELETE(taskPtr)
#endif

typedef void* ResultPtr;

typedef std::vector<ResultPtr> ResultStore;
typedef ResultStore* ResultStorePtr;

class ISubTaskDelegate;
typedef ISubTaskDelegate* ISubTaskDelegatePtr;

class IResultSignalDelegate;
typedef IResultSignalDelegate* IResultSignalDelegatePtr;

class IResultWaitDelegate;
typedef IResultWaitDelegate* IResultWaitDelegatePtr;

typedef std::pair<IResultWaitDelegatePtr, IResultSignalDelegatePtr> IResultDelegatePtrPair;

class IResultDelegatePairFactory;
typedef IResultDelegatePairFactory* IResultDelegatePairFactoryPtr;

class ResultSignalDelegate;
typedef ResultSignalDelegate* ResultSignalDelegatePtr;

class ResultWaitDelegate;
typedef ResultWaitDelegate* ResultWaitDelegatePtr;

enum CondVarErrorCode{
    COND_VAR_ERROR_NONE,
    SIGNAL_ERROR,
    BROADCAST_ERROR
};

enum TaskExecutorErrorCode{
    THREADPOOL_ERROR_NONE,
    INIT_THREAD_ERROR
};

class IObjectPool;
typedef IObjectPool* ObjectPoolPtr;

enum POOL_ERR {
    POOL_ERR_NONE,
    ADD_OBJECT_FAILED,
    RETURN_OBJECT_FAILED
};

enum POOL_TYPE {
    SIMPLE,
    THREAD_SAFE
};

#endif
