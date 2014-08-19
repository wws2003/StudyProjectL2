//
//  ConcreteProblem.cpp
//  VNOI1
//
//  Created by wws2003 on 3/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <cstdlib>
#include "ConcreteProblem.h"
#include "CellPool.h"
#include "AbstractSolutionStep.h"
#include "SolutionStepPool.h"

ConcreteProblem::ConcreteProblem(integer numberOfRow, integer numberOfColumn) : AbstractProblem(numberOfRow, numberOfColumn) {
    
    //This method is called once to generate root problem instance
    CellPool::initInstance(numberOfRow, numberOfColumn);
    
    for (integer i = 0; i < numberOfRow; i++) {
        for (integer j = 0; j < numberOfColumn; j++) {
            m_freeCellPtrs.push_back(CellPool::getInstance()->getCellAtPosition(i,j));
        }
    }
}

ConcreteProblem::ConcreteProblem(ConcreteProblemPtr parentProblemPtr, AbstractSolutionStepPtr solutionStepPtr) : AbstractProblem(parentProblemPtr->m_numberOfRow, parentProblemPtr->m_numberOfColumn) {
    m_freeCellPtrs = parentProblemPtr->m_freeCellPtrs;
    Cell cell1UsedByStep, cell2UsedByStep;
    solutionStepPtr->getCells(cell1UsedByStep, cell2UsedByStep);
    Cells cellsUsedByStep;
    cellsUsedByStep.push_back(cell1UsedByStep);
    cellsUsedByStep.push_back(cell2UsedByStep);
    regiterBlockedCells(cellsUsedByStep);
}

ConcreteProblem::~ConcreteProblem() {
    //delete CellPool::getInstance();
}

void ConcreteProblem::regiterBlockedCells(const Cells& blockedCells) {
    for (CellPtrs::iterator cPtrIter = m_freeCellPtrs.begin(); cPtrIter != m_freeCellPtrs.end();) {
        bool blocked = false;
        CellPtr cellPtr = *cPtrIter;
        for (Cells::const_iterator cIter = blockedCells.begin(); cIter != blockedCells.end(); cIter++) {
            if (cellPtr->row == cIter->row && cellPtr->column == cIter->column) {
                blocked = true;
            }
        }
        if (blocked) {
            cPtrIter = m_freeCellPtrs.erase(cPtrIter);
        }
        else {
            cPtrIter++;
        }
    }
}

std::string ConcreteProblem::getProblemIdentifier() const{
    integer problemSize = m_numberOfRow * m_numberOfColumn;
    char* buffer = (char*)malloc(problemSize);
    memset(buffer, '0', problemSize *sizeof(char));
    for (CellPtrs::const_iterator cPtrIter = m_freeCellPtrs.begin(); cPtrIter != m_freeCellPtrs.end();cPtrIter++)  {
        CellPtr cellPtr = *cPtrIter;
        integer row = cellPtr->row;
        integer column= cellPtr->column;
        buffer[row * m_numberOfColumn + column] = '1';
    }
    std::string identifier(buffer, problemSize);
    free(buffer);
    return identifier;
}

void ConcreteProblem::getFreeCellPtrs(CellPtrs& freeCellPtrs) const {
    freeCellPtrs.clear();
    freeCellPtrs.insert(freeCellPtrs.begin(), m_freeCellPtrs.begin(), m_freeCellPtrs.end());
}

void ConcreteProblem::getSolutionStepsAroundCell(const CellPtr cellPtr, AbstractSolutionStepPtrs& solutionStepPtrs) const{
    integer row1 = cellPtr->row;
    integer column1 = cellPtr->column;
    SolutionStepPoolPtr solutionStepPoolPtr = SolutionStepPool::getInstance();
    if (isValidPosition(row1, column1 + 1)) {
        solutionStepPtrs.push_back(solutionStepPoolPtr->getSolutionStepPtr(row1, column1, HORIZONTAL));
    }
    if (isValidPosition(row1, column1 - 1)) {
        solutionStepPtrs.push_back(solutionStepPoolPtr->getSolutionStepPtr(row1, column1 - 1, HORIZONTAL));
    }
    if (isValidPosition(row1 + 1, column1)) {
        solutionStepPtrs.push_back(solutionStepPoolPtr->getSolutionStepPtr(row1, column1, VERTICAL));
    }
    if (isValidPosition(row1 - 1, column1)) {
        solutionStepPtrs.push_back(solutionStepPoolPtr->getSolutionStepPtr(row1 - 1, column1, VERTICAL));
    }
}

bool ConcreteProblem::isFreeSolutionStep(const AbstractSolutionStepPtr solutionStepPtr) const {
    Cell cell1, cell2;
    solutionStepPtr->getCells(cell1, cell2);
    bool cell1Free = false;
    bool cell2Free = false;
    for (CellPtrs::const_iterator cIter = m_freeCellPtrs.begin(); cIter != m_freeCellPtrs.end(); cIter++) {
        integer freeX = (*cIter)->row;
        integer freeY = (*cIter)->column;
        if ((!cell1Free) && (cell1.row == freeX && cell1.column == freeY)) {
            cell1Free = true;
        }
        if ((!cell2Free) && (cell2.row == freeX && cell2.column == freeY)) {
            cell2Free = true;
        }
        if (cell1Free && cell2Free) {
            return true;
        }
    }
    return false;
}


AbstractProblemPtr ConcreteProblem::getSubProblemUsingSolutionStep(AbstractSolutionStepPtr solutionStepPtr){
    return new ConcreteProblem(this, solutionStepPtr);
}

bool ConcreteProblem::isValidPosition(int row, int column) const {
    return !(row < 0 || column < 0 || row >= m_numberOfRow || column >= m_numberOfColumn);
}
