//
//  SolutionStepPool.h
//  VNOI1
//
//  Created by wws2003 on 3/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __VNOI1__SolutionStepPool__
#define __VNOI1__SolutionStepPool__

#include <iostream>
#include "AbstractSolutionStep.h"
#include "CellPool.h"

class SolutionStepPool {
public:
    static SolutionStepPool* getInstance();
    virtual ~SolutionStepPool();
    AbstractSolutionStepPtr getSolutionStepPtr(integer row, integer column, StepDirection stepDirection) const;
    
#if DEBUG
    void printOut() const;
#endif
    
private:
    SolutionStepPool(CellPoolPtr cellPoolPtr);
    static SolutionStepPool* instancePtr;
    
    AbstractSolutionStepPtr** m_horizontalSolutionStepPool;
    AbstractSolutionStepPtr** m_verticalSolutionStepPool;
};

typedef SolutionStepPool* SolutionStepPoolPtr;

#endif /* defined(__VNOI1__SolutionStepPool__) */
