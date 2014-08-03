//
//  ParticleProblem.h
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ParallelParticles_ParticleProblem_h
#define ParallelParticles_ParticleProblem_h

#include "PPTypeDefs.h"

class ParticleProblem {
public:
    ParticleProblem();
    virtual ~ParticleProblem();
    
    void setParticleInitiatorPtr(ParticlesInitiatorPtr pInitiator);
    void setParticleExportResult(ParticlesExportResultPtr pExporter);
    void setParticleMoveAlgorithmPtr(ParticleMoveAlgorithmPtr pMoveAlgorithm);
    
    PP_ERR solve();
    
private:
    static const int DT;
    static const int NSTEPS;
    static const long NAP_BETWEEN_STEP_IN_MILISECOND;
    
    ParticlePtrs m_pParticles;
    ParticleMoveAlgorithmPtr m_pMoveAlgorithm;
    ParticlesInitiatorPtr m_pInitiator;
    ParticlesExportResultPtr m_pExporter;
    
    void sleepBetweenStep() const;
};

#endif
