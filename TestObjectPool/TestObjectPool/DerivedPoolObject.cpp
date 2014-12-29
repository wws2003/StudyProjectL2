//
//  DerivedPoolObject.cpp
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "DerivedPoolObject.h"
#include "ObjectPoolFactory.h"
#include <iostream>

ObjectPoolPtr DerivedPoolObject::g_pObjectPool = ObjectPoolFactory::createObjectPool(SIMPLE);

DerivedPoolObject::DerivedPoolObject(int property1, int property2) : PoolObject(property1), m_property2(property2) {
     //std::cout << "Constructing new derived object with property " << m_property2 << " \n";
}

DerivedPoolObject::~DerivedPoolObject() {
    //std::cout << "Deconstructing derived object with property " << m_property2 << " \n";
}

//static in fact
void* DerivedPoolObject::operator new(std::size_t size) throw (std::bad_alloc) {
    return PoolObject::operator new(size, g_pObjectPool);
}

//static in fact
void DerivedPoolObject::operator delete(void* objectPtr) {
    return PoolObject::operator delete(objectPtr, g_pObjectPool);
}