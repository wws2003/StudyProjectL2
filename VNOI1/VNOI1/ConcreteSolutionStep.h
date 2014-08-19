//
//  ConcreteSolutionStep.h
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __VNOI1__ConcreteSolutionStep__
#define __VNOI1__ConcreteSolutionStep__

#include <iostream>
#include "AbstractSolutionStep.h"
#include "CellPool.h"

class ConcreteSolutionStep : public AbstractSolutionStep {
public:
    ConcreteSolutionStep(CellPtr firstCellPtr, StepDirection stepDirection);
    virtual ~ConcreteSolutionStep();
    
    //@Override
    virtual void getCells(Cell& cell1, Cell& cell2);
private:
    std::pair<CellPtr, StepDirection> m_cellPair;
};

typedef ConcreteSolutionStep* ConcreteSolutionStepPtr;

#endif /* defined(__VNOI1__ConcreteSolutionStep__) */
