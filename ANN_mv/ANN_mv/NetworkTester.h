//
//  NetworkTester.h
//  ANN_mv
//
//  Created by wws2003 on 10/28/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__NetworkTester__
#define __ANN_mv__NetworkTester__

#include <iostream>
#include "common.h"
#include "MultiLayerNetwork.h"
#include "PerceptronUnitSimpleSigmoidImpl.h"

class NetworkTester {
public:
    NetworkTester();
    virtual ~NetworkTester();
    
    void testForwardPropagate();
    
    void testUpdateDeltaTable();
    
private:
    void initLayersForTest();
    void initNetworkForTest();
    void initInputsForTest();
    void initExpectedOutputForTest();
    void initTargetValue();
    void initExpectedDeltaWeightTables();
    
    void initWeightTable(WeightTable& weightTable, ulong n, ulong m);
    
    void releaseLayersForTest();
    void releaseInputsForTest();
    void releaseNetworkForTest();
    void releaseExpectedDeltaWeightTables();
    
    void releaseWeightTable(WeightTable weightTable, ulong size);

    MultiLayerNetworkPtr m_pNetwork;
    InputsPtr m_pInputsForTest;

    LayerPtr m_pHiddenLayer;
    LayerPtr m_pOutputLayer;
    
    std::vector<PerceptronUnitSimpleSigmoidImpl*> m_pHiddenLayerPerceptronUnits;
    std::vector<PerceptronUnitSimpleSigmoidImpl*> m_pOutputLayerPerceptronUnits;
    
    Outputs m_expectedOutputs;
    
    Targets m_targets;
    
    WeightTable m_expectedDeltaWeightTableForOuputLayer;
    WeightTable m_expectedDeltaWeightTableForHiddenLayer;
};

#endif /* defined(__ANN_mv__NetworkTester__) */
