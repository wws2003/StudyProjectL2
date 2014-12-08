//
//  :
//  ANN_mv
//
//  Created by wws2003 on 10/21/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PerceptronUnitWeightPenaltyImpl.h"

PerceptronUnitWeightPenaltyImpl::PerceptronUnitWeightPenaltyImpl(const double learningRate, const double weightPenaltyRate) : PerceptronUnitSimpleSigmoidImpl(learningRate), m_weightPenaltyRate(weightPenaltyRate) {
    
}

PerceptronUnitWeightPenaltyImpl::~PerceptronUnitWeightPenaltyImpl() {
    
}

void PerceptronUnitWeightPenaltyImpl::calculateUpdateDelta(double* deltaWeights) {
    ulong numberOfIncomeWeights = m_incomeEdges.size();
    PerceptronUnitSimpleSigmoidImpl::calculateUpdateDelta(deltaWeights);
    
    for (ulong i = 0; i < numberOfIncomeWeights; i++) {
        double weight = *(m_incomeEdges[i]);
        deltaWeights[i] -= 2 * m_weightPenaltyRate * weight;
    }
}