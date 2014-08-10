//
//  PoolObject.cpp
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PoolObject.h"
#include "IObjectPool.h"
#include "ObjectPoolManager.h"
#include <iostream>

ObjectPoolPtr PoolObject::g_pObjectPool = ObjectPoolManager::getObjectPool();

PoolObject::PoolObject(int property) : m_property(property) {
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
                if (pPool->addObjectPtr(::operator new(size, pPool)) != ERR_NONE) {
                    return NULL;
                }
            }
        }
        return pPool->getObjectPtr();
    }
    return ::operator new(size);
}

//static in fact
void* PoolObject::operator new(std::size_t size) throw (std::bad_alloc) {
    //std::cout << "Creating new object with size " << size << " \n";
    void* ptr = NULL;
    if (g_pObjectPool) {
        ptr = g_pObjectPool->getObjectPtr();
        if (!ptr) {
            size_t oldCapacity = g_pObjectPool->getSize();
            size_t newCapacity = (oldCapacity == 0) ? 100 : oldCapacity * 1.5;
            g_pObjectPool->reserve(newCapacity);
            size_t numberOfNewObjectToAdd = newCapacity - oldCapacity;
            for (int i = 0; i < numberOfNewObjectToAdd; i++) {
                //std::cout << "Have to create a new object size = " << size << " \n";
                if (g_pObjectPool->addObjectPtr(::operator new(size)) != ERR_NONE) {
                    return NULL;
                }
            }
            ptr = g_pObjectPool->getObjectPtr();
            return ptr;
        }
        else {
            return ptr;
        }
    }
    return ::operator new(size);
}

//static in fact
void PoolObject::operator delete(void* objectPtr) {
    //std::cout << "Deleting an object\n";
    if (!g_pObjectPool || g_pObjectPool->returnObjectPtr(objectPtr) != ERR_NONE) {
        ::operator delete(objectPtr);
    }
    return;
}

//static in fact
void PoolObject::operator delete(void* objectPtr, ObjectPoolPtr pPool) {
    if (!pPool || pPool->returnObjectPtr(objectPtr) != ERR_NONE) {
        ::operator delete(objectPtr);
    }
    return;
}