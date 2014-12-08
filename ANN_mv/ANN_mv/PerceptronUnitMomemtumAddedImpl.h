//
//  PerceptronUnitMomemtumAddedImpl.h
//  ANN_mv
//
//  Created by wws2003 on 10/20/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__PerceptronUnitMomemtumAddedImpl__
#define __ANN_mv__PerceptronUnitMomemtumAddedImpl__

#include <iostream>
#include "PerceptronUnitSimpleSigmoidImpl.h"

class PerceptronUnitMomemtumAddedImpl : public PerceptronUnitSimpleSigmoidImpl {
public:
    PerceptronUnitMomemtumAddedImpl(const double learningRate, const double momentum);
    virtual ~PerceptronUnitMomemtumAddedImpl();
    
    //@Override
    virtual void calculateUpdateDelta(double* deltaWeights);
    
private:
    double m_momentum;
    double* m_lastDeltaWeights;
};

#endif /* defined(__ANN_mv__PerceptronUnitMomemtumAddedImpl__) */
