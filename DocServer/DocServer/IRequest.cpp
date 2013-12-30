//
//  IRequest.cpp
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include "IRequest.h"

IRequest::IRequest(IConnectorPtr connectorPtr) : m_pConnector(connectorPtr) {
    
}

IConnectorPtr IRequest::getConnectorPtr() {
    return m_pConnector;
}