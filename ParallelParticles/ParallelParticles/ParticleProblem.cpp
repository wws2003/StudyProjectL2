//
//  ParticleProblem.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ParticleProblem.h"
#include "IParticlesExportResult.h"
#include "IParticlesInitiator.h"
#include "IParticleMoveAlgorithm.h"
#include "common.h"
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

const int ParticleProblem::DT = 5;
const int ParticleProblem::NSTEPS = 1000;
const long ParticleProblem::NAP_BETWEEN_STEP_IN_MILISECOND = 0;

#define NAP_BETWEEN_SLEEP_IN_NANOSECOND NAP_BETWEEN_STEP_IN_MILISECOND * 1000

ParticleProblem::ParticleProblem() : m_pExporter(NULL), m_pInitiator(NULL), m_pMoveAlgorithm(NULL){
    
}

ParticleProblem::~ParticleProblem() {
    for (unsigned int i = 0; i < m_pParticles.size(); i++) {
        delete m_pParticles[i];
    }
}

void ParticleProblem::setParticleInitiatorPtr(ParticlesInitiatorPtr pInitiator) {
    m_pInitiator = pInitiator;
}

void ParticleProblem::setParticleExportResult(ParticlesExportResultPtr pExporter) {
    m_pExporter = pExporter;
}

void ParticleProblem::setParticleMoveAlgorithmPtr(ParticleMoveAlgorithmPtr pMoveAlgorithm) {
    m_pMoveAlgorithm = pMoveAlgorithm;
}

PP_ERR ParticleProblem::solve() {
    double spaceWidth = 0;
    double spaceHeight = 0;
    double density = 0;
    
    if (!m_pInitiator || m_pInitiator->initParticles(m_pParticles, spaceWidth, spaceHeight, density) != ERR_NONE) {
        return ERR_INIT_FAILED;
    }
    if (!m_pExporter) {
        return ERR_INVALID_PARAMS;
    }
    m_pMoveAlgorithm->setParticles(m_pParticles, spaceWidth, spaceHeight, density);
    
    int t = 0;
    unsigned int i = 0;
    while (i < NSTEPS) {
        if (m_pMoveAlgorithm) {
            PP_ERR err = m_pMoveAlgorithm->moveParticles(DT);
            if (err != ERR_NONE) {
                return ERR_EXECUTE_FAILED;
            }
        }
        if (m_pExporter->exportParticlesResult(m_pParticles) != ERR_NONE) {
            return ERR_EXPORT_RESULT_FAILED;
        }
        if (NAP_BETWEEN_STEP_IN_MILISECOND > 0) {
            sleepBetweenStep();
        }
        i++;
        t += DT;
    }
    
    return ERR_NONE;
}

void ParticleProblem::sleepBetweenStep() const {
    struct timespec t1, t2;
    t1.tv_sec = 0;
    t1.tv_nsec = NAP_BETWEEN_SLEEP_IN_NANOSECOND;
    nanosleep(&t1, &t2);
}

