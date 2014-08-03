//
//  ParticleMoveAndDistributeTask.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticleMoveAndDistributeTask.h"
#include "Bin.h"
#include "common.h"
#include "AbstractBinningAlgorithm.h"

ParticleMoveAndDistributeTask::ParticleMoveAndDistributeTask(AbstractBinningAlgorithmPtr pAlgo, ParticlePtrs pParticles, const unsigned int& dt) : m_pAlgo(pAlgo), m_pParticles(pParticles), m_dt(dt) {
    
}

//Override
void ParticleMoveAndDistributeTask::execute() {
    double spaceWidth, spaceHeight;
    m_pAlgo->getSpaceSize(spaceWidth, spaceHeight);
    double size = spaceWidth; //Temporally assume the space is square
    
    for (ParticlePtrs::iterator pIter = m_pParticles.begin(); pIter != m_pParticles.end(); pIter++) {
        ParticlePtr pParticle = *pIter;
        move(*pParticle, size, m_dt);
        BinPtr pBin = m_pAlgo->findBinByPosition(pParticle->x, pParticle->y);
        if (pBin) {
            pBin->addParticle(pParticle);
        }
    }
}