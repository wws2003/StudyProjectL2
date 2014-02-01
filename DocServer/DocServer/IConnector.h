//
//  IConnector.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef DocServer_IConnector_h
#define DocServer_IConnector_h

#include "PointerDef.h"
#include "Buffer.h"

class IConnector {
public:
    enum ConnectorOperationErr{
        ERR_NONE,
        ERR_TIME_OUT
    };
    
    virtual ~IConnector(){};
    
    virtual void cancel() = 0;
    virtual ConnectorOperationErr readData(BufferPtr bufferPtr) = 0;
};

#endif
