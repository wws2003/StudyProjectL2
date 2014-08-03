//
//  BinClearTask.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "BinClearTask.h"
#include "Bin.h"

BinClearTask::BinClearTask(BinPtr pBin) : m_pBin(pBin){
    
}

//Override
void BinClearTask::execute() {
    m_pBin->clear();
}