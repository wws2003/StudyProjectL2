//
//  ProblemCache.cpp
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ProblemCache.h"
#include <algorithm>
#include <assert.h>

ProblemCache* ProblemCache::instancePtr = NULL;

void ProblemCache::storeProblemWithNumberOfSolution(std::string problemIdentifier, integer numberOfSolution) {
    m_problemToNumberOfSolutionMap.insert(std::pair<std::string, integer>(problemIdentifier, numberOfSolution));
}

bool ProblemCache::hasProblemStored(std::string problemIdentifier) {
    return m_problemToNumberOfSolutionMap.find(problemIdentifier) != m_problemToNumberOfSolutionMap.end();
}

integer ProblemCache::findNumberOfSolutionByProblem(std::string problemIdentifier) {
    if (m_problemToNumberOfSolutionMap.find(problemIdentifier) == m_problemToNumberOfSolutionMap.end()) {
        assert(false);
    }
    return m_problemToNumberOfSolutionMap[problemIdentifier];
}

ProblemCache::ProblemCache() {
    
}

ProblemCache* ProblemCache::getInstance() {
    if (instancePtr == NULL) {
        instancePtr = new ProblemCache();
    }
    return instancePtr;
}