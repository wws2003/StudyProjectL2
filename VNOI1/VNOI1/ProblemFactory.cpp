//
//  ProblemFactory.cpp
//  VNOI1
//
//  Created by wws2003 on 3/11/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ProblemFactory.h"
#include "ConcreteProblem.h"
#include "Cell.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>

AbstractProblemPtr ProblemFactory::getProblemPtr(integer numberOfRow, integer numberOfColumn, const Cells blockedCells) {
    ConcreteProblemPtr problemPtr = new ConcreteProblem(numberOfRow, numberOfColumn);
    problemPtr->regiterBlockedCells(blockedCells);
    return problemPtr;
}

AbstractProblemPtr ProblemFactory::getProblemPtr(const char* fileName) {
    std::ifstream inFile(fileName);
    const char BLOCKED_CHAR = '#';
    
    //Read number of row and column
    integer numberOfRow;
    integer numberOfColumn;
    Cells blockedCells;
    
    std::string line;
    integer lineNumber = 0;
    while (std::getline(inFile, line)) {
        printf("%s\n", line.c_str());
        if (lineNumber == 0) {
            std::istringstream iss(line);
            iss >> numberOfRow >> numberOfColumn;
        }
        else {
            for (integer column = 0; column < numberOfColumn; column++) {
                if (line.c_str()[column] == BLOCKED_CHAR) {
                    Cell blockedCell;
                    blockedCell.row = lineNumber - 1;
                    blockedCell.column = column;
                    blockedCells.push_back(blockedCell);
                }
            }
        }
        lineNumber++;
    }
    ConcreteProblemPtr problemPtr = new ConcreteProblem(numberOfRow, numberOfColumn);
   
    problemPtr->regiterBlockedCells(blockedCells);
    return problemPtr;
}