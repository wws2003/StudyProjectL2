//
//  ParticlesRandomInitiatorImpl.h
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__ParticlesRandomInitiatorImpl__
#define __ParallelParticles__ParticlesRandomInitiatorImpl__

#include <iostream>
#include "PPTypeDefs.h"
#include "IParticlesInitiator.h"

class ParticlesRandomInitiatorImpl : public IParticlesInitiator {
public:
    //Override
    virtual PP_ERR initParticles(ParticlePtrs& particles, double& rSpaceWidth, double& rSpaceHeight, double& density);
};

#endif /* defined(__ParallelParticles__ParticlesRandomInitiatorImpl__) */
