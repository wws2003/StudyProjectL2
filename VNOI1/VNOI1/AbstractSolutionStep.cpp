//
//  AbstractSolutionStep.cpp
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractSolutionStep.h"

AbstractSolutionStep::AbstractSolutionStep(CellPtr firstCell, StepDirection stepDirection) {
}

AbstractSolutionStep::~AbstractSolutionStep() {
    
}

#if DEBUG
integer AbstractSolutionStep::getFirstCellRow() {
    Cell cell1, cell2;
    getCells(cell1, cell2);
    return cell1.row;
}

integer AbstractSolutionStep::getFirstCellColumn() {
    Cell cell1, cell2;
    getCells(cell1, cell2);
    return cell1.column;
}
#endif