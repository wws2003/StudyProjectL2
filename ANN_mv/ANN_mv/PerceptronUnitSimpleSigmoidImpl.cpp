//
//  PerceptronUnitSimpleSigmoidImpl.cpp
//  ANN_mv
//
//  Created by wws2003 on 10/20/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PerceptronUnitSimpleSigmoidImpl.h"
#include <cmath>

PerceptronUnitSimpleSigmoidImpl::PerceptronUnitSimpleSigmoidImpl(const double learningRate) :  AbstractPerceptronUnit(), m_learningRate(learningRate) {
    
}

PerceptronUnitSimpleSigmoidImpl::~PerceptronUnitSimpleSigmoidImpl() {
    
}

//@Override
void PerceptronUnitSimpleSigmoidImpl::calculateAndStoreOutput() {
    ulong size = m_pCurrentInputs->size();
    double v = 0;
    for (ulong i = 0; i < size; i++) {
        double input = (*m_pCurrentInputs)[i];
        double weight = (*m_incomeEdges[i]);
        v += input * weight;
    }
    m_currentOutput = 1 / (1 + exp(-v));
}

//@Override
void PerceptronUnitSimpleSigmoidImpl::calculateAndStoreErrorTerm(double target) {
    m_currentErrorTerm = (target - m_currentOutput) * m_currentOutput * (1 - m_currentOutput);
}

//@Override
void PerceptronUnitSimpleSigmoidImpl::calculateAndStoreErrorTerm(LayerPtr outerLayer) {
    ulong numberOfOutcomeUnits = outerLayer->size();
    double errorTerm = 0;
    for (ulong i = 0; i < numberOfOutcomeUnits; i++) {
        double outcomeWeight = *m_outcomeEdges[i];
        double outerErrorTerm = (*outerLayer)[i]->getErrorTerm();
        errorTerm += outerErrorTerm * outcomeWeight;
    }
    errorTerm = errorTerm * (1 - m_currentOutput) * m_currentOutput;
    m_currentErrorTerm = errorTerm;
}

//@Override
void PerceptronUnitSimpleSigmoidImpl::calculateUpdateDelta(double* deltaWeights) const {
    ulong numberOfIncomeWeights = m_incomeEdges.size();

    for (ulong i = 0; i < numberOfIncomeWeights; i++) {
        double input = (*m_pCurrentInputs)[i];
        deltaWeights[i] = m_learningRate * m_currentErrorTerm * input;
    }
}
