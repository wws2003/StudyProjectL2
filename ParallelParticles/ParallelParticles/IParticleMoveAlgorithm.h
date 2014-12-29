//
//  IParticleMoveAlgorithm.h
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ParallelParticles_IParticleMoveAlgorithm_h
#define ParallelParticles_IParticleMoveAlgorithm_h

#include "PPTypeDefs.h"

class IParticleMoveAlgorithm {
public:
    IParticleMoveAlgorithm(){};
    virtual ~IParticleMoveAlgorithm(){};
    
    virtual void setParticles(const ParticlePtrs& particles, const double& spaceWidth, const double& spaceHeight, const double& density) = 0;
    virtual PP_ERR moveParticles(unsigned int dt) = 0;
};

#endif
