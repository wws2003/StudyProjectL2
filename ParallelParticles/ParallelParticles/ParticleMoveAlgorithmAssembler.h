//
//  AlgorithmAssembler.h
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__AlgorithmAssembler__
#define __ParallelParticles__AlgorithmAssembler__

#include <iostream>
#include "PPTypeDefs.h"
#include "TypeDefs.h"

class ParticleMoveAlgorithmAssembler {
public:
    enum AlgorithmType {
        MULTI_THREAD,
        SERIAL
    };
    
    ParticleMoveAlgorithmAssembler();
    virtual ~ParticleMoveAlgorithmAssembler();
    ParticleMoveAlgorithmPtr createAlgorithmInstance(const int type = MULTI_THREAD);
    void destroyAlgorithm(ParticleMoveAlgorithmPtr pAlgorithm);
    
private:
    AbstractThreadPoolPtr m_pThreadpool;
};

#endif /* defined(__ParallelParticles__AlgorithmAssembler__) */
