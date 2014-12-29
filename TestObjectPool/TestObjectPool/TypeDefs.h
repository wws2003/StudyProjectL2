//
//  TypeDefs.h
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef TestObjectPool_TypeDefs_h
#define TestObjectPool_TypeDefs_h

class IObjectPool;
typedef IObjectPool* ObjectPoolPtr;

enum POOL_ERR {
    ERR_NONE,
    ADD_OBJECT_FAILED,
    RETURN_OBJECT_FAILED
};

enum POOL_TYPE {
    SIMPLE,
    THREAD_SAFE
};

#endif
