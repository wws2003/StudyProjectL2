//
//  ParticleDistributeTask.h
//  ParallelParticles
//
//  Created by wws2003 on 8/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__ParticleDistributeTask__
#define __ParallelParticles__ParticleDistributeTask__

#include <iostream>
#include "PPTypeDefs.h"
#include "TypeDefs.h"
#include "ITask.h"

class ParticleDistributeTask : public ITask {
public:
    ParticleDistributeTask(AbstractBinningAlgorithmPtr pAlgo, const ParticlePtrs& pParticles);
    virtual ~ParticleDistributeTask(){};
    
    //Override
    virtual void execute();
    
    static void refreshPool();
    
private:
    AbstractBinningAlgorithmPtr m_pAlgo;
    ParticlePtrs m_pParticles;
    
    static ObjectPoolPtr g_pObjectPool;

};

#endif /* defined(__ParallelParticles__ParticleDistributeTask__) */
