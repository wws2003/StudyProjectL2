//
//  SocketConnection.cpp
//  DocServer
//
//  Created by wws2003 on 1/14/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "SocketConnector.h"

SocketConnector::SocketConnector(SocketPtr socketPtr) : m_pSocketPtr(socketPtr){
    
}

void SocketConnector::cancel() {
    m_pSocketPtr->cancel();
}

SocketPtr SocketConnector::getSocketPtr() {
    return m_pSocketPtr;
}