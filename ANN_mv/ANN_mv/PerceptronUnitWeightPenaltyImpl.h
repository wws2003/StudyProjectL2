//
//  PerceptronUnitWeightPenaltyImpl.h
//  ANN_mv
//
//  Created by wws2003 on 10/21/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__PerceptronUnitWeightPenaltyImpl__
#define __ANN_mv__PerceptronUnitWeightPenaltyImpl__

#include <iostream>
#include "common.h"
#include "PerceptronUnitSimpleSigmoidImpl.h"

class PerceptronUnitWeightPenaltyImpl : public PerceptronUnitSimpleSigmoidImpl {
public:
    PerceptronUnitWeightPenaltyImpl(const double learningRate, const double weightPenaltyRate);
    virtual ~PerceptronUnitWeightPenaltyImpl();
    
    //@Override
    virtual void calculateUpdateDelta(double* deltaWeights);
    
private:
    double m_weightPenaltyRate;
};

#endif /* defined(__ANN_mv__PerceptronUnitWeightPenaltyImpl__) */
