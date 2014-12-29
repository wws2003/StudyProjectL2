//
//  ParticlesExportResultPrintImpl.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticlesExportResultPrintImpl.h"
#include "common.h"
#include <fstream>
#include <iostream>

ParticlesExportResultPrintImpl::ParticlesExportResultPrintImpl(const char* outputFileName) : IParticlesExportResult(), m_outputFileName(outputFileName) {
    m_fStream.open(m_outputFileName, std::ios::out);
}

ParticlesExportResultPrintImpl::~ParticlesExportResultPrintImpl() {
    if(m_fStream.is_open())
        m_fStream.close();
}

//Override
void ParticlesExportResultPrintImpl::setBasicInfo(const unsigned int& particleNumber, const double& spaceWidth, const double& spaceHeight) {
    if(m_fStream.is_open()) {
        m_fStream << particleNumber << " " << spaceWidth << "\n";
    }
}

//Override
PP_ERR ParticlesExportResultPrintImpl::exportParticlesResult(const ParticlePtrs& particles) {
    if(!m_fStream.is_open())
    {
        return  ERR_EXPORT_RESULT_FAILED;
    }
    for (ParticlePtr pParticle : particles) {
        m_fStream << pParticle->x << " " << pParticle->y << "\n";
    }
    return ERR_NONE;
}