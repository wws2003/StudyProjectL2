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
#include "ParticleMoveAndDistributeTask.h"


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
}

//Override
void BinningAlgorithmMultiThreadImpl::onClearBin(BinPtr pBin) {
    BinClearTaskPtr pTask(new BinClearTask(pBin));
    m_pThreadPool->addTask(pTask);
}

//Override
void BinningAlgorithmMultiThreadImpl::onBinsCleared() {
    m_pThreadPool->waitAllTaskComplete();
}

//Override
void BinningAlgorithmMultiThreadImpl::onMoveAndPushParticleToBins(ParticlePtrs pParticles, unsigned int dt) {
    const unsigned int numberOfThread = 4; //TODO Inject this dependency
    const unsigned int numberOfParticleInAThread = (unsigned int)pParticles.size() / numberOfThread;
    
    unsigned int startIndex = 0;
    for (unsigned int i = 0; i < numberOfThread; i++) {
        unsigned int endIndex = startIndex + numberOfParticleInAThread - 1;
        if (i == numberOfThread - 1) {
            endIndex += (unsigned int)pParticles.size() % numberOfThread;
        }
        ParticleMoveAndDistributeTaskPtr pTask(new ParticleMoveAndDistributeTask(this, pParticles, dt, startIndex, endIndex));
        m_pThreadPool->addTask(pTask);
        startIndex += numberOfParticleInAThread;
    }
    m_pThreadPool->waitAllTaskComplete();
}
