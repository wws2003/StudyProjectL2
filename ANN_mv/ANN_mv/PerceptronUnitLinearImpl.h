//
//  PerceptronUnitLinearImpl.h
//  ANN_mv
//
//  Created by wws2003 on 11/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__PerceptronUnitLinearImpl__
#define __ANN_mv__PerceptronUnitLinearImpl__

#include <iostream>
#include "common.h"
#include "AbstractPerceptronUnit.h"

class PerceptronUnitLinearImpl: public AbstractPerceptronUnit {
public:
    PerceptronUnitLinearImpl(const double learningRate);
    virtual ~PerceptronUnitLinearImpl();
    
    //@Override
    virtual void calculateAndStoreOutput();
    
    //@Override
    virtual void calculateAndStoreErrorTerm(double target);
    
    //@Override
    virtual void calculateAndStoreErrorTerm(LayerPtr outerLayer);
    
    //@Override
    virtual void calculateUpdateDelta(double* deltaWeights) const;
    
protected:
    const double m_learningRate;
};

#endif /* defined(__ANN_mv__PerceptronUnitLinearImpl__) */
