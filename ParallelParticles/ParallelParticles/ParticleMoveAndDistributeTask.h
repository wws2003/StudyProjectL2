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
    ParticleMoveAndDistributeTask(AbstractBinningAlgorithmPtr pAlgo, const ParticlePtrs& pParticles, const unsigned int& dt, const unsigned int& startIndex = 0, const unsigned int& endIndex = 0);
    virtual ~ParticleMoveAndDistributeTask(){};
    
    //@Override
    void* operator new (size_t size) throw (std::bad_alloc);
    
    //@Override
    void operator delete(void* objectPtr);
    
    //Override
    virtual void execute();
    
    static void refreshPool();
    
private:
    AbstractBinningAlgorithmPtr m_pAlgo;
    const unsigned int m_dt;
    const unsigned int m_startIndex;
    const unsigned int m_endIndex;
    ParticlePtrs m_pParticles;
    
    static ObjectPoolPtr g_pObjectPool;
};

#endif /* defined(__ParallelParticles__ParticleMoveAndDistributeTask__) */
