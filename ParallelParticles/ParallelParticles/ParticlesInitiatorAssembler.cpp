//
//  ParticlesInitiatorAssembler.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticlesInitiatorAssembler.h"
#include "IParticlesInitiator.h"
#include "ParticlesRandomInitiatorImpl.h"

ParticlesInitiatorPtr ParticlesInitiatorAssembler::createInitiatorInstance() {
    return new ParticlesRandomInitiatorImpl();
}

void ParticlesInitiatorAssembler::destroyInitiatorInstance(ParticlesInitiatorPtr pInstance) {
    delete pInstance;
}