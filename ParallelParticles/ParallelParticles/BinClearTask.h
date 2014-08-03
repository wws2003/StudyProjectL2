//
//  BinClearTask.h
//  ParallelParticles
//
//  Created by wws2003 on 7/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ParallelParticles__BinClearTask__
#define __ParallelParticles__BinClearTask__

#include <iostream>
#include "PPTypeDefs.h"
#include "TypeDefs.h"
#include "ITask.h"

class BinClearTask : public ITask {
public:
    BinClearTask(BinPtr pBin);
    virtual ~BinClearTask(){};
    
    //Override
    virtual void execute();
    
private:
    BinPtr m_pBin;

};

#endif /* defined(__ParallelParticles__BinClearTask__) */
