//
//  IResponseSenderQueue.h
//  DocServer
//
//  Created by wws2003 on 12/31/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef __DocServer__IResponseSenderQueue__
#define __DocServer__IResponseSenderQueue__

#include <iostream>
#include "IResponseSender.h"
#include "Response.h"
#include "PointerDef.h"

class IResponseSenderQueue {
public:
    enum ResponseSenderQueueOperationErr {
        ERR_NONE = 0,
        ERR_PUSH_FAILED,
    };
    
    virtual ~IResponseSenderQueue(){};
    
    virtual bool isEmpty() = 0;
    virtual ResponseSenderQueueOperationErr pushResponseSender(IResponseSenderPtr responseSenderPtr) = 0;
    virtual IResponseSenderPtr front() = 0;
    virtual ResponseSenderQueueOperationErr popFront() = 0;
};

#endif /* defined(__DocServer__IResponseSenderQueue__) */
