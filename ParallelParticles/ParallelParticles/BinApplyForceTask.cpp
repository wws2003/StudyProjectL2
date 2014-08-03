//
//  BinApplyForceTask.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "BinApplyForceTask.h"
#include "Bin.h"
#include <iostream>

BinApplyForceTask::BinApplyForceTask(BinPtr pBin, ParticlePtr pParticle) : m_pBin(pBin), m_pParticle(pParticle) {
    
}

//Override
void BinApplyForceTask::execute() {
    m_pBin->applyForceToOneParticle(m_pParticle);
}