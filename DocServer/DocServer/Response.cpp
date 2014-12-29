//
//  IResponse.cpp
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include "Response.h"

Response::Response(ResponseStatus status, BufferPtr bufferPtr, IConnectorPtr connectorPtr) : m_Status(status), m_pBuffer(bufferPtr), m_pConnector(connectorPtr){
    
}

Response::~Response() {
    freeBuffer(m_pBuffer);
}

Response::ResponseStatus Response::getStatus() {
    return m_Status;
}

BufferPtr Response::getBufferPtr() {
    return m_pBuffer;
}

IConnectorPtr Response::getConnectorPtr() {
    return m_pConnector;
}