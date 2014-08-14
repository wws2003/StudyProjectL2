//
//  AbstractBinningAlgorithm.h
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__AbstractBinningAlgorithm__
#define __ParallelParticles__AbstractBinningAlgorithm__

#include <iostream>
#include "PPTypeDefs.h"
#include "IParticleMoveAlgorithm.h"

class AbstractBinningAlgorithm : public IParticleMoveAlgorithm{
public:
    AbstractBinningAlgorithm();
    virtual ~AbstractBinningAlgorithm();
    
    //Override
    virtual void setParticles(const ParticlePtrs& particles, const double& spaceWidth, const double& spaceHeight, const double& density);
    
    //Override
    virtual PP_ERR moveParticles(unsigned int dt);
    
    BinPtr findBinByPosition(const double& x, const double& y) const;
    void getSpaceSize(double& w, double&h) const;
    
protected:
    void initBins();
    
    virtual void onApplyBinForceToOnParticle(BinPtr pBin, ParticlePtr pParticle) = 0;
    virtual void onParticleAppliedForce(ParticlePtr pParticle) = 0;
    virtual void onClearBin(BinPtr pBin) = 0;
    virtual void onBinsCleared() = 0;
    
    virtual void onMoveParticle(ParticlePtr pParticle, unsigned int dt) = 0;
    virtual void onDistributeParticleToBin(const ParticlePtrs pParticles) = 0;
    
    virtual void findAdjBins(const ParticlePtr pParticle, BinPtrs& pBins) const;
    
private:
    double m_binSize;
    unsigned int m_numberOfBinsOnWidth;
    unsigned int m_numberOfBinsOnHeight;
    BinPtrs m_pBins;

    bool isContaningData() const;
    bool isValidBinPosition(const int& binX, const int& binY) const;
    int calculateBinIndex(const int& binX, const int& binY) const;
    void getParticlesFromBins(ParticlePtrs& pParticles) const;
};

#endif /* defined(__ParallelParticles__AbstractBinningAlgorithm__) */
