//
//  Tester.h
//  ANN_mv
//
//  Created by wws2003 on 10/27/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__Tester__
#define __ANN_mv__Tester__

#include <iostream>
#include "common.h"
#include "PerceptronUnitSimpleSigmoidImpl.h"
#include "PerceptronUnitDummyForTestImpl.h"

class PerceptronTester {
public:
    PerceptronTester();
    virtual ~PerceptronTester();
    
    void testPerceptronUnitSimpleSigmoidImpl(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit);
    
private:
    void initIncomeEdgesForTest();
    void initOutcomeEdgesForTest();
    void initOutputLayerForTest();
    void initInputsForTest();
    void initTarget();
    void initExpectedValues();
    
    void testPerceptronUnitSimpleSigmoidImplOutput(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit);
    void testPerceptronUnitSimpleSigmoidImplErrorTerm(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit);
    
    void testPerceptronUnitSimpleSigmoidImplOutputLayerErrorTerm(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit);
    void testPerceptronUnitSimpleSigmoidImplHiddenLayerErrorTerm(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit);
    
    Edges m_incomeEdgesForTest;
    Edges m_outcomeEdgesForTest;
    
    std::vector<PerceptronUnitDummyForTestImpl*> m_pDummyOutputUnits;
    LayerPtr m_pOuputLayer;
    InputsPtr m_pInputsForTest;
    
    double m_target;
    double m_expectedOutput;
    double m_expectedOutputLayerErrorTerm;
    double m_expectedHiddenLayerErrorTerm;
    
    void releaseIncomeEdgesForTest();
    void releaseOutcomeEdgesForTest();
    void releaseOutputLayerForTest();
    void releaseInputsForTest();
    
};


#endif /* defined(__ANN_mv__Tester__) */
