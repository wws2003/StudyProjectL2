//
//  RequestFromSocketFactoryNormalImpl.h
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestFromSocketFactoryNormalImpl__
#define __DocServer__RequestFromSocketFactoryNormalImpl__

#include <iostream>
#include "IRequestFromSocketFactory.h"

class RequestFromSocketFactoryNormalImpl : public IRequestFromSocketFactory{
public:
    virtual ~RequestFromSocketFactoryNormalImpl(){};
    
    virtual IRequestPtr createRequestPtrFromSocketPtr(SocketPtr socketPtr);
};

#endif /* defined(__DocServer__RequestFromSocketFactoryNormalImpl__) */
