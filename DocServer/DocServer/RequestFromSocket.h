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
#include "IRequest.h"
#include "CommonTypes.h"

class RequestFromSocket : public IRequest {
public:
    RequestFromSocket(SocketPtr socketPtr);
    virtual ~RequestFromSocket(){};
    
    virtual int getRequestType();
    virtual RequestOperationErr parseRequestParams(std::list<std::string>& params);
    
private:
    void asyncReadSocket(SocketPtr socketPtr, ErrorCodeRef errorCode, size_t byteReaded);
    static IConnectorPtr socketPtr2ConnectorPtr(SocketPtr socketPtr);
    
    std::list<std::string> m_TmpParams;
    
    IOBuffer oneTimeBuffer;
};

#endif /* defined(__DocServer__RequestFromSocket__) */
