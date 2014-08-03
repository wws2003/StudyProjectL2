//
//  AlgorithmAssembler.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticleMoveAlgorithmAssembler.h"
#include "IParticleMoveAlgorithm.h"
#include "BinningAlgorithmMultiThreadImpl.h"
#include "ThreadPoolFactory.h"
#include "AbstractThreadPool.h"

ParticleMoveAlgorithmAssembler::ParticleMoveAlgorithmAssembler() {
    m_pThreadpool = ThreadPoolFactory::getThreadPoolPtr(4);
}

ParticleMoveAlgorithmAssembler::~ParticleMoveAlgorithmAssembler() {
    m_pThreadpool->destroy();
    delete  m_pThreadpool;
}

ParticleMoveAlgorithmPtr ParticleMoveAlgorithmAssembler::createAlgorithmInstance() {
    ParticleMoveAlgorithmPtr pAlgorithm = new BinningAlgorithmMultiThreadImpl(m_pThreadpool);
    return pAlgorithm;
}

void ParticleMoveAlgorithmAssembler::destroyAlgorithm(ParticleMoveAlgorithmPtr pAlgorithm) {
    delete pAlgorithm;
}