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
#include "ParticleMoveTask.h"
#include "ParticleDistributeTask.h"

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
     BinApplyForceTask::refreshPool();
}

//Override
void BinningAlgorithmSerialImpl::onClearBin(BinPtr pBin) {
    BinClearTaskPtr pTask(new BinClearTask(pBin));
    pTask->execute();
}

//Override
void BinningAlgorithmSerialImpl::onBinsCleared() {
    BinClearTask::refreshPool();
}

//Override
void BinningAlgorithmSerialImpl::onMoveParticle(ParticlePtr pParticle, unsigned int dt) {
    double w,h;
    getSpaceSize(w, h);
    ParticleMoveTaskPtr pTask(new ParticleMoveTask(dt, w, h, pParticle));
    pTask->execute();
}

//Override
void BinningAlgorithmSerialImpl::onDistributeParticleToBin(const ParticlePtrs pParticles) {
    ParticleMoveTask::refreshPool();
    ParticleDistributeTaskPtr pTask(new ParticleDistributeTask(this, pParticles));
    pTask->execute();
}