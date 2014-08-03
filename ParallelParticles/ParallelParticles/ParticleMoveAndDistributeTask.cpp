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

ParticleMoveAndDistributeTask::ParticleMoveAndDistributeTask(AbstractBinningAlgorithmPtr pAlgo, ParticlePtrs pParticles, const unsigned int& dt) : m_pAlgo(pAlgo), m_pParticles(pParticles), m_dt(dt) {
    
}

//Override
void ParticleMoveAndDistributeTask::execute() {
    //std::cout << "Executing task ParticleMoveAndDistributeTask \n";
    double spaceWidth, spaceHeight;
    m_pAlgo->getSpaceSize(spaceWidth, spaceHeight);
    double size = spaceWidth; //Temporally assume the space is square
    
    for (ParticlePtr pParticle : m_pParticles) {
        move(*pParticle, size, m_dt);
        BinPtr pBin = m_pAlgo->findBinByPosition(pParticle->x, pParticle->y);
        if (pBin) {
            pBin->addParticle(pParticle);
        }
    }
}