//
//  ParticleExportResultAssembler.cpp
//  ParallelParticles
//
//  Created by wws2003 on 8/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticleExportResultAssembler.h"
#include "IParticlesExportResult.h"
#include "ParticlesExportResultPrintImpl.h"

ParticlesExportResultPtr ParticleExportResultAssembler::createInitiatorInstance() {
    return new ParticlesExportResultPrintImpl("output.txt");
}

void ParticleExportResultAssembler::destroyExportResultInstance(ParticlesExportResultPtr pInstance) {
    delete pInstance;
}