//
//  common.h
//  MyReadWriteLock
//
//  Created by wws2003 on 12/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef MyReadWriteLock_common_h
#define MyReadWriteLock_common_h

class ILock;
class RWCritical;
class AbstractReadLock;
class AbstractWriteLock;

#define NORMAL_PTR 1

#if NORMAL_PTR
typedef ILock* PLock;
typedef RWCritical* RWCriticalPtr;
typedef AbstractReadLock* AbstractReadLockPtr;
typedef AbstractWriteLock* AbstractWriteLockPtr;
#else

#endif

#endif
