//
//  ParticleMoveAndDistributeTask.h
//  ParallelParticles
//
//  Created by wws2003 on 7/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__ParticleMoveAndDistributeTask__
#define __ParallelParticles__ParticleMoveAndDistributeTask__

#include <iostream>
#include "PPTypeDefs.h"
#include "TypeDefs.h"
#include "ITask.h"

class ParticleMoveAndDistributeTask : public ITask{
public:
    ParticleMoveAndDistributeTask(AbstractBinningAlgorithmPtr pAlgo, ParticlePtrs pParticles, const unsigned int& dt);
    virtual ~ParticleMoveAndDistributeTask(){};
    
    //Override
    virtual void execute();
    
private:
    AbstractBinningAlgorithmPtr m_pAlgo;
    const unsigned int m_dt;
    ParticlePtrs m_pParticles;
};

#endif /* defined(__ParallelParticles__ParticleMoveAndDistributeTask__) */
