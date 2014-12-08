//
//  PerceptronUnitLinearWeightPenaltyImpl.h
//  ANN_mv
//
//  Created by wws2003 on 11/12/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__PerceptronUnitLinearWeightPenaltyImpl__
#define __ANN_mv__PerceptronUnitLinearWeightPenaltyImpl__

#include <iostream>
#include "common.h"
#include "PerceptronUnitLinearImpl.h"

class PerceptronUnitLinearWeightPenaltyImpl : public PerceptronUnitLinearImpl {
public:
    PerceptronUnitLinearWeightPenaltyImpl(const double learningRate, const double weightPenaltyRate);
    virtual ~PerceptronUnitLinearWeightPenaltyImpl();
    
    //@Override
    virtual void calculateUpdateDelta(double* deltaWeights) const;
    
private:
    const double m_weightPenaltyRate;
};


#endif /* defined(__ANN_mv__PerceptronUnitLinearWeightPenaltyImpl__) */
