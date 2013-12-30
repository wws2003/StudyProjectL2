//
//  IRequestExecutorFactory.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef __DocServer__IRequestExecutorFactory__
#define __DocServer__IRequestExecutorFactory__

#include <iostream>

#include "IRequestExecutor.h"
#include "IRequest.h"

class IRequestExecutorFactory {
public:
    virtual ~IRequestExecutorFactory(){};
    virtual IRequestExecutorPtr createRequestExecutor(IRequestPtr request) = 0;
};

#if INORMAL_PTR == 1
typedef IRequestExecutorFactory* IRequestExecutorFactoryPtr;
#endif

#endif /* defined(__DocServer__IRequestExecutorFactory__) */
