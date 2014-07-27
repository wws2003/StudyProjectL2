//
//  IResultDelegatePairFactory.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ThreadPoolSample_IResultDelegatePairFactory_h
#define ThreadPoolSample_IResultDelegatePairFactory_h

#include "TypeDefs.h"

class IResultDelegatePairFactory {
public:
    IResultDelegatePairFactory(){};
    virtual ~IResultDelegatePairFactory(){};

    virtual IResultDelegatePtrPair getResultDelegatePtrPair() = 0;
};

#endif
