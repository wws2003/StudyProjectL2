//
//  BinApplyForceTask.h
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__BinApplyForceTask__
#define __ParallelParticles__BinApplyForceTask__

#include <iostream>
#include "PPTypeDefs.h"
#include "TypeDefs.h"
#include "ITask.h"

class BinApplyForceTask : public ITask {
public:
    BinApplyForceTask(BinPtr pBin, ParticlePtr pParticle);
    virtual ~BinApplyForceTask(){};
    
    //@Override
    void* operator new (size_t size) throw (std::bad_alloc);
    
    //@Override
    void operator delete(void* objectPtr);
    
    //Override
    virtual void execute();
    
    static void refreshPool();
    
private:
    BinPtr m_pBin;
    ParticlePtr m_pParticle;
    
    static ObjectPoolPtr g_pObjectPool;
};


#endif /* defined(__ParallelParticles__BinApplyForceTask__) */
