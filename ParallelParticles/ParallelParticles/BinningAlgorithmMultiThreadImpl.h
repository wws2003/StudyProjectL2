//
//  BinningAlgorithmMultiThreadImpl.h
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__BinningAlgorithmMultiThreadImpl__
#define __ParallelParticles__BinningAlgorithmMultiThreadImpl__

#include <iostream>
#include "TypeDefs.h"
#include "AbstractBinningAlgorithm.h"

class BinningAlgorithmMultiThreadImpl : public  AbstractBinningAlgorithm {
public:
    BinningAlgorithmMultiThreadImpl(AbstractThreadPoolPtr pThreadPool);
    virtual ~BinningAlgorithmMultiThreadImpl();
    
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
    virtual void onMoveParticle(ParticlePtr pParticle, unsigned int dt);
    
    //Override
    virtual void onDistributeParticleToBin(const ParticlePtrs pParticles);
    
private:
    AbstractThreadPoolPtr m_pThreadPool;
};

#endif /* defined(__ParallelParticles__BinningAlgorithmMultiThreadImpl__) */
