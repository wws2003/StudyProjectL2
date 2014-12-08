//
//  NetworkTester.cpp
//  ANN_mv
//
//  Created by wws2003 on 10/28/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//


//Test the network having specification
//-Using simple sigmoid unit
//-3 inputs, 2 hidden layer units, 1 output layer unit
//-Inputs: 1 1 2
//-Weights: Use the initial value of network 0.1
//-Expected output of hidden unit = h = 1 / (1 + e^-(1*0.1 + 1*0.1 + 2*0.1)) = 0.59869
//-Expected output: 1 / (1 + e^-(h*0.1 + h*0.1)) = 0.52990

//-Target value: 0.9
//-Expected Error term of output unit = (target - output) * output * (1 - output)
//                                    = (0.9 - 0.52990) * 0.52990 * (1- 0.52990) = 0.092194
//-Expected delta weight output unit = LEARNING_RATE  * output of hidden unit * Error term of output unit = 0.005 * 0.59869 * 0.092194 = .000276
//-Expected Error term of hidden unit = output of hidden unit * (1 - output of hidden unit) * weight from hidden unit to output unit * errorTerm of output unit
//                           = 0.59869 * (1 - 0.59869) * 0.1 * 0.092194 = 0.0022151
//-Expected Delta 0 = LEARNING_RATE * input * errorTerm of hidden unit
//         = 0.005 * 1 * 0.0022151 = 1.1075e-05
//-Expected Delta 1 = LEARNING_RATE * input * errorTerm of hidden unit
//         = 0.005 * 1 * 0.0022151 = 1.1075e-05
//-Expected Delta 2 = LEARNING_RATE * input * errorTerm of hidden unit
//         = 0.005 * 2 * 0.0022151 = 2.2151e-05

#include "NetworkTester.h"
#include "Util.hpp"
#include "AbstractPerceptronUnit.h"

#define LEARNING_RATE 0.005

NetworkTester::NetworkTester() {
    initLayersForTest();
    initNetworkForTest();
    initInputsForTest();
    initExpectedOutputForTest();
    initTargetValue();
    initExpectedDeltaWeightTables();
}

NetworkTester::~NetworkTester() {
    releaseExpectedDeltaWeightTables();
    releaseInputsForTest();
    releaseNetworkForTest();
    releaseLayersForTest();
}

void NetworkTester::testForwardPropagate() {
    m_pNetwork->forwardPropagate(m_pInputsForTest);
    
    for (int i = 0; i < m_expectedOutputs.size(); i++) {
        printf("Output expected %lf, pratical %lf \n", m_expectedOutputs[i], (*m_pOutputLayer)[i]->getOutput());
    }
}

void NetworkTester::testUpdateDeltaTable() {
    m_pNetwork->updateDeltaTables(m_targets);
    WeightTable deltaWeightForOutputLayer = m_pNetwork->m_deltaWeightTableForOutputLayer;
    WeightTable deltaWeightForHiddenLayer = m_pNetwork->m_deltaWeightTableForHiddenLayer;
    
    ulong outputLayerSize = m_pOutputLayer->size();
    ulong hiddenLayerSize = m_pHiddenLayer->size();
    ulong inputsSize = m_pInputsForTest->size();
    
    for (int i = 0; i < outputLayerSize; i++) {
        for (int j = 0; j < hiddenLayerSize; j++) {
            printf("Delta weight from hidden layer j to output layer unit i expected: %lf, practical: %lf\n", m_expectedDeltaWeightTableForOuputLayer[i][j], deltaWeightForOutputLayer[i][j]);
        }
    }
    
    for (int i = 0; i < hiddenLayerSize; i++) {
        for (int j = 0; j < inputsSize; j++) {
            printf("Delta weight from input j to hidden layer unit i expected: %lf, practical: %lf\n", m_expectedDeltaWeightTableForHiddenLayer[i][j], deltaWeightForHiddenLayer[i][j]);
        }
    }
}

void NetworkTester::initNetworkForTest() {
    m_pNetwork = new MultiLayerNetwork();
    m_pNetwork->setNumberOfInputUnits(3);
    m_pNetwork->setHiddenLayerPtr(m_pHiddenLayer);
    m_pNetwork->setOutputLayerPtr(m_pOutputLayer);
    m_pNetwork->initNetwork();
}

void NetworkTester::initInputsForTest() {
    m_pInputsForTest = new Inputs();
    m_pInputsForTest->push_back(1);
    m_pInputsForTest->push_back(1);
    m_pInputsForTest->push_back(2);
}

void NetworkTester::initExpectedOutputForTest() {
    m_expectedOutputs.clear();
    m_expectedOutputs.push_back(0.52990);
}

void NetworkTester::initTargetValue() {
    m_targets.clear();
    m_targets.push_back(0.9);
}

void NetworkTester::initExpectedDeltaWeightTables() {
    ulong outputLayerSize = m_pOutputLayer->size();
    ulong hiddenLayerSize = m_pHiddenLayer->size();
    ulong inputsSize = m_pInputsForTest->size();
    
    initWeightTable(m_expectedDeltaWeightTableForOuputLayer, outputLayerSize, hiddenLayerSize);
    initWeightTable(m_expectedDeltaWeightTableForHiddenLayer, hiddenLayerSize, inputsSize);
    
    m_expectedDeltaWeightTableForOuputLayer[0][0] = .000276;
    m_expectedDeltaWeightTableForOuputLayer[0][1] = .000276;
    
    m_expectedDeltaWeightTableForHiddenLayer[0][0] = 1.1075e-05;
    m_expectedDeltaWeightTableForHiddenLayer[0][1] = 1.1075e-05;
    m_expectedDeltaWeightTableForHiddenLayer[0][2] = 2.2151e-05;
    m_expectedDeltaWeightTableForHiddenLayer[1][0] = 1.1075e-05;
    m_expectedDeltaWeightTableForHiddenLayer[1][1] = 1.1075e-05;
    m_expectedDeltaWeightTableForHiddenLayer[1][2] = 2.2151e-05;
}

void NetworkTester::initWeightTable(WeightTable& weightTable, ulong n, ulong m) {
    weightTable = new double*[n];
    for (unsigned int i = 0; i < n; i++) {
        weightTable[i] = new double[m];
        for (unsigned int j = 0; j < m; j++) {
            weightTable[i][j] = 0;
        }
    }
}

void NetworkTester::initLayersForTest() {
    PerceptronUnitSimpleSigmoidImpl* pHiddenUnit1 = new PerceptronUnitSimpleSigmoidImpl(LEARNING_RATE);
    PerceptronUnitSimpleSigmoidImpl* pHiddenUnit2 = new PerceptronUnitSimpleSigmoidImpl(LEARNING_RATE);
    
    m_pHiddenLayer = new Layer();
    m_pHiddenLayer->push_back(pHiddenUnit1);
    m_pHiddenLayer->push_back(pHiddenUnit2);
    
    //Store to release later
    m_pHiddenLayerPerceptronUnits.push_back(pHiddenUnit1);
    m_pHiddenLayerPerceptronUnits.push_back(pHiddenUnit2);
    
    PerceptronUnitSimpleSigmoidImpl* pOutputUnit = new PerceptronUnitSimpleSigmoidImpl(LEARNING_RATE);
    m_pOutputLayer = new Layer();
    m_pOutputLayer->push_back(pOutputUnit);
    
    //Store to release later
    m_pOutputLayerPerceptronUnits.push_back(pOutputUnit);
}

void NetworkTester::releaseLayersForTest() {
    delete m_pHiddenLayer;
    delete m_pOutputLayer;
    Util::releaseVector<PerceptronUnitSimpleSigmoidImpl>(m_pHiddenLayerPerceptronUnits);
    Util::releaseVector<PerceptronUnitSimpleSigmoidImpl>(m_pOutputLayerPerceptronUnits);
}

void NetworkTester::releaseInputsForTest() {
    delete m_pInputsForTest;
}

void NetworkTester::releaseNetworkForTest() {
    delete m_pNetwork;
}

void NetworkTester::releaseExpectedDeltaWeightTables() {
    ulong outputLayerSize = m_pOutputLayer->size();
    ulong hiddenLayerSize = m_pHiddenLayer->size();
    releaseWeightTable(m_expectedDeltaWeightTableForHiddenLayer, hiddenLayerSize);
    releaseWeightTable(m_expectedDeltaWeightTableForOuputLayer, outputLayerSize);
    m_expectedDeltaWeightTableForOuputLayer = NULL;
    m_expectedDeltaWeightTableForHiddenLayer = NULL;
}

void NetworkTester::releaseWeightTable(WeightTable weightTable, ulong size) {
    for (ulong i = 0; i < size; i++) {
        delete weightTable[i];
    }
    delete  weightTable;
}