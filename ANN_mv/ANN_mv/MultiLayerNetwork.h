//
//  MultiLayerNetwork.h
//  ANN_mv
//
//  Created by wws2003 on 10/19/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__MultiLayerNetwork__
#define __ANN_mv__MultiLayerNetwork__

#include <iostream>
#include "common.h"

class MultiLayerNetwork {
    
//Temporally allow NetworkTester to access private members
friend class NetworkTester;
    
public:
    MultiLayerNetwork();
    virtual ~MultiLayerNetwork();
    
    void inline setNumberOfInputUnits(int dimensionOfInputs){m_dimensionOfInputs = dimensionOfInputs;};
    void inline setHiddenLayerPtr(LayerPtr pHiddenLayer){m_pHiddenLayer = pHiddenLayer;};
    void inline setOutputLayerPtr(LayerPtr pOutputLayer){m_pOutputLayer = pOutputLayer;};
    
    //Connect layers with weighted edges.
    void initNetwork();
    
    //Train the network to update weights
    void train(const InputsSet & inputsSet, const TargetsSet& targetsSet);
    
    //Calculate the output by feed forwarding
    void forwardPropagate(InputsPtr pInputs);
    
    void getOutputs(Outputs& outputs);
    
private:
    void initWeightTables();
    void initWeightTable(WeightTable& weightTable, ulong dimensionOfIncome, ulong dimensionOfOutcome, double defaultValue = 0);
    
    void connectLayers();
    
    void releaseWeightTables();
    void releaseWeightTable(WeightTable weightTable, ulong size);
    
    void addWeightTable(WeightTable table, WeightTable delta, ulong w, ulong h);
    void releaseInternalInputs();
    
    void updateWeightTables();

    void updateDeltaTables(Targets targets);
    WeightTable m_deltaWeightTableForHiddenLayer;
    WeightTable m_deltaWeightTableForOutputLayer;
    
    LayerPtr m_pHiddenLayer;
    LayerPtr m_pOutputLayer;
    InternalInputs m_outputLayerInputs;
    int m_dimensionOfInputs;
    
    WeightTable m_weightTableForHiddenLayer;
    WeightTable m_weightTableForOutputLayer;
};

#endif /* defined(__ANN_mv__MultiLayerNetwork__) */
