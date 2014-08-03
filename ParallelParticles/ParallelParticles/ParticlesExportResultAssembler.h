//
//  ParticleExportResultAssembler.h
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__ParticleExportResultAssembler__
#define __ParallelParticles__ParticleExportResultAssembler__

#include <iostream>
#include "PPTypeDefs.h"

class ParticlesExportResultAssembler {
public:
    ParticlesExportResultPtr createInitiatorInstance();
    void destroyExportResultInstance(ParticlesExportResultPtr pInstance);
};

#endif /* defined(__ParallelParticles__ParticleExportResultAssembler__) */
