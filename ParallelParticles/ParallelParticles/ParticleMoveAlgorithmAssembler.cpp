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
#include "BinningAlgorimthSerialImpl.h"
#include "ThreadPoolFactory.h"
#include "AbstractThreadPool.h"

ParticleMoveAlgorithmAssembler::ParticleMoveAlgorithmAssembler() : m_pThreadpool(NULL){
}

ParticleMoveAlgorithmAssembler::~ParticleMoveAlgorithmAssembler() {
    if (m_pThreadpool) {
        m_pThreadpool->destroy();
        delete  m_pThreadpool;
    }
}

ParticleMoveAlgorithmPtr ParticleMoveAlgorithmAssembler::createAlgorithmInstance(const int type) {
    ParticleMoveAlgorithmPtr pAlgorithm = NULL;
    switch (type) {
        case MULTI_THREAD:
            m_pThreadpool = ThreadPoolFactory::getThreadPoolPtr(2);
            pAlgorithm = new BinningAlgorithmMultiThreadImpl(m_pThreadpool);
            break;
        case SERIAL:
            pAlgorithm = new BinningAlgorithmSerialImpl();
            break;
        default:
            break;
    }
    return pAlgorithm;
}

void ParticleMoveAlgorithmAssembler::destroyAlgorithm(ParticleMoveAlgorithmPtr pAlgorithm) {
    delete pAlgorithm;
}