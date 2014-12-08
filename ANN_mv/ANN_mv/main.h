//
//  main.h
//  ANN_mv
//
//  Created by wws2003 on 11/12/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ANN_mv_main_h
#define ANN_mv_main_h

#include <iostream>
#include <cmath>
#include <ctime>
#include "common.h"
#include "MultiLayerNetwork.h"
#include "NetworkAssembler.h"


struct NetWorkConfig {
    int m_numberOfHiddenUnits;
    int m_numberOfOutputUnits;
    PERCEPTRON_UNIT_TYPE m_hiddenUnitType;
    PERCEPTRON_UNIT_TYPE m_outputUnitType;
    int m_numberOfInputs;
};

typedef struct NetWorkConfig NetworkConfig;

struct TrainingConfig {
    int m_sizeOfTrainingDataSet;
    int m_maxTrainingIteration;
};

typedef struct TrainingConfig TrainingConfig;

void initNetworkConfig(NetWorkConfig* pConfig);

void initTraningConfig(TrainingConfig* pConfig);

void initTraningDataSet(InputsSet& inputsSet, TargetsSet& targetsSet, TrainingConfig trainingConfig, int *pNumberOfInputs = NULL, int* pNumberOfOutputs = NULL);

void functionToLearn(Inputs inputs, Targets& targets);

void initNetwork(NetworkAssembler** ppNetworkAssembler, MultiLayerNetworkPtr pNetwork, NetworkConfig config);

void trainNetwork(MultiLayerNetwork* pNetwork, const InputsSet& inputsSet, const TargetsSet& targetsSet, TrainingConfig config);

void validateNetwork(MultiLayerNetwork* pNetwork);

bool canTerminateTraining(int iteration, MultiLayerNetwork* pNetwork, TrainingConfig config);

int testNetworkWithValidationData(MultiLayerNetwork* pNetwork, int testDataIndex, const InputsSet& inputsSet, const TargetsSet& targetsSet);

void releaseTrainingDataSet(InputsSet& inputsSet, TargetsSet& targetsSet);

#endif
