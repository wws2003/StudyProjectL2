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
#include <iostream>

ParticleMoveAndDistributeTask::ParticleMoveAndDistributeTask(AbstractBinningAlgorithmPtr pAlgo, const ParticlePtrs& pParticles, const unsigned int& dt, const unsigned int& startIndex, const unsigned int& endIndex) : m_pAlgo(pAlgo), m_pParticles(pParticles), m_dt(dt), m_startIndex(startIndex), m_endIndex(endIndex) {
    
}

//Override
//Can run on other thread
void ParticleMoveAndDistributeTask::execute() {
    double spaceWidth, spaceHeight;
    m_pAlgo->getSpaceSize(spaceWidth, spaceHeight);
    double size = spaceWidth; //Temporally assume the space is square
    
    for (unsigned int i = m_startIndex; i <= m_endIndex; i++ ) {
        ParticlePtr pParticle = m_pParticles[i];
        move(*pParticle, size, m_dt);
        BinPtr pBin = m_pAlgo->findBinByPosition(pParticle->x, pParticle->y);
        //std::cout << "X " << pParticle->x << " Y " << pParticle->y << std::endl;
        if (pBin) {
            pBin->addParticle(pParticle);
        }
    }
}