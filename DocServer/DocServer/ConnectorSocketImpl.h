//
//  SocketConnection.h
//  DocServer
//
//  Created by wws2003 on 1/14/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__SocketConnection__
#define __DocServer__SocketConnection__

#include <iostream>
#include "CommonTypes.h"
#include "IConnector.h"
#include <boost/enable_shared_from_this.hpp>

class ConnectorSocketImpl : public IConnector {
public:
    ConnectorSocketImpl(SocketPtr socketPtr);
    virtual ~ConnectorSocketImpl(){};
    
    //@Override
    void cancel();
    
    //@Override
    ConnectorOperationErr readData(BufferPtr bufferPtr);
    
    SocketPtr getSocketPtr();
    
private:
    void asyncReadSocket(BufferPtr mainBufferPtr, IOBuffer buffer, ErrorCodeRef errorCode, size_t byteReaded);
    void onDataReaded(BufferPtr mainBufferPtr, const IOBuffer& ioBuffer, const size_t& numberOfByteReaded);
    
    SocketPtr m_pSocketPtr;
};

#endif /* defined(__DocServer__SocketConnection__) */
