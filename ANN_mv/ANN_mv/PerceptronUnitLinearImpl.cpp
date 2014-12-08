//
//  PerceptronUnitLinearImpl.cpp
//  ANN_mv
//
//  Created by wws2003 on 11/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PerceptronUnitLinearImpl.h"
#include <cmath>
#include <cassert>

PerceptronUnitLinearImpl::PerceptronUnitLinearImpl(const double learningRate) : m_learningRate(learningRate) {
    
}

PerceptronUnitLinearImpl::~PerceptronUnitLinearImpl() {
    
}

//@Override
void PerceptronUnitLinearImpl::calculateAndStoreOutput() {
    ulong size = m_pCurrentInputs->size();
    double net = 0;
    for (ulong i = 0; i < size; i++) {
        double input = (*m_pCurrentInputs)[i];
        double weight = (*m_incomeEdges[i]);
        assert(!isnan(input));
        assert(!isinf(input));
        assert(!isnan(weight));
        assert(!isinf(weight));
        net += input * weight;
    }
    m_currentOutput = net;
    assert(!isnan(m_currentOutput));
    assert(!isinf(m_currentOutput));
}

//@Override
void PerceptronUnitLinearImpl::calculateAndStoreErrorTerm(double target) {
    m_currentErrorTerm = target - m_currentOutput;
    assert(!isinf(m_currentErrorTerm));
    assert(!isnan(m_currentErrorTerm));
}

//@Override
void PerceptronUnitLinearImpl::calculateAndStoreErrorTerm(LayerPtr outerLayer) {
    ulong numberOfOutcomeUnits = outerLayer->size();
    double errorTerm = 0;
    for (ulong i = 0; i < numberOfOutcomeUnits; i++) {
        double outcomeWeight = *m_outcomeEdges[i];
        double outerErrorTerm = (*outerLayer)[i]->getErrorTerm();
        errorTerm += outerErrorTerm * outcomeWeight;
    }
    errorTerm = errorTerm * 1;
    assert(!isinf(errorTerm));
    assert(!isnan(errorTerm));
    m_currentErrorTerm = errorTerm;
}

//@Override
void PerceptronUnitLinearImpl::calculateUpdateDelta(double* deltaWeights) const {
    ulong numberOfIncomeWeights = m_incomeEdges.size();
    
    for (ulong i = 0; i < numberOfIncomeWeights; i++) {
        double input = (*m_pCurrentInputs)[i];
        deltaWeights[i] = m_learningRate * m_currentErrorTerm * input;
        assert(!isinf(deltaWeights[i]));
        assert(!isnan(deltaWeights[i]));
    }
}