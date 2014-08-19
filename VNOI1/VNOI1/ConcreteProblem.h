//
//  ConcreteProblem.h
//  VNOI1
//
//  Created by wws2003 on 3/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __VNOI1__ConcreteProblem__
#define __VNOI1__ConcreteProblem__

#include <iostream>
#include "AbstractProblem.h"

class ConcreteProblem : public AbstractProblem {
public:
    ConcreteProblem(integer numberOfRow, integer numberOfColumn);
    ConcreteProblem(ConcreteProblem* parentProblemPtr, AbstractSolutionStepPtr solutionStepPtr);
    virtual ~ConcreteProblem();
    
    //@Override
    virtual void regiterBlockedCells(const Cells& blockedCells);
    //@Override
    virtual std::string getProblemIdentifier() const;
    //@Override
    
    //@Override
    virtual void getFreeCellPtrs(CellPtrs& freeCellPtrs) const;
    //@Override
    virtual void getSolutionStepsAroundCell(const CellPtr cellPtr, AbstractSolutionStepPtrs& solutionStepPtrs) const;
    //@Override
    virtual AbstractProblemPtr getSubProblemUsingSolutionStep(AbstractSolutionStepPtr solutionStepPtr);
    //@Override
    virtual bool isFreeSolutionStep(const AbstractSolutionStepPtr solutionStepPtr) const;
    
private:
    CellPtrs m_freeCellPtrs;
    bool isValidPosition(int row, int column) const;
};

typedef ConcreteProblem* ConcreteProblemPtr;

#endif /* defined(__VNOI1__ConcreteProblem__) */
