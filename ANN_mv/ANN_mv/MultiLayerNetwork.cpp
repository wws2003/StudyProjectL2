//
//  MultiLayerNetwork.cpp
//  ANN_mv
//
//  Created by wws2003 on 10/19/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "MultiLayerNetwork.h"
#include "AbstractPerceptronUnit.h"
#include "common.h"
#include "Util.hpp"

#define INIT_WEIGHT 0.01

MultiLayerNetwork::MultiLayerNetwork() {
    
}

MultiLayerNetwork::~MultiLayerNetwork() {
    releaseWeightTables();
    
    releaseInternalInputs();
}

void MultiLayerNetwork::initNetwork() {
    initWeightTables();
    
    connectLayers();
    
    return;
}

void MultiLayerNetwork::train(const InputsSet& inputsSet, const TargetsSet& targetsSet) {
    size_t trainingDataSize = inputsSet.size();
    
    for (ulong i = 0; i < trainingDataSize; i++) {
        InputsPtr pInputs = inputsSet[i];
        Targets targets = *targetsSet[i];
       
        forwardPropagate(pInputs);
        
        updateDeltaTables(targets);
        
        updateWeightTables();
    }
    
    releaseInternalInputs();
}

void MultiLayerNetwork::initWeightTables() {
    ulong numberOfInputUnits = m_dimensionOfInputs;
    ulong numberOfHiddenUnits = m_pHiddenLayer->size();
    ulong numberOfOutputUnits = m_pOutputLayer->size();
    
    initWeightTable(m_weightTableForHiddenLayer, numberOfHiddenUnits, numberOfInputUnits, INIT_WEIGHT);
    initWeightTable(m_weightTableForOutputLayer, numberOfOutputUnits, numberOfHiddenUnits, INIT_WEIGHT);
    
    initWeightTable(m_deltaWeightTableForHiddenLayer, numberOfHiddenUnits, numberOfInputUnits);
    initWeightTable(m_deltaWeightTableForOutputLayer, numberOfOutputUnits, numberOfHiddenUnits);
}

void MultiLayerNetwork::initWeightTable(WeightTable& weightTable, ulong dimensionOfIncome, ulong dimensionOfOutcome, double defaultValue) {
    weightTable = new double*[dimensionOfIncome];
    for (unsigned int i = 0; i < dimensionOfIncome; i++) {
        weightTable[i] = new double[dimensionOfOutcome];
        for (unsigned int j = 0; j < dimensionOfOutcome; j++) {
            weightTable[i][j] = defaultValue;
        }
    }
}

void MultiLayerNetwork::connectLayers() {
    for (unsigned int i = 0; i < m_dimensionOfInputs; i++)  {
        for (unsigned int j = 0; j < m_pHiddenLayer->size(); j++) {
            //Weight of weight from input i to hidden unit j
            (*m_pHiddenLayer)[j]->addIncomeEdge(&m_weightTableForHiddenLayer[j][i]);
        }
    }
    
    for (unsigned int i = 0; i < m_pHiddenLayer->size(); i++)  {
        for (unsigned int j = 0; j < m_pOutputLayer->size(); j++) {
            //Weight of weight from hidden unit i to output unit j
            (*m_pHiddenLayer)[i]->addOutcomeEdge(&m_weightTableForOutputLayer[j][i]);
            (*m_pOutputLayer)[j]->addIncomeEdge(&m_weightTableForOutputLayer[j][i]);
        }
    }
}

void MultiLayerNetwork::releaseWeightTables() {
    ulong numberOfHiddenUnits = m_pHiddenLayer->size();
    ulong numberOfOutputUnits = m_pOutputLayer->size();
    
    releaseWeightTable(m_weightTableForHiddenLayer, numberOfHiddenUnits);
    releaseWeightTable(m_weightTableForOutputLayer, numberOfOutputUnits);
    
    releaseWeightTable(m_deltaWeightTableForHiddenLayer, numberOfHiddenUnits);
    releaseWeightTable(m_deltaWeightTableForOutputLayer, numberOfOutputUnits);
}

void MultiLayerNetwork::releaseWeightTable(WeightTable weightTable, ulong size) {
    for (ulong i = 0; i < size; i++) {
        delete weightTable[i];
    }
    delete  weightTable;
}

void MultiLayerNetwork::forwardPropagate(InputsPtr pInputs) {
    InputsPtr pHiddenLayerOutputs = new Inputs();
    for (AbstractPerceptronUnitPtr pPerceptronUnit : *m_pHiddenLayer) {
        pPerceptronUnit->setInputs(pInputs);
        pPerceptronUnit->calculateAndStoreOutput();
        pHiddenLayerOutputs->push_back(pPerceptronUnit->getOutput());
    }
    for (AbstractPerceptronUnitPtr pPerceptronUnit : *m_pOutputLayer) {
        pPerceptronUnit->setInputs(pHiddenLayerOutputs);
        pPerceptronUnit->calculateAndStoreOutput();
    }
    //Collect internal inputs in order to release later, avoid memory leakage
    m_outputLayerInputs.push_back(pHiddenLayerOutputs);
}

void MultiLayerNetwork::getOutputs(Outputs& outputs) {
    outputs.clear();
    for (AbstractPerceptronUnitPtr pPerceptronUnit : *m_pOutputLayer) {
        outputs.push_back(pPerceptronUnit->getOutput());
    }
}

void MultiLayerNetwork::updateWeightTables() {
    ulong numberOfInputUnits = m_dimensionOfInputs;
    ulong numberOfHiddenUnits = m_pHiddenLayer->size();
    ulong numberOfOutputUnits = m_pOutputLayer->size();
    
    addWeightTable(m_weightTableForHiddenLayer, m_deltaWeightTableForHiddenLayer, numberOfHiddenUnits, numberOfInputUnits);
    
    addWeightTable(m_weightTableForOutputLayer, m_deltaWeightTableForOutputLayer, numberOfOutputUnits, numberOfHiddenUnits);
}

void MultiLayerNetwork::updateDeltaTables(Targets targets) {
    ulong numberOfOutputUnits = m_pOutputLayer->size();
    ulong numberOfHiddenUnits = m_pHiddenLayer->size();
    
    for (ulong i = 0; i < numberOfOutputUnits; i++) {
        AbstractPerceptronUnitPtr pOutputUnit = (*m_pOutputLayer)[i];
        pOutputUnit->calculateAndStoreErrorTerm(targets[i]);
        pOutputUnit->calculateUpdateDelta(m_deltaWeightTableForOutputLayer[i]);
    }
    
    for(ulong i = 0; i < numberOfHiddenUnits; i++) {
        AbstractPerceptronUnitPtr pHiddenUnit = (*m_pHiddenLayer)[i];
        pHiddenUnit->calculateAndStoreErrorTerm(m_pOutputLayer);
        pHiddenUnit->calculateUpdateDelta(m_deltaWeightTableForHiddenLayer[i]);
    }

}

void MultiLayerNetwork::addWeightTable(WeightTable table, WeightTable delta, ulong w, ulong h) {
    for (ulong i = 0; i < w; i++) {
        for (ulong j = 0; j < h; j++) {
            table[i][j] += delta[i][j];
        }
    }
}

void MultiLayerNetwork::releaseInternalInputs() {
    Util::releaseVector<Inputs>(m_outputLayerInputs);
}