//
//  DerivedPoolObject.h
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __TestObjectPool__DerivedPoolObject__
#define __TestObjectPool__DerivedPoolObject__

#include <iostream>
#include "PoolObject.h"

class DerivedPoolObject : public PoolObject {
public:
    DerivedPoolObject(int property1, int property2);
    virtual ~DerivedPoolObject();
    
    //Override
    void* operator new(std::size_t size) throw (std::bad_alloc);
    
    //Override
    void operator delete(void* objectPtr);
    
private:
    int m_property2;
};

#endif /* defined(__TestObjectPool__DerivedPoolObject__) */
