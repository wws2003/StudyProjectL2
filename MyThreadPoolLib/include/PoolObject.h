//
//  PoolObject.h
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __TestObjectPool__PoolObject__
#define __TestObjectPool__PoolObject__

#include <new>
#include "TypeDefs.h"

class PoolObject {
public:
    PoolObject();
    virtual ~PoolObject();
    
    //Override
    void* operator new(std::size_t size, ObjectPoolPtr pPool) throw (std::bad_alloc);
   
     //Override
    void* operator new(std::size_t size) throw (std::bad_alloc);
    
    //Override
    void operator delete(void* objectPtr);
    
    //Override
    void operator delete(void* objectPtr, ObjectPoolPtr pPool);
};

#endif /* defined(__TestObjectPool__PoolObject__) */
