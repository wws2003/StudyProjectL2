//
//  IParticlesInitiator.h
//  ParallelParticles
//
//  Created by wws2003 on 7/28/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ParallelParticles_IParticlesInitiator_h
#define ParallelParticles_IParticlesInitiator_h

#include "PPTypeDefs.h"

class IParticlesInitiator {
public:
    IParticlesInitiator(){};
    virtual ~IParticlesInitiator(){};
    virtual PP_ERR initParticles(ParticlePtrs& particles, double& rSpaceWidth, double& rSpaceHeight, double& density) = 0;
};

#endif
