//
//  BinningAlgorimthSerialImpl.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//
#include "BinApplyForceTask.h"
#include "BinClearTask.h"
#include "BinningAlgorimthSerialImpl.h"
#include "ParticleMoveAndDistributeTask.h"

BinningAlgorithmSerialImpl::BinningAlgorithmSerialImpl() {
    
}

BinningAlgorithmSerialImpl::~BinningAlgorithmSerialImpl() {
    
}


//Override
void BinningAlgorithmSerialImpl::onApplyBinForceToOnParticle(BinPtr pBin, ParticlePtr pParticle) {
    BinApplyForceTaskPtr pTask(new BinApplyForceTask(pBin, pParticle));
    pTask->execute();
}

//Override
void BinningAlgorithmSerialImpl::onParticleAppliedForce(ParticlePtr pParticle) {
    
}

//Override
void BinningAlgorithmSerialImpl::onClearBin(BinPtr pBin) {
    BinClearTaskPtr pTask(new BinClearTask(pBin));
    pTask->execute();
}

//Override
void BinningAlgorithmSerialImpl::onBinsCleared() {
    
}

//Override
void BinningAlgorithmSerialImpl::onMoveAndPushParticleToBins(ParticlePtrs pParticles, unsigned int dt) {
    ParticleMoveAndDistributeTaskPtr pTask(new ParticleMoveAndDistributeTask(this, pParticles, dt, 0, (int)pParticles.size() - 1));
    pTask->execute();
}