//
//  ObjectPoolSimpleImpl.h
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __TestObjectPool__ObjectPoolSimpleImpl__
#define __TestObjectPool__ObjectPoolSimpleImpl__

#include <iostream>
#include <vector>
#include "IObjectPool.h"

class ObjectPoolSimpleImpl : public IObjectPool{
public:
    ObjectPoolSimpleImpl();
    virtual ~ObjectPoolSimpleImpl();
    
    //Override
    virtual void reserve(const size_t size);
    
    //Override
    virtual size_t getSize();
    
    //Override
    virtual POOL_ERR addObjectPtr(void* objectPtr);
    
    //Override
    virtual void* getObjectPtr();
    
    //Override
    virtual POOL_ERR returnObjectPtr(void* objectPtr);
    
    //Override
    virtual void drain();
    
private:
    std::vector<void*> m_objectPtrs;
    int m_indexOfLastObject;

};

#endif /* defined(__TestObjectPool__ObjectPoolSimpleImpl__) */
