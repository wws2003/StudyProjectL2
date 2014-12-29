//
//  ParticleMoveTask.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticleMoveTask.h"
#include "common.h"
#include "IObjectPool.h"
#include "ObjectPoolFactory.h"

ObjectPoolPtr ParticleMoveTask::g_pObjectPool = ObjectPoolFactory::createObjectPool(SIMPLE);

ParticleMoveTask::ParticleMoveTask(const unsigned int& dt, const double& spaceWidth, const double& spaceHeight, ParticlePtr& pMovingParticle) : m_dt(dt), m_spaceSize(spaceWidth), m_pMovingParticle(pMovingParticle) {
    //Assume the space is square
}

//@Override
void* ParticleMoveTask::operator new (size_t size) throw (std::bad_alloc) {
    return PoolObject::operator new(size, g_pObjectPool);
}

//@Override
void ParticleMoveTask::operator delete(void* objectPtr) {
    return PoolObject::operator delete(objectPtr, g_pObjectPool);
}

//Override
void ParticleMoveTask::execute() {
    move(*m_pMovingParticle, m_spaceSize, m_dt);
}

void ParticleMoveTask::refreshPool() {
    if (g_pObjectPool) {
        g_pObjectPool->refresh();
    }
}