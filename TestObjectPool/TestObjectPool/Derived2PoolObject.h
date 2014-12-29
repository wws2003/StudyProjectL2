//
//  Derived2PoolObject.h
//  TestObjectPool
//
//  Created by Scalzi on 8/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __TestObjectPool__Derived2PoolObject__
#define __TestObjectPool__Derived2PoolObject__

#include <iostream>

#include "DerivedPoolObject.h"

class Derived2PoolObject : public DerivedPoolObject {
public:
    Derived2PoolObject(int property1, int property2, int property3);
    virtual ~Derived2PoolObject();
    
    //Override
    void* operator new(std::size_t size) throw (std::bad_alloc);
    
    //Override
    void operator delete(void* objectPtr);
    
private:
    int m_property3;
    static ObjectPoolPtr g_pObjectPool;
};

#endif /* defined(__TestObjectPool__Derived2PoolObject__) */
