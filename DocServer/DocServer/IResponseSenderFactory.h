//
//  IResponseSenderFactory.h
//  DocServer
//
//  Created by wws2003 on 12/31/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef DocServer_IResponseSenderFactory_h
#define DocServer_IResponseSenderFactory_h

#include "IResponseSender.h"
#include "Response.h"
#include "PointerDef.h"

class IResponseSenderFactory {
public:
    virtual ~IResponseSenderFactory(){};
    virtual IResponseSenderPtr createResponseSenderPtr(ResponsePtr responsePtr) = 0;
};

#endif
