//
//  Bin.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "Bin.h"
#include "common.h"

Bin::Bin(int i, int j) : m_i(i), m_j(j) {
    
}

Bin::~Bin() {
    
}

void Bin::addParticle(ParticlePtr pParticle) {
    m_pParticles.push_back(pParticle);
}

void Bin::applyForceToOneParticle(ParticlePtr pParticle) {
    for (ParticlePtrs::iterator pIter = m_pParticles.begin(); pIter != m_pParticles.end(); pIter++) {
        ParticlePtr pNeighbour = *pIter;
        apply_force(*pParticle, *pNeighbour);
    }
}

void Bin::clear() {
    m_pParticles.clear();
}

const ParticlePtrs& Bin::getParticles() const {
    return  m_pParticles;
}