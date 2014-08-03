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
    
    //Override
    virtual void execute();
    
private:
    BinPtr m_pBin;
    ParticlePtr m_pParticle;
};


#endif /* defined(__ParallelParticles__BinApplyForceTask__) */
