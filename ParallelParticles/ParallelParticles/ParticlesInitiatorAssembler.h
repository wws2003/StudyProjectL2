//
//  ParticlesInitiatorAssembler.h
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__ParticlesInitiatorAssembler__
#define __ParallelParticles__ParticlesInitiatorAssembler__

#include <iostream>
#include "PPTypeDefs.h"

class ParticlesInitiatorAssembler {
public:
    ParticlesInitiatorPtr createInitiatorInstance();
    void destroyInitiatorInstance(ParticlesInitiatorPtr pInstance);
};

#endif /* defined(__ParallelParticles__ParticlesInitiatorAssembler__) */
