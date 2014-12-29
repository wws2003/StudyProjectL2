//
//  BinningAlgorithmMultithreadBatchImpl.h
//  ParallelParticles
//
//  Created by wws2003 on 8/14/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__BinningAlgorithmMultithreadBatchImpl__
#define __ParallelParticles__BinningAlgorithmMultithreadBatchImpl__

#include <iostream>
#include "TypeDefs.h"
#include "AbstractBinningAlgorithm.h"

class BinningAlgorithmMultithreadBatchImpl : public AbstractBinningAlgorithm {
public:
    BinningAlgorithmMultithreadBatchImpl(AbstractThreadPoolPtr pThreadPool);
    virtual ~BinningAlgorithmMultithreadBatchImpl();
    
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
    ITaskPtrs m_pApplyBinForceTasks;
    ITaskPtrs m_pClearBinTasks;
    ITaskPtrs m_pParticleMoveTasks;
    ITaskPtrs m_pParticleDistributeTask;
    AbstractThreadPoolPtr m_pThreadPool;
};

#endif /* defined(__ParallelParticles__BinningAlgorithmMultithreadBatchImpl__) */
