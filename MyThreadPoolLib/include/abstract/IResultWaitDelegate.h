//
//  IResultWaitDelegate.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/26/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ThreadPoolSample_IResultWaitDelegate_h
#define ThreadPoolSample_IResultWaitDelegate_h

#include "TypeDefs.h"

class IResultWaitDelegate {
public:
    IResultWaitDelegate(){};
    virtual ~IResultWaitDelegate(){};
    
    virtual void waitForResults(const ResultStore& resultStoreRef, const unsigned int numberOfJobTodo) = 0;
};

#endif
