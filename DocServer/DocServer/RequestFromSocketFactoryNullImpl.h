//
//  IRequestFactoryFromSocketNullImpl.h
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef DocServer_IRequestFactoryFromSocketNullImpl_h
#define DocServer_IRequestFactoryFromSocketNullImpl_h

#include "IRequestFromSocketFactory.h"

class RequestFromSocketFactoryNullImpl : public IRequestFromSocketFactory{
public:
    virtual ~RequestFromSocketFactoryNullImpl(){};
    
    virtual IRequestPtr createRequestPtrFromSocketPtr(SocketPtr socketPtr);
};
#endif
