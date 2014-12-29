//
//  PoolObject.cpp
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PoolObject.h"
#include "IObjectPool.h"
#include "ObjectPoolFactory.h"
#include <iostream>

PoolObject::PoolObject() {
    //std::cout << "Constructing new object with property " << property << " \n";
}

PoolObject::~PoolObject() {
   //std::cout << "Deconstructing object with property " << m_property << " \n";
}

//static in fact
void* PoolObject::operator new(std::size_t size, ObjectPoolPtr pPool) throw (std::bad_alloc) {
    if (pPool) {
        void* ptr = pPool->getObjectPtr();
        if (!ptr) {
            size_t oldCapacity = pPool->getSize();
            size_t newCapacity = (oldCapacity == 0) ? 100 : oldCapacity * 1.2;
            size_t numberOfNewObjectToAdd = newCapacity - oldCapacity;
            pPool->reserve(newCapacity);
            for (int i = 0; i < numberOfNewObjectToAdd; i++) {
                if (pPool->addObjectPtr(::operator new(size)) != POOL_ERR_NONE) {
                    return NULL;
                }
            }
            ptr = pPool->getObjectPtr();
        }
        return ptr;
        
    }
    return ::operator new(size);
}

//static in fact
void* PoolObject::operator new(std::size_t size) throw (std::bad_alloc) {
    return ::operator new(size);
}

//static in fact
void PoolObject::operator delete(void* objectPtr) {
    //std::cout << "Deleting an object\n";
    return ::operator delete(objectPtr);
}

//static in fact
void PoolObject::operator delete(void* objectPtr, ObjectPoolPtr pPool) {
    if (!pPool || pPool->returnObjectPtr(objectPtr) != POOL_ERR_NONE) {
        ::operator delete(objectPtr);
    }
    return;
}