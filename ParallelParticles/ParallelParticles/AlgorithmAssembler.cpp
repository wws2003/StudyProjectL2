//
//  AlgorithmAssembler.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AlgorithmAssembler.h"
#include "IParticleMoveAlgorithm.h"
#include "BinningAlgorithmMultiThreadImpl.h"
#include "ThreadPoolFactory.h"
#include "AbstractThreadPool.h"

AlgorithmAssembler::AlgorithmAssembler() {
    m_pThreadpool = ThreadPoolFactory::getThreadPoolPtr(4);
}

AlgorithmAssembler::~AlgorithmAssembler() {
    delete  m_pThreadpool;
}

ParticleMoveAlgorithmPtr AlgorithmAssembler::createAlgorithmInstance() {
    ParticleMoveAlgorithmPtr pAlgorithm = new BinningAlgorithmMultiThreadImpl(m_pThreadpool);
    return pAlgorithm;
}

void AlgorithmAssembler::destroyAlgorithm(ParticleMoveAlgorithmPtr pAlgorithm) {
    delete pAlgorithm;
}