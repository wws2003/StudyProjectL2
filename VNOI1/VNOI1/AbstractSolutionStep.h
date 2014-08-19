//
//  AbstractSolutionStep.h
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __VNOI1__AbstractSolutionStep__
#define __VNOI1__AbstractSolutionStep__

#include <iostream>
#include "PointerTypes.h"
#include "Cell.h"
#include <algorithm>

class AbstractSolutionStep {
public:
    AbstractSolutionStep(CellPtr firstCell, StepDirection stepDirection);
    virtual ~AbstractSolutionStep();
   
    virtual void getCells(Cell& cell1, Cell& cell2) = 0;
    
#if DEBUG
    integer getFirstCellRow();
    integer getFirstCellColumn();
#endif
    
protected:
    
};

#endif /* defined(__VNOI1__AbstractSolutionStep__) */
