//
//  Bin.h
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__Bin__
#define __ParallelParticles__Bin__

#include <iostream>
#include "PPTypeDefs.h"

class Bin {
public:
    Bin(int i, int j);
    virtual ~Bin();
    
    void addParticle(ParticlePtr pParticle);
    void applyForceToOneParticle(ParticlePtr pParticle);
    void clear();
    const ParticlePtrs& getParticles() const;
    
private:
    int m_i;
    int m_j;
    ParticlePtrs m_pParticles;
    
};

#endif /* defined(__ParallelParticles__Bin__) */
