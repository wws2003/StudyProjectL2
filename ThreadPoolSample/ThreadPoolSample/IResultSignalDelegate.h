//
//  IResultSignalDelegate.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/26/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ThreadPoolSample_IResultSignalDelegate_h
#define ThreadPoolSample_IResultSignalDelegate_h

#include "TypeDefs.h"

class IResultSignalDelegate {
public:
    IResultSignalDelegate(){};
    virtual ~IResultSignalDelegate(){};
    
    virtual void reportResult(ResultStore& resultStoreRef, const ResultPtr resultPtr) = 0;
};

#endif
