//
//  AbstractProblem.cpp
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractProblem.h"
#include "AbstractSolutionStep.h"
#include "ProblemCache.h"
#include <assert.h>
#include <cstdio>

AbstractProblem::AbstractProblem(integer numberOfRow, integer numberOfColumn) {
    m_numberOfRow = numberOfRow;
    m_numberOfColumn = numberOfColumn;
}

AbstractProblem::~AbstractProblem() {
    
}

integer AbstractProblem::calculateNumberOfSolutions() {
#if DEBUG
    //printProblem();
#endif
    std::string problemIdentifier = getProblemIdentifier();
    ProblemCachePtr problemCachePtr = ProblemCache::getInstance();
    if (problemCachePtr->hasProblemStored(problemIdentifier)) {
        #if DEBUG
            printf("Cached!\n");
        #endif
        return problemCachePtr->findNumberOfSolutionByProblem(problemIdentifier);;
    }
    
    integer numberOfSolutionForProblem = 0;
    CellPtrs freeCellPtrs;
    getFreeCellPtrs(freeCellPtrs);
    if (freeCellPtrs.size() > 0) {
        CellPtr firstFreeCellPtr = freeCellPtrs.front();
        if (firstFreeCellPtr != NULL) {
            AbstractSolutionStepPtrs solutionStepPtrsAroundCell;
            getSolutionStepsAroundCell(firstFreeCellPtr, solutionStepPtrsAroundCell);
            for (AbstractSolutionStepPtrs::const_iterator sPtrIter = solutionStepPtrsAroundCell.begin(); sPtrIter != solutionStepPtrsAroundCell.end(); sPtrIter++) {
                const AbstractSolutionStepPtr solutionPtr = *sPtrIter;
                if (isFreeSolutionStep(solutionPtr)) {
                    AbstractProblemPtr subProblemPtr = getSubProblemUsingSolutionStep(solutionPtr);
                    numberOfSolutionForProblem += subProblemPtr->calculateNumberOfSolutions();
                    delete subProblemPtr;
                }
            }
        }
    }
    else {
        numberOfSolutionForProblem = 1;
    }
    
    problemCachePtr->storeProblemWithNumberOfSolution(problemIdentifier, numberOfSolutionForProblem);

#if DEBUG
    //printf("Number of solutions:%d\n", numberOfSolutionForProblem);
#endif
    
    return numberOfSolutionForProblem;
}

#if DEBUG
void AbstractProblem::printProblem() const{
    printf("Problem description\n");
    integer* cells = new integer[m_numberOfRow * m_numberOfColumn];
    for (integer i = 0; i < m_numberOfRow * m_numberOfColumn; i++) {
        cells[i] = 1;
    }
    CellPtrs freeCellPtrs;
    getFreeCellPtrs(freeCellPtrs);
    for (CellPtrs::const_iterator cIter = freeCellPtrs.begin(); cIter != freeCellPtrs.end(); cIter++) {
        integer freeX = (*cIter)->row;
        integer freeY = (*cIter)->column;
        cells[freeX * m_numberOfColumn + freeY] = 0;
    }
    for (integer i = 0; i < m_numberOfRow; i++) {
        for (integer j = 0; j < m_numberOfColumn; j++) {
            printf("%d ", cells[i * m_numberOfColumn + j]);
        }
        printf("\n");
    }
    delete cells;
}
#endif

