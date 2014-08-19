//
//  SolutionStepPool.cpp
//  VNOI1
//
//  Created by wws2003 on 3/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "SolutionStepPool.h"
#include "ConcreteSolutionStep.h"
#include <assert.h>
#include <cstdio>

SolutionStepPool* SolutionStepPool::instancePtr = NULL;

SolutionStepPool* SolutionStepPool::getInstance() {
    CellPoolPtr cellPoolPtr = CellPool::getInstance();
    if (instancePtr == NULL) {
        instancePtr = new SolutionStepPool(cellPoolPtr);
    }
    return instancePtr;
}

SolutionStepPool::~SolutionStepPool() {
    CellPoolPtr cellPoolPtr = CellPool::getInstance();
    integer numberOfRow = cellPoolPtr->getNumberOfRow();
    integer numberOfColumn = cellPoolPtr->getNumberOfColumn();

    for (integer i = 0; i < numberOfRow; i++) {
       for (integer j = 0; j < numberOfColumn - 1; j++) {
           delete m_horizontalSolutionStepPool[i][j];
        }
        delete m_horizontalSolutionStepPool[i];
    }
    delete m_horizontalSolutionStepPool;
    
    for (integer i = 0; i < numberOfRow - 1; i++) {
        for (integer j = 0; j < numberOfColumn; j++) {
            delete m_verticalSolutionStepPool[i][j];
        }
        delete m_verticalSolutionStepPool[i];
    }
    delete m_verticalSolutionStepPool;
}

AbstractSolutionStepPtr SolutionStepPool::getSolutionStepPtr(integer row, integer column, StepDirection stepDirection) const {
    if (stepDirection == HORIZONTAL) {
        //assert(column <  CellPool::getInstance()->getNumberOfColumn() - 1);
        return m_horizontalSolutionStepPool[row][column];
    }
    if (stepDirection == VERTICAL) {
        //assert(row <  CellPool::getInstance()->getNumberOfRow() - 1);
        return m_verticalSolutionStepPool[row][column];
    }
    return NULL;
}

#if DEBUG
void SolutionStepPool::printOut() const {
    printf("Solution step pool\n");
    CellPoolPtr cellPoolPtr = CellPool::getInstance();
    integer numberOfRow = cellPoolPtr->getNumberOfRow();
    integer numberOfColumn = cellPoolPtr->getNumberOfColumn();
    
    printf("Horizontal solution step\n");
    for (integer i = 0; i < numberOfRow; i++) {
        for (integer j = 0; j < numberOfColumn - 1; j++) {
            printf("(%d-%d) ", m_horizontalSolutionStepPool[i][j]->getFirstCellRow(), m_horizontalSolutionStepPool[i][j]->getFirstCellColumn());
        }
        printf("\n");
    }
    
    printf("Vertical solution step\n");
    for (integer i = 0; i < numberOfRow - 1; i++) {
        for (integer j = 0; j < numberOfColumn; j++) {
            printf("(%d-%d) ", m_verticalSolutionStepPool[i][j]->getFirstCellRow(), m_verticalSolutionStepPool[i][j]->getFirstCellColumn());
        }
        printf("\n");
    }
}
#endif

SolutionStepPool::SolutionStepPool(CellPoolPtr cellPoolPtr) {
    integer numberOfRow = cellPoolPtr->getNumberOfRow();
    integer numberOfColumn = cellPoolPtr->getNumberOfColumn();
    
    m_horizontalSolutionStepPool = new AbstractSolutionStepPtr*[numberOfRow];
    for (integer i = 0; i < numberOfRow; i++) {
        m_horizontalSolutionStepPool[i] = new AbstractSolutionStepPtr[numberOfColumn - 1];
        for (integer j = 0; j < numberOfColumn - 1; j++) {
            m_horizontalSolutionStepPool[i][j] = new ConcreteSolutionStep(cellPoolPtr->getCellAtPosition(i, j), HORIZONTAL);
        }
    }
    
    m_verticalSolutionStepPool = new AbstractSolutionStepPtr*[numberOfRow - 1];
    for (integer i = 0; i < numberOfRow - 1; i++) {
        m_verticalSolutionStepPool[i] = new AbstractSolutionStepPtr[numberOfColumn];
        for (integer j = 0; j < numberOfColumn; j++) {
            m_verticalSolutionStepPool[i][j] = new ConcreteSolutionStep(cellPoolPtr->getCellAtPosition(i, j), VERTICAL);
        }
    }
    
}