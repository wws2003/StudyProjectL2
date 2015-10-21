//
//  PCondVar.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__PCondVar__
#define __ThreadPoolSample__PCondVar__

#include <iostream>
#include <pthread.h>
#include "ICondVar.h"

class PCondVar : public ICondVar {
public:
    PCondVar();
    virtual ~PCondVar();
    
    //@Override
    virtual void wait(MutexPtr mutexPtr);
    //@Override
    virtual CondVarErrorCode signal();
    //@Override
    virtual CondVarErrorCode broadcast();

private:
    pthread_cond_t m_condVar;
};


#endif /* defined(__ThreadPoolSample__PCondVar__) */
