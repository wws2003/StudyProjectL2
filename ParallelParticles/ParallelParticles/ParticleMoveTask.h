//
//  ParticleMoveTask.h
//  ParallelParticles
//
//  Created by wws2003 on 8/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__ParticleMoveTask__
#define __ParallelParticles__ParticleMoveTask__

#include <iostream>
#include "PPTypeDefs.h"
#include "TypeDefs.h"
#include "ITask.h"

class ParticleMoveTask : public ITask {
public:
    ParticleMoveTask(const unsigned int& dt, const double& spaceWidth, const double& spaceHeight, ParticlePtr& pMovingParticle);
    virtual ~ParticleMoveTask(){};
    
    //@Override
    void* operator new (size_t size) throw (std::bad_alloc);
    
    //@Override
    void operator delete(void* objectPtr);
    
    //Override
    virtual void execute();
    
    static void refreshPool();
    
private:
    const unsigned int m_dt;
    const double m_spaceSize;
    ParticlePtr m_pMovingParticle;
    
    static ObjectPoolPtr g_pObjectPool;

};

#endif /* defined(__ParallelParticles__ParticleMoveTask__) */
