//
//  ParticleExportResultAssembler.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticlesExportResultAssembler.h"
#include "IParticlesExportResult.h"
#include "ParticlesExportResultPrintImpl.h"

ParticlesExportResultPtr ParticlesExportResultAssembler::createInitiatorInstance() {
    return new ParticlesExportResultPrintImpl("output.txt");
}

void ParticlesExportResultAssembler::destroyExportResultInstance(ParticlesExportResultPtr pInstance) {
    delete pInstance;
}