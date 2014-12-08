//
//  main.cpp
//  ANN_mv
//
//  Created by wws2003 on 10/19/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#define TEST_MODE 0

#if TEST_MODE == 1

#include "PerceptronTester.h"
#include "NetworkTester.h"
#include "PerceptronUnitFactory.h"
#include <cmath>

int main(int argc, const char * argv[])
{
    PerceptronTester perceptronTester;
    PerceptronUnitFactory* pFactoryInstance = PerceptronUnitFactory::getInstance();
    PerceptronUnitSimpleSigmoidImpl* pPerceptronUnit = (PerceptronUnitSimpleSigmoidImpl* )pFactoryInstance->createPerceptronUnit(SIMPLE_SIGMOID);
    perceptronTester.testPerceptronUnitSimpleSigmoidImpl(pPerceptronUnit);
    
    NetworkTester networkTester;
    networkTester.testForwardPropagate();
    networkTester.testUpdateDeltaTable();
    PerceptronUnitFactory::releaseInstance();
    return 0;
}

#else

#include "main.h"
#include "Util.hpp"

#define MAX_INPUT_VALUE 20

int main(int argc, const char * argv[])
{
    std::cout << "Hello, World!\n";
    
    InputsSet inputsSet;
    TargetsSet targetsSet;
    
    NetWorkConfig networkConfig;
    initNetworkConfig(&networkConfig);
    
    TrainingConfig trainingConfig;
    initTraningConfig(&trainingConfig);
    
    initTraningDataSet(inputsSet, targetsSet, trainingConfig, &networkConfig.m_numberOfInputs, &networkConfig.m_numberOfOutputUnits);
    
    NetworkAssembler* pNetworkAssembler;
    MultiLayerNetwork network;
    initNetwork(&pNetworkAssembler, &network, networkConfig);

    trainNetwork(&network, inputsSet, targetsSet, trainingConfig);
    
    validateNetwork(&network);
    
    releaseTrainingDataSet(inputsSet, targetsSet);
    
    delete pNetworkAssembler;
    
    return 0;
}

void initNetworkConfig(NetWorkConfig* pConfig) {
    pConfig->m_hiddenUnitType = WEIGHT_PENALTY;
    pConfig->m_outputUnitType = WEIGHT_PENALTY;
    pConfig->m_numberOfHiddenUnits = 50;
}

void initTraningConfig(TrainingConfig* pConfig) {
    pConfig->m_sizeOfTrainingDataSet = 6000;
    pConfig->m_maxTrainingIteration = 100;
}

void initTraningDataSet(InputsSet& inputsSet, TargetsSet& targetsSet, TrainingConfig config,int *pNumberOfInputs, int* pNumberOfOutputs) {
    
    srand((unsigned int)time(NULL));
    
    for (uint i = 0; i < config.m_sizeOfTrainingDataSet; i++) {
        InputsPtr pInputs = new Inputs();
        pInputs->push_back(1);
        double x = (rand() % 2 == 0 ? 1 : -1) * double(rand() % (MAX_INPUT_VALUE * 100)) / 100.0;
        double y = (rand() % 2 == 0 ? 1 : -1) * double(rand() % (MAX_INPUT_VALUE * 100)) / 100.0;
        pInputs->push_back(x);
        pInputs->push_back(y);
        
        TargetsPtr pTargets = new Targets();
        functionToLearn(*pInputs, *pTargets);
        
        inputsSet.push_back(pInputs);
        targetsSet.push_back(pTargets);
    }
    
    if (pNumberOfInputs != NULL && inputsSet.size() > 0) {
        *pNumberOfInputs = (int)inputsSet[0]->size();
    }
    if (pNumberOfOutputs != NULL && targetsSet.size() > 0) {
        *pNumberOfOutputs = (int)targetsSet[0]->size();
    }
}

void functionToLearn(Inputs inputs, Targets& targets) {
    targets.clear();
    //  Try to learn the function
    //  z = z = (2 * x - 3 * y > 100) ? 1 : 0;
    
    double x = inputs[1];
    double y = inputs[2];
    
//    double v = 2 * x * x * (x - 1) + 3 * x * x - 3 * y;
//    double z0 = (v > 200) ? 1 : 0;
//    double z1 = (v < 200 && v > 0) ? 1 : 0;
//    double z2 = (v < 0) ? 1 : 0;
//    
//    targets.push_back(z0);
//    targets.push_back(z1);
//    targets.push_back(z2);
    
    //Try the circle function
    double r = MAX_INPUT_VALUE;
    double z = 2 * x * x * y - y * y * x - 12;
    double z0 = z > 0 ? 1 : 0;
    targets.push_back(z0);
    targets.push_back(1 - z0);
}

void initNetwork(NetworkAssembler** ppNetworkAssembler, MultiLayerNetworkPtr pNetwork, NetworkConfig config) {
    NetworkAssembler* pNetworkAssembler = new NetworkAssembler(config.m_numberOfHiddenUnits, config.m_numberOfOutputUnits, config.m_hiddenUnitType, config.m_outputUnitType);
    pNetworkAssembler->assembleNetwork(pNetwork, config.m_numberOfInputs);
    *ppNetworkAssembler = pNetworkAssembler;
}

void trainNetwork(MultiLayerNetwork* pNetwork, const InputsSet& inputsSet, const TargetsSet& targetsSet, TrainingConfig config) {
    int iteration = 0;
    while (!canTerminateTraining(iteration, pNetwork, config)) {
        pNetwork->train(inputsSet, targetsSet);
        iteration++;
    }
}

//TODO Revise this method
bool canTerminateTraining(int iteration, MultiLayerNetwork* pNetwork, TrainingConfig config) {
    return iteration >= config.m_maxTrainingIteration;
}

void validateNetwork(MultiLayerNetwork* pNetwork) {
    int numberOfValidateData = 200;
    InputsSet inputsSet;
    TargetsSet targetsSet;
    
    TrainingConfig config;
    config.m_sizeOfTrainingDataSet = numberOfValidateData;
    
    initTraningDataSet(inputsSet, targetsSet, config);
    
    int correctPredictionCount = 0;
    for (int i = 0; i < numberOfValidateData; i++) {
        correctPredictionCount += testNetworkWithValidationData(pNetwork, i, inputsSet, targetsSet);
        printf("----------------\n");
    }
    
    printf("Correct prediction rate : %d/%d\n", correctPredictionCount, numberOfValidateData);
    
    releaseTrainingDataSet(inputsSet, targetsSet);
}

int testNetworkWithValidationData(MultiLayerNetwork* pNetwork, int testDataIndex, const InputsSet& inputsSet, const TargetsSet& targetsSet) {
    InputsPtr pInputs = inputsSet[testDataIndex];
    //double x = (*pInputs)[1];
    //double y = (*pInputs)[2];
    pNetwork->forwardPropagate(pInputs);
    
    Outputs outputs;
    pNetwork->getOutputs(outputs);
    
    int maxIdx = 0;
    double maxOutput = - MAXFLOAT;
    int maxExpectedIdx = 0;
    double maxExpectedOutput = - MAXFLOAT;
    
    for (int i = 0; i < outputs.size(); i++) {
        if (outputs[i] > maxOutput) {
            maxOutput = outputs[i];
            maxIdx = i;
        }
        if ((*targetsSet[testDataIndex])[i] > maxExpectedOutput) {
            maxExpectedOutput = (*targetsSet[testDataIndex])[i];
            maxExpectedIdx = i;
        }
        //printf("Input %lf %lf, [expected output, pratical output][%d] = [%lf, %lf] \n", x, y, i, (*targetsSet[testDataIndex])[i], outputs[i]);
    }
    
    printf("[%d %d] %s\n", maxExpectedIdx, maxIdx, maxExpectedIdx == maxIdx ? "Correct prediction" : "Failed prediction");
    return maxIdx == maxExpectedIdx ? 1 : 0;
}

void releaseTrainingDataSet(InputsSet& inputsSet, TargetsSet& targetsSet) {
    Util::releaseVector<Inputs>(inputsSet);
    Util::releaseVector<Targets>(targetsSet);
}

#endif