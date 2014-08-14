//
//  ParticleDistributeTask.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticleDistributeTask.h"
#include "common.h"
#include "IObjectPool.h"
#include "ObjectPoolFactory.h"
#include "Bin.h"
#include "AbstractBinningAlgorithm.h"

ObjectPoolPtr ParticleDistributeTask::g_pObjectPool = ObjectPoolFactory::createObjectPool(SIMPLE);

ParticleDistributeTask::ParticleDistributeTask(AbstractBinningAlgorithmPtr pAlgo, const ParticlePtrs& pParticles) : m_pAlgo(pAlgo), m_pParticles(pParticles){
    
}

//Override
void ParticleDistributeTask::execute() {
    for (ParticlePtr pParticle : m_pParticles) {
       BinPtr pBin = m_pAlgo->findBinByPosition(pParticle->x, pParticle->y);
        //std::cout << "X " << pParticle->x << " Y " << pParticle->y << std::endl;
        if (pBin) {
            pBin->addParticle(pParticle);
        }
    }
}

void ParticleDistributeTask::refreshPool() {
    if (g_pObjectPool) {
        g_pObjectPool->refresh();
    }
}
