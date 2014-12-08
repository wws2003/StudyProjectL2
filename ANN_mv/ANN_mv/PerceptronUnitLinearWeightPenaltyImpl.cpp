//
//  PerceptronUnitLinearWeightPenaltyImpl.cpp
//  ANN_mv
//
//  Created by wws2003 on 11/12/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PerceptronUnitLinearWeightPenaltyImpl.h"

PerceptronUnitLinearWeightPenaltyImpl::PerceptronUnitLinearWeightPenaltyImpl(const double learningRate, const double weightPenaltyRate) : PerceptronUnitLinearImpl(learningRate), m_weightPenaltyRate(weightPenaltyRate) {
    
}

PerceptronUnitLinearWeightPenaltyImpl::~PerceptronUnitLinearWeightPenaltyImpl() {
    
}

//@Override
void PerceptronUnitLinearWeightPenaltyImpl::calculateUpdateDelta(double* deltaWeights) const {
    ulong numberOfIncomeWeights = m_incomeEdges.size();
    
    for (ulong i = 0; i < numberOfIncomeWeights; i++) {
        double input = (*m_pCurrentInputs)[i];
        deltaWeights[i] = m_learningRate * m_currentErrorTerm * input;
    }
    
    for (ulong i = 0; i < numberOfIncomeWeights; i++) {
        double weight = *(m_incomeEdges[i]);
        deltaWeights[i] -= 2 * m_weightPenaltyRate * weight;
    }
}