//
//  BinningAlgorithmMultithreadBatchImpl.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/14/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "BinningAlgorithmMultithreadBatchImpl.h"
#include "BinningAlgorithmMultiThreadImpl.h"
#include "BinApplyForceTask.h"
#include "AbstractThreadPool.h"
#include "BinClearTask.h"
#include "ParticleMoveTask.h"
#include "ParticleDistributeTask.h"

BinningAlgorithmMultithreadBatchImpl::BinningAlgorithmMultithreadBatchImpl(AbstractThreadPoolPtr pThreadPool) : m_pThreadPool(pThreadPool){
    m_pThreadPool->initAndStart(false);
}

BinningAlgorithmMultithreadBatchImpl::~BinningAlgorithmMultithreadBatchImpl() {
    
}


//Override
void BinningAlgorithmMultithreadBatchImpl::onApplyBinForceToOnParticle(BinPtr pBin, ParticlePtr pParticle) {
    BinApplyForceTaskPtr pTask(new BinApplyForceTask(pBin, pParticle));
    m_pApplyBinForceTasks.push_back(pTask);
}

void BinningAlgorithmMultithreadBatchImpl::onParticleAppliedForce(ParticlePtr pParticle) {
    m_pThreadPool->addTaskBatch(m_pApplyBinForceTasks);
    m_pThreadPool->waitAllTaskComplete();
    m_pApplyBinForceTasks.clear();
    BinApplyForceTask::refreshPool();
}

//Override
void BinningAlgorithmMultithreadBatchImpl::onClearBin(BinPtr pBin) {
    BinClearTaskPtr pTask(new BinClearTask(pBin));
    m_pClearBinTasks.push_back(pTask);
}

//Override
void BinningAlgorithmMultithreadBatchImpl::onBinsCleared() {
    m_pThreadPool->addTaskBatch(m_pClearBinTasks);
    m_pThreadPool->waitAllTaskComplete();
    m_pClearBinTasks.clear();
    BinClearTask::refreshPool();
}

//Override
void BinningAlgorithmMultithreadBatchImpl::onMoveParticle(ParticlePtr pParticle, unsigned int dt) {
    double w,h;
    getSpaceSize(w, h);
    ParticleMoveTaskPtr pTask(new ParticleMoveTask(dt, w, h, pParticle));
    m_pParticleMoveTasks.push_back(pTask);
}

//Override
void BinningAlgorithmMultithreadBatchImpl::onDistributeParticleToBin(const ParticlePtrs pParticles) {
    m_pThreadPool->addTaskBatch(m_pParticleMoveTasks);
    m_pThreadPool->waitAllTaskComplete();
    m_pParticleMoveTasks.clear();
    ParticleMoveTask::refreshPool();
    
    ParticleDistributeTaskPtr pTask(new ParticleDistributeTask(this, pParticles));
    pTask->execute();
}
