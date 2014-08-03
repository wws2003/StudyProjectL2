//
//  AbstractBinningAlgorithm.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractBinningAlgorithm.h"
#include "Bin.h"
#include "common.h"
#include <cmath>

AbstractBinningAlgorithm::AbstractBinningAlgorithm() : m_binSize(-1), m_numberOfBinsOnWidth(-1), m_numberOfBinsOnHeight(-1) {

}

AbstractBinningAlgorithm::~AbstractBinningAlgorithm() {
    initBins();
}

void AbstractBinningAlgorithm::initBins() {
    m_binSize = -1;
    m_numberOfBinsOnWidth = -1;
    m_numberOfBinsOnHeight = -1;
    for (auto pBin : m_pBins) {
        if (pBin) {
            delete pBin;
        }
    }
    m_pBins.clear();
}

//Override
void AbstractBinningAlgorithm::setParticles(const ParticlePtrs& particles, const double& spaceWidth, const double& spaceHeight, const double& density) {
    m_binSize = 1 / sqrt(density);
    m_numberOfBinsOnWidth = spaceWidth / m_binSize;
    m_numberOfBinsOnHeight = spaceHeight / m_binSize;
    
    int numberOfBins = m_numberOfBinsOnHeight * m_numberOfBinsOnWidth;
    for (int i = 0; i < numberOfBins; i++) {
        int y = numberOfBins / m_numberOfBinsOnWidth;
        int x = numberOfBins % m_numberOfBinsOnWidth;
        m_pBins.push_back(new Bin(x, y));
    }
    
    onMoveAndPushParticleToBins(particles, 0);
}

BinPtr AbstractBinningAlgorithm::findBinByPosition(const double& x, const double& y) const {
    if (!isContaningData()) {
        return NULL;
    }
    const int binX = x / m_binSize;
    const int binY = y / m_binSize;
    
    return isValidBinPosition(binX, binY) ? m_pBins[calculateBinIndex(binX, binY)] : NULL;
}

//Override
PP_ERR AbstractBinningAlgorithm::moveParticles(unsigned int dt) {
    ParticlePtrs pParticles;
    getParticlesFromBins(pParticles);
    
    for (ParticlePtrs::iterator pIter = pParticles.begin(); pIter != pParticles.end(); pIter++) {
        ParticlePtr pParticle = *pIter;
        BinPtrs pBins;
        findAdjBins(pParticle, pBins);
        
        for (BinPtrs::iterator pBIter = pBins.begin(); pBIter != pBins.end(); pBIter++) {
            BinPtr pBin = *pBIter;
            onApplyBinForceToOnParticle(pBin, pParticle);
        }
        
        onParticleAppliedForce(pParticle);
    }
    for (BinPtrs::iterator pBIter = m_pBins.begin(); pBIter != m_pBins.end(); pBIter++) {
        BinPtr pBin = *pBIter;
        onClearBin(pBin);
    }
    
    onBinsCleared();
    
    onMoveAndPushParticleToBins(pParticles, dt);
    return ERR_NONE;
}

void AbstractBinningAlgorithm::findAdjBins(const ParticlePtr pParticle, BinPtrs& pBins) const{
    pBins.clear();
    const int binX = pParticle->x / m_binSize;
    const int binY = pParticle->y / m_binSize;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            const int x = binX + dx;
            const int y = binY + dy;
            if (isValidBinPosition(x, y)) {
                pBins.push_back(pBins[calculateBinIndex(x, y)]);
            }
        }
    }
}


void AbstractBinningAlgorithm::getSpaceSize(double& w, double&h) const{
    w = m_numberOfBinsOnWidth * m_binSize;
    h = m_numberOfBinsOnHeight * m_binSize;
}

bool AbstractBinningAlgorithm::isContaningData() const {
    return  m_binSize != -1;
}

bool AbstractBinningAlgorithm::isValidBinPosition(const int& binX, const int& binY) const {
    if (binX < 0 || binX >= m_numberOfBinsOnWidth) {
        return false;
    }
    if (binY < 0 || binY >= m_numberOfBinsOnHeight) {
        return false;
    }
    return true;
}

int AbstractBinningAlgorithm::calculateBinIndex(const int& binX, const int& binY) const {
    return binX * m_numberOfBinsOnWidth + binY;
}

void AbstractBinningAlgorithm::getParticlesFromBins(ParticlePtrs pParticles) const {
    pParticles.clear();
    for (BinPtr pBin : m_pBins) {
        pParticles.insert(pParticles.end(), pBin->getParticles().begin(), pBin->getParticles().end());
    }
}
