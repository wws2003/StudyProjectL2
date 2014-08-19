//
//  ResultDelegatePairFactoryImpl.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__ResultDelegatePairFactoryImpl__
#define __ThreadPoolSample__ResultDelegatePairFactoryImpl__

#include <iostream>
#include "IResultDelegatePairFactory.h"

class ResultDelegatePairFactoryImpl : public IResultDelegatePairFactory {
public:
    ResultDelegatePairFactoryImpl(){};
    virtual ~ResultDelegatePairFactoryImpl(){};
    
    //@Override
    virtual IResultDelegatePtrPair getResultDelegatePtrPair();
};

#endif /* defined(__ThreadPoolSample__ResultDelegatePairFactoryImpl__) */
