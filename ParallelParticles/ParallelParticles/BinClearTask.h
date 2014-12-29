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
    
    //@Override
    void* operator new (size_t size) throw (std::bad_alloc);
    
    //@Override
    void operator delete(void* objectPtr);
    
    //Override
    virtual void execute();
    
    static void refreshPool();
    
private:
    BinPtr m_pBin;
    
    static ObjectPoolPtr g_pObjectPool;
};

#endif /* defined(__ParallelParticles__BinClearTask__) */
