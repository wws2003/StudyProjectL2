//
//  RequestExecutorFactorySimpleImpl.h
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestExecutorFactorySimpleImpl__
#define __DocServer__RequestExecutorFactorySimpleImpl__

#include <iostream>
#include "IRequestExecutorFactory.h"

class RequestExecutorFactorySimpleImpl : public IRequestExecutorFactory{
public:
    virtual ~RequestExecutorFactorySimpleImpl(){};
    virtual IRequestExecutorPtr createRequestExecutor(IRequestPtr request);
};

#endif /* defined(__DocServer__RequestExecutorFactorySimpleImpl__) */
