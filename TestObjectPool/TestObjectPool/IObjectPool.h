//
//  IObjectPool.h
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef TestObjectPool_IObjectPool_h
#define TestObjectPool_IObjectPool_h

#include "TypeDefs.h"

class IObjectPool {
public:
    
    IObjectPool(){};
    virtual ~IObjectPool(){};
    
    virtual void reserve(const size_t size) = 0; // Prepare space for $size objects
    virtual size_t getSize() = 0; //Return number of objects in pool
    virtual POOL_ERR addObjectPtr(void* objectPtr) = 0; //Add a object ptr to pool
    
    virtual void* getObjectPtr() = 0;//Get an object ptr from pool
    virtual POOL_ERR returnObjectPtr(void* objectPtr) = 0;//Return to pool an object ptr
    
    virtual void drain() = 0; //deallocate all object in pool
};

#endif
