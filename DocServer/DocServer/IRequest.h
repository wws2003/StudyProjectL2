//
//  IRequest.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef DocServer_IRequest_h
#define DocServer_IRequest_h

#include <list>
#include <string>

#include "IConnector.h"
#include "PointerDef.h"

class IRequest {
public:
    enum RequestOperationErr {
        ERR_NONE = 0,
        ERR_PARSING
    };
    IRequest(IConnectorPtr connectorPtr);
    virtual ~IRequest(){};
    
    virtual int getRequestType() = 0;
    virtual RequestOperationErr parseRequestParams(std::list<std::string>& params) = 0;
    virtual IConnectorPtr getConnectorPtr();
    
protected:
    IConnectorPtr m_pConnector;
};

#endif
