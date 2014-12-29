//
//  ParticlesExportResultPrintImpl.h
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__ParticlesExportResultPrintImpl__
#define __ParallelParticles__ParticlesExportResultPrintImpl__

#include <iostream>
#include <fstream>
#include "IParticlesExportResult.h"

class ParticlesExportResultPrintImpl : public IParticlesExportResult {
public:
    ParticlesExportResultPrintImpl(const char* outputFileName);
    virtual ~ParticlesExportResultPrintImpl();
    
    //Override
    void setBasicInfo(const unsigned int& particleNumber, const double& spaceWidth, const double& spaceHeight);
    
    //Override
    virtual PP_ERR exportParticlesResult(const ParticlePtrs& particles);
    
private:
    const char* m_outputFileName;
    std::fstream m_fStream;
};

#endif /* defined(__ParallelParticles__ParticlesExportResultPrintImpl__) */
