//
//  PerceptronUnitSimpleSigmoidImpl.h
//  ANN_mv
//
//  Created by wws2003 on 10/20/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__PerceptronUnitSimpleSigmoidImpl__
#define __ANN_mv__PerceptronUnitSimpleSigmoidImpl__

#include <iostream>
#include "common.h"
#include "AbstractPerceptronUnit.h"

class PerceptronUnitSimpleSigmoidImpl : public AbstractPerceptronUnit {
public:
    PerceptronUnitSimpleSigmoidImpl(const double learningRate);
    virtual ~PerceptronUnitSimpleSigmoidImpl();
   
    //@Override
    virtual void calculateAndStoreOutput();
    
    //@Override
    virtual void calculateAndStoreErrorTerm(double target);
    
    //@Override
    virtual void calculateAndStoreErrorTerm(LayerPtr outerLayer);
    
    //@Override
    virtual void calculateUpdateDelta(double* deltaWeights) const;
    
private:
    const double m_learningRate;
};

#endif /* defined(__ANN_mv__PerceptronUnitSimpleSigmoidImpl__) */
