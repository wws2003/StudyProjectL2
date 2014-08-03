//
//  BinClearTask.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "BinClearTask.h"
#include "Bin.h"
#include <iostream>

BinClearTask::BinClearTask(BinPtr pBin) : m_pBin(pBin){
    
}

//Override
void BinClearTask::execute() {
    //std::cout << "Executing task BinClearTask \n";
    m_pBin->clear();
}