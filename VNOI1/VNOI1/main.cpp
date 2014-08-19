//
//  main.cpp
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <iostream>
#include "ProblemFactory.h"
#include "Cell.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";    
    AbstractProblemPtr problemPtr = ProblemFactory::getProblemPtr("/Users/wws2003/Desktop/Apps/VNOI1/input.txt");
    integer numberOfSolution = problemPtr->calculateNumberOfSolutions();
    std::cout << "Number of solution:" << numberOfSolution << "\n";
    
    delete problemPtr;
    return 0;
}

