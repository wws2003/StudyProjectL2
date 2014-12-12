//
//  concrete_typedef.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/12/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef MyReadWriteLock_concrete_typedef_h
#define MyReadWriteLock_concrete_typedef_h

#include <pthread.h>
#include "common.h"

typedef pthread_cond_t* pthread_cond_t_ptr;

class PThreadMutexLockImpl;
class PThreadReadLockImpl;
class PThreadWriteLockImpl;

#if NORMAL_PTR
typedef PThreadMutexLockImpl* PThreadMutexLockImplPtr;
typedef PThreadReadLockImpl* PThreadReadLockImplPtr;
typedef PThreadWriteLockImpl* PThreadWriteLockImplPtr;
#else

#endif

#endif
