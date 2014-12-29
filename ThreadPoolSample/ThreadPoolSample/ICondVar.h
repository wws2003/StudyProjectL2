//
//  ICondVar.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ThreadPoolSample_ICondVar_h
#define ThreadPoolSample_ICondVar_h

#include "TypeDefs.h"

class ICondVar {
public:
    ICondVar(){};
    virtual ~ICondVar(){};
    
    virtual void wait(IMutexPtr mutexPtr) = 0;
    virtual CondVarErrorCode signal() = 0;
    virtual CondVarErrorCode broadcast() = 0;
};

#endif
