//
//  PerceptronUnitMomemtumAddedImpl.cpp
//  ANN_mv
//
//  Created by wws2003 on 10/20/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PerceptronUnitMomemtumAddedImpl.h"

PerceptronUnitMomemtumAddedImpl::PerceptronUnitMomemtumAddedImpl(const double learningRate, const double momentum) : PerceptronUnitSimpleSigmoidImpl(learningRate), m_momentum(momentum), m_lastDeltaWeights(NULL) {
    
}

PerceptronUnitMomemtumAddedImpl::~PerceptronUnitMomemtumAddedImpl() {
    if (m_lastDeltaWeights != NULL) {
        delete m_lastDeltaWeights;
    }
}

//@Override
void PerceptronUnitMomemtumAddedImpl::calculateUpdateDelta(double* deltaWeights) {
    ulong numberOfIncomeWeights = m_incomeEdges.size();
    
    if (m_lastDeltaWeights == NULL) {
        m_lastDeltaWeights = new double[m_incomeEdges.size()];
    }
    PerceptronUnitSimpleSigmoidImpl::calculateUpdateDelta(deltaWeights);
    
    for (ulong i = 0; i < numberOfIncomeWeights; i++) {
        deltaWeights[i] += m_lastDeltaWeights[i] * m_momentum;
        m_lastDeltaWeights[i] = deltaWeights[i];
    }
}