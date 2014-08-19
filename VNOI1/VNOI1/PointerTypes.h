//
//  PointerTypes.h
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef VNOI1_PointerTypes_h
#define VNOI1_PointerTypes_h

#include <vector>

typedef unsigned int integer;

enum StepDirection{
    HORIZONTAL,
    VERTICAL
};

class Cell;
typedef Cell* CellPtr;
typedef std::vector<CellPtr> CellPtrs;
typedef std::vector<Cell> Cells;

class AbstractSolutionStep;
typedef AbstractSolutionStep* AbstractSolutionStepPtr;
typedef std::vector<AbstractSolutionStepPtr> AbstractSolutionStepPtrs;

class AbstractProblem;
typedef AbstractProblem* AbstractProblemPtr;
typedef std::vector<AbstractProblemPtr> AbstractProblemPtrs;

class ISolutionStepCalculator;
typedef ISolutionStepCalculator* SolutionStepCalculatorPtr;
#endif
