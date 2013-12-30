//
//  IResponse.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef __DocServer__IResponse__
#define __DocServer__IResponse__

#include <iostream>
#include "IConnector.h"
#include "Buffer.h"

class Response {
public:
    enum ResponseStatus {
        ERR_NONE = 0,
        ERR_EXECUTE_FAILED
    };
    Response(ResponseStatus status, BufferPtr bufferPtr, IConnectorPtr connectorPtr);
    virtual ~Response();
    
    virtual ResponseStatus getStatus();
    virtual BufferPtr getBufferPtr();
    virtual IConnectorPtr getConnectorPtr();
    
protected:
    ResponseStatus m_Status;
    BufferPtr m_pBuffer;
    IConnectorPtr m_pConnector;
};

#if INORMAL_PTR==1
    typedef Response* ResponsePtr;
#endif

#endif /* defined(__DocServer__IResponse__) */
