//
//  PerceptronUnitDummyImpl.h
//  ANN_mv
//
//  Created by wws2003 on 10/21/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__PerceptronUnitDummyImpl__
#define __ANN_mv__PerceptronUnitDummyImpl__

#include <iostream>
#include "common.h"
#include "AbstractPerceptronUnit.h"

class PerceptronUnitDummyImpl : public AbstractPerceptronUnit {
public:
    
    //@Override
    virtual double inline getOutput() const {return 1;};
    
    //@Override
    virtual double inline getErrorTerm() const {return 0;}
    
    //The below method do nothing at all
    
    //@Override
    virtual void inline addIncomeEdge(const Edge edge){};
    
    //@Override
    virtual void inline addOutcomeEdge(const Edge edge){};
    
    //@Override
    virtual void inline setInputs(InputsPtr pInputs){};
    
    //@Override
    virtual void calculateAndStoreOutput() {};
    
    //@Override
    virtual void calculateAndStoreErrorTerm(double target) {};
    
    //@Override
    virtual void calculateAndStoreErrorTerm(LayerPtr outerLayer) {};
    
    //@Override
    virtual void calculateUpdateDelta(double* deltaWeights) const {};
};

#endif /* defined(__ANN_mv__PerceptronUnitDummyImpl__) */
