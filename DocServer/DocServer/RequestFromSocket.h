//
//  RequestFromSocket.h
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestFromSocket__
#define __DocServer__RequestFromSocket__

#include <iostream>
#include <boost/enable_shared_from_this.hpp>
#include "Buffer.h"
#include "IRequest.h"
#include "CommonTypes.h"

class RequestFromSocket : public IRequest {
public:
    RequestFromSocket(SocketPtr socketPtr);
    virtual ~RequestFromSocket();
    
    virtual int getRequestType();
    virtual RequestOperationErr parseRequestParams(std::list<std::string>& params);
    
private:
    void onTimedOut();
    
    static IConnectorPtr socketPtr2ConnectorPtr(SocketPtr socketPtr);
    
    BufferPtr m_pReadBufferPtr ;
};

#endif /* defined(__DocServer__RequestFromSocket__) */
