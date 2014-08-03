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
    const unsigned int numberOfThread = 2; //TODO Inject this dependency
    const unsigned int numberOfParticleInAThread = (unsigned int)pParticles.size() / numberOfThread;
    
    std::vector<ParticlePtrs> pParticlesVector;
    for (unsigned int i = 0; i < numberOfThread; i++) {
        pParticlesVector.push_back(ParticlePtrs());
    }
    unsigned int t = 0;
    unsigned int p = 0;
    for (unsigned int i = 0; i < pParticles.size(); i++) {
        if (p == numberOfParticleInAThread) {
            t++;
            p = 0;
        }
        pParticlesVector[t].push_back(pParticles[i]);
        p++;
    }
    
    for (unsigned int i = 0; i < numberOfThread; i++) {
        ParticleMoveAndDistributeTaskPtr pTask(new ParticleMoveAndDistributeTask(this, pParticlesVector[i], dt));
        m_pThreadPool->addTask(pTask);
    }
    m_pThreadPool->waitAllTaskComplete();
}
