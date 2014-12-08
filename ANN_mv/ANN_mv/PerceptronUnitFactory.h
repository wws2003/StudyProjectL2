//
//  PerceptronUnitFactory.h
//  ANN_mv
//
//  Created by wws2003 on 10/21/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__PerceptronUnitFactory__
#define __ANN_mv__PerceptronUnitFactory__

#include <iostream>
#include "common.h"
#include "PerceptronUnitDummyImpl.h"
#include "PerceptronUnitSimpleSigmoidImpl.h"
#include "PerceptronUnitWeightPenaltyImpl.h"
#include "PerceptronUnitLinearImpl.h"
#include "PerceptronUnitLinearWeightPenaltyImpl.h"

class PerceptronUnitFactory {
public:
    static PerceptronUnitFactory* getInstance();
    static void releaseInstance();
    
    virtual ~PerceptronUnitFactory();
    
    AbstractPerceptronUnitPtr createPerceptronUnit(PERCEPTRON_UNIT_TYPE type);
    
    void releasePool();
    
private:
    PerceptronUnitFactory(){};
    
    static PerceptronUnitFactory* g_pInstance;
    
    std::vector<PerceptronUnitDummyImpl*> m_pPerceptronUnitDummyPool;
    std::vector<PerceptronUnitWeightPenaltyImpl*> m_pPerceptronUnitWeightPenaltyPool;
    std::vector<PerceptronUnitSimpleSigmoidImpl*> m_pPerceptronUnitSimpleSigmoidPool;
    std::vector<PerceptronUnitLinearImpl*> m_pPerceptronUnitLinearPool;
    std::vector<PerceptronUnitLinearWeightPenaltyImpl*> m_pPerceptronUnitLinearWeightPenaltyImpl;
};

#endif /* defined(__ANN_mv__PerceptronUnitFactory__) */
