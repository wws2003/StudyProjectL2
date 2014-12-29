//
//  BinningAlgorithmMultiThreadImpl.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "BinningAlgorithmMultiThreadImpl.h"
#include "BinApplyForceTask.h"
#include "AbstractThreadPool.h"
#include "BinClearTask.h"
#include "ParticleMoveTask.h"
#include "ParticleDistributeTask.h"

BinningAlgorithmMultiThreadImpl::BinningAlgorithmMultiThreadImpl(AbstractThreadPoolPtr pThreadPool) : m_pThreadPool(pThreadPool){
    m_pThreadPool->initAndStart(false);
}

BinningAlgorithmMultiThreadImpl::~BinningAlgorithmMultiThreadImpl() {
    
}


//Override
void BinningAlgorithmMultiThreadImpl::onApplyBinForceToOnParticle(BinPtr pBin, ParticlePtr pParticle) {
    BinApplyForceTaskPtr pTask(new BinApplyForceTask(pBin, pParticle));
    m_pThreadPool->addTask(pTask);
}

void BinningAlgorithmMultiThreadImpl::onParticleAppliedForce(ParticlePtr pParticle) {
    m_pThreadPool->waitAllTaskComplete();
    BinApplyForceTask::refreshPool();
}

//Override
void BinningAlgorithmMultiThreadImpl::onClearBin(BinPtr pBin) {
    BinClearTaskPtr pTask(new BinClearTask(pBin));
    m_pThreadPool->addTask(pTask);
}

//Override
void BinningAlgorithmMultiThreadImpl::onBinsCleared() {
    m_pThreadPool->waitAllTaskComplete();
    BinClearTask::refreshPool();
}

//Override
void BinningAlgorithmMultiThreadImpl::onMoveParticle(ParticlePtr pParticle, unsigned int dt) {
    double w,h;
    getSpaceSize(w, h);
    ParticleMoveTaskPtr pTask(new ParticleMoveTask(dt, w, h, pParticle));
    m_pThreadPool->addTask(pTask);
}

//Override
void BinningAlgorithmMultiThreadImpl::onDistributeParticleToBin(const ParticlePtrs pParticles) {
    m_pThreadPool->waitAllTaskComplete();
    ParticleMoveTask::refreshPool();
    ParticleDistributeTaskPtr pTask(new ParticleDistributeTask(this, pParticles));
    pTask->execute();
}
