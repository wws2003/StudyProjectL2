//
//  common.h
//  ANN_mv
//
//  Created by wws2003 on 10/19/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ANN_mv_common_h
#define ANN_mv_common_h

#include <vector>

typedef std::vector<double> Inputs;
typedef std::vector<double> Targets;

typedef Inputs* InputsPtr;
typedef Targets* TargetsPtr;

typedef std::vector<double> Outputs;

typedef std::vector<InputsPtr> InputsSet;
typedef std::vector<InputsPtr> InternalInputs;
typedef std::vector<TargetsPtr> TargetsSet;

typedef double* Edge;
typedef std::vector<Edge> Edges;
typedef double**  WeightTable;

class AbstractPerceptronUnit;
typedef AbstractPerceptronUnit* AbstractPerceptronUnitPtr;

typedef std::vector<AbstractPerceptronUnitPtr> Layer;
typedef Layer* LayerPtr;

class MultiLayerNetwork;
typedef MultiLayerNetwork* MultiLayerNetworkPtr;

enum PERCEPTRON_UNIT_TYPE {
    DUMMY,
    SIMPLE_SIGMOID,
    WEIGHT_PENALTY,
    LINEAR,
    LINEAR_WEIGHT_PENALTY
};

typedef unsigned long ulong;
#endif
