//
//  ObjectPoolSimpleImpl.cpp
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <new>
#include <iostream>
#include "ObjectPoolSimpleImpl.h"

ObjectPoolSimpleImpl::ObjectPoolSimpleImpl() : m_indexOfLastObject(-1) {
    
}

ObjectPoolSimpleImpl::~ObjectPoolSimpleImpl() {
    
}

//Override
void ObjectPoolSimpleImpl::reserve(const size_t size) {
    m_objectPtrs.reserve(size);
}

//Override
size_t ObjectPoolSimpleImpl::getSize() {
    return m_objectPtrs.size();
}

//Override
POOL_ERR ObjectPoolSimpleImpl::addObjectPtr(void* objectPtr) {
    m_objectPtrs.push_back(objectPtr);
    m_indexOfLastObject++;
    return POOL_ERR_NONE;
}

//Override
void* ObjectPoolSimpleImpl::getObjectPtr() {
    if(m_indexOfLastObject < 0)
        return NULL;
    return m_objectPtrs[m_indexOfLastObject--];
}

//Override
POOL_ERR ObjectPoolSimpleImpl::returnObjectPtr(void* objectPtr) {
    m_indexOfLastObject++;
    return POOL_ERR_NONE;
}

void ObjectPoolSimpleImpl::refresh() {
    m_indexOfLastObject = m_objectPtrs.size() - 1;
}

//Override
void ObjectPoolSimpleImpl::drain() {
    std::nothrow_t t;
    for (void* ptr : m_objectPtrs) {
        operator delete(ptr, t);
    }
    m_objectPtrs.clear();
}