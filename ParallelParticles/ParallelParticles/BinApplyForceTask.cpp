//
//  BinApplyForceTask.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "BinApplyForceTask.h"
#include "Bin.h"
#include "ObjectPoolFactory.h"
#include "IObjectPool.h"
#include <iostream>

ObjectPoolPtr BinApplyForceTask::g_pObjectPool = ObjectPoolFactory::createObjectPool(SIMPLE);

BinApplyForceTask::BinApplyForceTask(BinPtr pBin, ParticlePtr pParticle) : m_pBin(pBin), m_pParticle(pParticle) {
    
}

//@Override
void* BinApplyForceTask::operator new (size_t size) throw (std::bad_alloc) {
    return PoolObject::operator new(size, g_pObjectPool);
}

//@Override
void BinApplyForceTask::operator delete(void* objectPtr) {
    return PoolObject::operator delete(objectPtr, g_pObjectPool);
}

//Override
//Can run on other thread
void BinApplyForceTask::execute() {
    m_pBin->applyForceToOneParticle(m_pParticle);
}

void BinApplyForceTask::refreshPool() {
    if (g_pObjectPool) {
        g_pObjectPool->refresh();
    }
}