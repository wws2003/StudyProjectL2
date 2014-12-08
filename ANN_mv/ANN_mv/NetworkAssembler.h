//
//  NetworkAssembler.h
//  ANN_mv
//
//  Created by wws2003 on 11/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__NetworkAssembler__
#define __ANN_mv__NetworkAssembler__

#include <iostream>
#include "common.h"
#include "MultiLayerNetwork.h"
#include "PerceptronUnitFactory.h"

class NetworkAssembler {
public:
    NetworkAssembler(int numberOfHiddenUnit, int numberOfOutputUnit, PERCEPTRON_UNIT_TYPE hiddenUnitType, PERCEPTRON_UNIT_TYPE outputUnitType);
    virtual ~NetworkAssembler();
    
    void assembleNetwork(MultiLayerNetworkPtr pNetwork, int numberOfInputs);
    
private:
    const int m_numberOfHiddenUnit;
    const int m_numberOfOutputUnit;
    const PERCEPTRON_UNIT_TYPE m_hiddenUnitType;
    const PERCEPTRON_UNIT_TYPE m_outputUnitType;
    
    PerceptronUnitFactory* m_pPerceptronFactory;
    
    Layer m_hiddenLayer;
    Layer m_outputLayer;
    
    void initHiddenLayer();
    
    void initOutputLayer();
    
    void releaseLayer(Layer& layer);
};

#endif /* defined(__ANN_mv__NetworkAssembler__) */
