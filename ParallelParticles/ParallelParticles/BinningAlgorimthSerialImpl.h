//
//  BinningAlgorimthSerialImpl.h
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__BinningAlgorimthSerialImpl__
#define __ParallelParticles__BinningAlgorimthSerialImpl__

#include <iostream>
#include "TypeDefs.h"
#include "AbstractBinningAlgorithm.h"

class BinningAlgorithmSerialImpl : public AbstractBinningAlgorithm {
public:
    BinningAlgorithmSerialImpl();
    virtual ~BinningAlgorithmSerialImpl();
    
protected:
    //Override
    virtual void onApplyBinForceToOnParticle(BinPtr pBin, ParticlePtr pParticle);
    
    //Override
    virtual void onParticleAppliedForce(ParticlePtr pParticle);
    
    //Override
    virtual void onClearBin(BinPtr pBin);
    
    //Override
    virtual void onBinsCleared();
    
    //Override
    virtual void onMoveAndPushParticleToBins(ParticlePtrs pParticles, unsigned int dt);
};

#endif /* defined(__ParallelParticles__BinningAlgorimthSerialImpl__) */
