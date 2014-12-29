//
//  IParticlesExportResult.h
//  ParallelParticles
//
//  Created by wws2003 on 7/28/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ParallelParticles_IParticlesExportResult_h
#define ParallelParticles_IParticlesExportResult_h

#include "PPTypeDefs.h"

class IParticlesExportResult {
public:
    IParticlesExportResult(){};
    virtual ~IParticlesExportResult(){};
    virtual void setBasicInfo(const unsigned int& particleNumber, const double& spaceWidth, const double& spaceHeight) = 0;
    virtual PP_ERR exportParticlesResult(const ParticlePtrs& particles) = 0;
};


#endif
