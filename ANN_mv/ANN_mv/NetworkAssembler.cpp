//
//  NetworkAssembler.cpp
//  ANN_mv
//
//  Created by wws2003 on 11/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "NetworkAssembler.h"
#include "PerceptronUnitFactory.h"

NetworkAssembler::NetworkAssembler(int numberOfHiddenUnit, int numberOfOutputUnit, PERCEPTRON_UNIT_TYPE hiddenUnitType, PERCEPTRON_UNIT_TYPE outputUnitType) : m_numberOfHiddenUnit(numberOfHiddenUnit), m_numberOfOutputUnit(numberOfOutputUnit), m_hiddenUnitType(hiddenUnitType), m_outputUnitType(outputUnitType) {
    m_pPerceptronFactory = PerceptronUnitFactory::getInstance();
    initHiddenLayer();
    initOutputLayer();
}

NetworkAssembler::~NetworkAssembler() {
    releaseLayer(m_hiddenLayer);
    releaseLayer(m_outputLayer);
    PerceptronUnitFactory::releaseInstance();
}

void NetworkAssembler::assembleNetwork(MultiLayerNetworkPtr pNetwork, int numberOfInputs) {
    pNetwork->setNumberOfInputUnits(numberOfInputs);
    pNetwork->setHiddenLayerPtr(&m_hiddenLayer);
    pNetwork->setOutputLayerPtr(&m_outputLayer);
    pNetwork->initNetwork();

}

void NetworkAssembler::initHiddenLayer() {
    //Add one dummy unit first
    AbstractPerceptronUnitPtr pDummyPerceptronUnit = m_pPerceptronFactory->createPerceptronUnit(DUMMY);
    m_hiddenLayer.push_back(pDummyPerceptronUnit);
    
    for (ulong i = 0; i < m_numberOfHiddenUnit; i++) {
        AbstractPerceptronUnitPtr pPerceptronUnit = m_pPerceptronFactory->createPerceptronUnit(m_hiddenUnitType);
        m_hiddenLayer.push_back(pPerceptronUnit);
    }
}

void NetworkAssembler::initOutputLayer() {
   for (ulong i = 0; i < m_numberOfOutputUnit; i++) {
        AbstractPerceptronUnitPtr pPerceptronUnit = m_pPerceptronFactory->createPerceptronUnit(m_outputUnitType);
        m_outputLayer.push_back(pPerceptronUnit);
    }
}

void NetworkAssembler::releaseLayer(Layer& layer) {
    layer.clear();
}