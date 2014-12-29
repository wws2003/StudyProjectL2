//
//  ISubTaskDelegate.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/23/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ThreadPoolSample_ISubTaskDelegate_h
#define ThreadPoolSample_ISubTaskDelegate_h

#include "TypeDefs.h"

class ISubTaskDelegate {
public:
    ISubTaskDelegate(){};
    virtual ~ISubTaskDelegate(){};
    
    //Return number of subTasks need to wait
    virtual unsigned int executeSubTasks(const AbstractRecursiveTaskPtrs& subTaskPtrs) = 0;
    
};

#endif
