//
//  Derived2PoolObject.cpp
//  TestObjectPool
//
//  Created by Scalzi on 8/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "Derived2PoolObject.h"
#include "ObjectPoolFactory.h"
#include <iostream>

ObjectPoolPtr Derived2PoolObject::g_pObjectPool = ObjectPoolFactory::createObjectPool();

Derived2PoolObject::Derived2PoolObject(int property1, int property2, int property3) : DerivedPoolObject(property1, property2), m_property3(property3) {
    //std::cout << "Constructing new derived object with property " << m_property2 << " \n";
}

Derived2PoolObject::~Derived2PoolObject() {
    //std::cout << "Deconstructing derived object with property " << m_property2 << " \n";
}

//static in fact
void* Derived2PoolObject::operator new(std::size_t size) throw (std::bad_alloc) {
    return PoolObject::operator new(size, g_pObjectPool);
}

//static in fact
void Derived2PoolObject::operator delete(void* objectPtr) {
    return PoolObject::operator delete(objectPtr, g_pObjectPool);
}