//
//  AbstractProblem.h
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __VNOI1__AbstractProblem__
#define __VNOI1__AbstractProblem__

#include <iostream>
#include <string>
#include "PointerTypes.h"

class AbstractProblem {
public:
    AbstractProblem(integer numberOfRow, integer numberOfColumn);
    virtual ~AbstractProblem();
    
    virtual integer calculateNumberOfSolutions();
    
protected:
    virtual void regiterBlockedCells(const Cells& blockedCells) = 0;
    virtual std::string getProblemIdentifier() const = 0;
    
    virtual void getFreeCellPtrs(CellPtrs& freeCellPtrs) const = 0;
    virtual void getSolutionStepsAroundCell(const CellPtr cellPtr, AbstractSolutionStepPtrs& solutionStepPtrs) const = 0;
    virtual AbstractProblemPtr getSubProblemUsingSolutionStep(const AbstractSolutionStepPtr solutionStepPtr) = 0;
    virtual bool isFreeSolutionStep(const AbstractSolutionStepPtr solutionStepPtr) const = 0;
    
    integer m_numberOfRow;
    integer m_numberOfColumn;
    
private:
#if DEBUG
    void printProblem() const;
#endif
};

#endif /* defined(__VNOI1__AbstractProblem__) */

