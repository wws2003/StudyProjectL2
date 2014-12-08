//
//  PerceptronUnitFactory.cpp
//  ANN_mv
//
//  Created by wws2003 on 10/21/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PerceptronUnitFactory.h"
#include "PerceptronUnitDummyImpl.h"
#include "PerceptronUnitWeightPenaltyImpl.h"
#include "Util.hpp"

#define LEARNING_RATE 0.005
#define WEIGHT_PENALTY_RATE 0.02

PerceptronUnitFactory* PerceptronUnitFactory::g_pInstance = NULL;

PerceptronUnitFactory* PerceptronUnitFactory::getInstance() {
    if (g_pInstance == NULL) {
        g_pInstance = new PerceptronUnitFactory();
    }
    return g_pInstance;
}

void PerceptronUnitFactory::releaseInstance() {
    if (g_pInstance != NULL) {
        delete g_pInstance;
        g_pInstance = NULL;
    }
}

PerceptronUnitFactory::~PerceptronUnitFactory() {
    releasePool();
}


AbstractPerceptronUnitPtr PerceptronUnitFactory::createPerceptronUnit(PERCEPTRON_UNIT_TYPE type) {
    switch (type) {
        case DUMMY:
        {
            PerceptronUnitDummyImpl* pPerceptronUnit = new PerceptronUnitDummyImpl();
            m_pPerceptronUnitDummyPool.push_back(pPerceptronUnit);
            return pPerceptronUnit;
        }
        case WEIGHT_PENALTY:
        {
            PerceptronUnitWeightPenaltyImpl* pWeightPenaltyPerceptronUnit = new PerceptronUnitWeightPenaltyImpl(LEARNING_RATE, WEIGHT_PENALTY_RATE);
            m_pPerceptronUnitWeightPenaltyPool.push_back(pWeightPenaltyPerceptronUnit);
            return pWeightPenaltyPerceptronUnit;
        }
        case SIMPLE_SIGMOID:
        {
            PerceptronUnitSimpleSigmoidImpl* pSimpleSigmoidPerceptronUnit = new PerceptronUnitSimpleSigmoidImpl(LEARNING_RATE);
            m_pPerceptronUnitSimpleSigmoidPool.push_back(pSimpleSigmoidPerceptronUnit);
            return pSimpleSigmoidPerceptronUnit;
        }
        case LINEAR:
        {
            PerceptronUnitLinearImpl* pLinearPerceptronUnit = new PerceptronUnitLinearImpl(LEARNING_RATE);
            m_pPerceptronUnitLinearPool.push_back(pLinearPerceptronUnit);
            return pLinearPerceptronUnit;
        }
        case LINEAR_WEIGHT_PENALTY:
        {
            PerceptronUnitLinearWeightPenaltyImpl* pLinearWeightPenaltyPerceptronUnit = new PerceptronUnitLinearWeightPenaltyImpl(LEARNING_RATE, WEIGHT_PENALTY_RATE);
            m_pPerceptronUnitLinearWeightPenaltyImpl.push_back(pLinearWeightPenaltyPerceptronUnit);
            return pLinearWeightPenaltyPerceptronUnit;
        }
        default:
            return NULL;
    }
}

void PerceptronUnitFactory::releasePool() {
    Util::releaseVector<PerceptronUnitDummyImpl>(m_pPerceptronUnitDummyPool);
    Util::releaseVector<PerceptronUnitSimpleSigmoidImpl>(m_pPerceptronUnitSimpleSigmoidPool);
    Util::releaseVector<PerceptronUnitWeightPenaltyImpl>(m_pPerceptronUnitWeightPenaltyPool);
}
