//
//  RequestExecutorFactorySimpleImpl.cpp
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestExecutorFactorySimpleImpl.h"
#include "RequestExecutorCountImpl.h"

IRequestExecutorPtr RequestExecutorFactorySimpleImpl::createRequestExecutor(IRequestPtr request) {
    return new RequestExecutorCountImpl(NULL, NULL);
}