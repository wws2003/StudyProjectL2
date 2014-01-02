//
//  IResponseSender.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef DocServer_IResponseSender_h
#define DocServer_IResponseSender_h

#include "Response.h"
#include "PointerDef.h"

class IResponseSender {
public:
    enum ResponseSenderOperationErr {
        ERR_NONE = 0,
        ERR_CANT_SEND
    };
    
    IResponseSender(ResponsePtr responsePtr);
    virtual ~IResponseSender(){};

    virtual ResponseSenderOperationErr sendResponse() = 0;
    
protected:
    ResponsePtr m_pResponse;
};

#endif
