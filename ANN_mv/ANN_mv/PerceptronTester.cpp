//
//  Tester.cpp
//  ANN_mv
//
//  Created by wws2003 on 10/27/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "PerceptronTester.h"
#include "Util.hpp"

#define LEARNING_RATE 0.005

//Inputs 1 1 2
//Income weights 0.2 0.5 0.1
//Target 0.9

//Error term as output unit
//Expected output y = 1 / (1 + e^-(1*0.2 + 1*0.5 + 2*0.1)) ~~ 0.71095
//Expected output layer error term = y*(1-y)*(target - y) = 

//Error term as hidden unit
//Outcome weights 0.3 0.1 0.5
//Output layer error terms: 1 1 1 (dummy unit)
//Expected hidden layer error term = y*(1-y)*(1*0.3 + 1*0.1 + 1*0.5) = 0.18495

PerceptronTester::PerceptronTester() {
    initIncomeEdgesForTest();
    initOutcomeEdgesForTest();
    initOutputLayerForTest();
    initInputsForTest();
    initExpectedValues();
    initTarget();
}

PerceptronTester::~PerceptronTester() {
    releaseIncomeEdgesForTest();
    releaseOutcomeEdgesForTest();
    releaseOutputLayerForTest();
    releaseInputsForTest();
}

void PerceptronTester::testPerceptronUnitSimpleSigmoidImpl(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit) {
    testPerceptronUnitSimpleSigmoidImplOutput(pPerceptronUnit);
    testPerceptronUnitSimpleSigmoidImplErrorTerm(pPerceptronUnit);
}

void PerceptronTester::initIncomeEdgesForTest() {
    Edge edge1 = new double(0.2);
    Edge edge2 = new double(0.5);
    Edge edge3 = new double(0.1);
    m_incomeEdgesForTest.push_back(edge1);
    m_incomeEdgesForTest.push_back(edge2);
    m_incomeEdgesForTest.push_back(edge3);
}

void PerceptronTester::initOutcomeEdgesForTest() {
    Edge edge1 = new double(0.3);
    Edge edge2 = new double(0.1);
    Edge edge3 = new double(0.5);
    m_outcomeEdgesForTest.push_back(edge1);
    m_outcomeEdgesForTest.push_back(edge2);
    m_outcomeEdgesForTest.push_back(edge3);
}

void PerceptronTester::initOutputLayerForTest() {
    m_pOuputLayer = new Layer();
    for (int i = 0; i < 3; i++) {
        PerceptronUnitDummyForTestImpl* pPerceptronUnit = new PerceptronUnitDummyForTestImpl();
        m_pDummyOutputUnits.push_back(pPerceptronUnit);
        m_pOuputLayer->push_back(pPerceptronUnit);
    }
}

void PerceptronTester::initInputsForTest() {
    m_pInputsForTest = new Inputs();
    m_pInputsForTest->push_back(1);
    m_pInputsForTest->push_back(1);
    m_pInputsForTest->push_back(2);
}

void PerceptronTester::initTarget() {
    m_target = 0.9;
}

void PerceptronTester::initExpectedValues() {
    m_expectedOutput = 0.71095;
    m_expectedOutputLayerErrorTerm = 0.038850;
    m_expectedHiddenLayerErrorTerm = 0.18495;
}

void PerceptronTester::testPerceptronUnitSimpleSigmoidImplOutput(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit) {
    
    pPerceptronUnit->setInputs(m_pInputsForTest);
    for (Edge edge : m_incomeEdgesForTest) {
        pPerceptronUnit->addIncomeEdge(edge);
    }
    pPerceptronUnit->calculateAndStoreOutput();
    printf("Output expected %lf, practical %lf\n", m_expectedOutput, pPerceptronUnit->getOutput());
}

void PerceptronTester::testPerceptronUnitSimpleSigmoidImplErrorTerm(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit) {
    testPerceptronUnitSimpleSigmoidImplOutputLayerErrorTerm(pPerceptronUnit);
    testPerceptronUnitSimpleSigmoidImplHiddenLayerErrorTerm(pPerceptronUnit);
}

void PerceptronTester::testPerceptronUnitSimpleSigmoidImplOutputLayerErrorTerm(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit) {
    pPerceptronUnit->calculateAndStoreErrorTerm(m_target);
    printf("Output layer error term expected %lf, practical %lf\n",  m_expectedOutputLayerErrorTerm, pPerceptronUnit->getErrorTerm());
}

void PerceptronTester::testPerceptronUnitSimpleSigmoidImplHiddenLayerErrorTerm(PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit) {
    for (Edge edge : m_outcomeEdgesForTest) {
        pPerceptronUnit->addOutcomeEdge(edge);
    }
    pPerceptronUnit->calculateAndStoreErrorTerm(m_pOuputLayer);
    printf("Hidden layer error term expected %lf, practical %lf\n", m_expectedHiddenLayerErrorTerm, pPerceptronUnit->getErrorTerm());
}

void PerceptronTester::releaseIncomeEdgesForTest() {
    Util::releaseVector<double>(m_incomeEdgesForTest);
}

void PerceptronTester::releaseInputsForTest() {
    delete m_pInputsForTest;
}

void PerceptronTester::releaseOutcomeEdgesForTest() {
    Util::releaseVector<double>(m_outcomeEdgesForTest);
}

void PerceptronTester::releaseOutputLayerForTest() {
    delete m_pOuputLayer;
    Util::releaseVector<PerceptronUnitDummyForTestImpl>(m_pDummyOutputUnits);
}