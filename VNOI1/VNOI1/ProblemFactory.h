//
//  ProblemFactory.h
//  VNOI1
//
//  Created by wws2003 on 3/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __VNOI1__ProblemFactory__
#define __VNOI1__ProblemFactory__

#include <iostream>
#include "AbstractProblem.h"

class ProblemFactory {
public:
    static AbstractProblemPtr getProblemPtr(integer numberOfRow, integer numberOfColumn, const Cells blockedCells);
    static AbstractProblemPtr getProblemPtr(const char* fileName);
};

#endif /* defined(__VNOI1__ProblemFactory__) */
