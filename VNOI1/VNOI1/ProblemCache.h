//
//  ProblemCache.h
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __VNOI1__ProblemCache__
#define __VNOI1__ProblemCache__

#include <iostream>
#include <map>
#include "PointerTypes.h"
#include "AbstractProblem.h"

class ProblemCache {
public:
    virtual ~ProblemCache(){};
    void storeProblemWithNumberOfSolution(std::string problemIdentifier, integer numberOfSolution);
    bool hasProblemStored(std::string problemIdentifier);
    integer findNumberOfSolutionByProblem(std::string problemIdentifier);
    static ProblemCache* getInstance();
private:
    ProblemCache();
    std::map<std::string, integer> m_problemToNumberOfSolutionMap;
    static ProblemCache* instancePtr;
};

typedef ProblemCache* ProblemCachePtr;

#endif /* defined(__VNOI1__ProblemCache__) */
