//
//  ConcreteSolutionStep.cpp
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ConcreteSolutionStep.h"
#include "SolutionStepPool.h"
#include <assert.h>

ConcreteSolutionStep::ConcreteSolutionStep(CellPtr firstCellPtr, StepDirection stepDirection) : AbstractSolutionStep(firstCellPtr, stepDirection), m_cellPair(firstCellPtr, stepDirection) {
   
}

ConcreteSolutionStep::~ConcreteSolutionStep() {
    
}

void ConcreteSolutionStep::getCells(Cell& cell1, Cell& cell2) {
    cell1.row = m_cellPair.first->row;
    cell1.column = m_cellPair.first->column;
    if (m_cellPair.second == HORIZONTAL) {
        cell2.column = cell1.column + 1;
        cell2.row = cell1.row;
    }
    if (m_cellPair.second == VERTICAL) {
        cell2.column = cell1.column;
        cell2.row = cell1.row + 1;
    }
}