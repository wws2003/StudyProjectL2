//
//  AbstractPerceptronUnit.h
//  ANN_mv
//
//  Created by wws2003 on 10/20/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__AbstractPerceptronUnit__
#define __ANN_mv__AbstractPerceptronUnit__

#include <iostream>
#include "common.h"

class AbstractPerceptronUnit {
public:
    AbstractPerceptronUnit();
    virtual ~AbstractPerceptronUnit();
   
    virtual void inline addIncomeEdge(const Edge edge){m_incomeEdges.push_back(edge);};
    virtual void inline addOutcomeEdge(const Edge edge){m_outcomeEdges.push_back(edge);};
    virtual void inline setInputs(InputsPtr pInputs){m_pCurrentInputs = pInputs;};
    
    virtual void calculateAndStoreOutput() = 0;
    virtual double inline getOutput() const {return m_currentOutput;};
    
    virtual void calculateAndStoreErrorTerm(double target) = 0;
    virtual void calculateAndStoreErrorTerm(LayerPtr outerLayer) = 0;
    virtual double inline getErrorTerm() const {return m_currentErrorTerm;};
    
    virtual void calculateUpdateDelta(double* deltaWeights) const = 0;
    
protected:
    double m_currentOutput;
    double m_currentErrorTerm;
    
    InputsPtr m_pCurrentInputs;
    
    Edges m_incomeEdges;
    Edges m_outcomeEdges;
};

#endif /* defined(__ANN_mv__AbstractPerceptronUnit__) */
