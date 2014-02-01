//
//  SocketConnection.cpp
//  DocServer
//
//  Created by wws2003 on 1/14/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ConnectorSocketImpl.h"
#include <iostream>
#include <boost/bind.hpp>

ConnectorSocketImpl::ConnectorSocketImpl(SocketPtr socketPtr) : m_pSocketPtr(socketPtr), m_pOneTimeBuffer(new IOBuffer()) {
    
}

void ConnectorSocketImpl::cancel() {
    m_pSocketPtr->cancel();
}

ConnectorSocketImpl::ConnectorOperationErr ConnectorSocketImpl::readData(BufferPtr bufferPtr) {
    ErrorCode errorCode;
    assert(m_pSocketPtr->is_open());
    asyncReadSocket(bufferPtr, m_pOneTimeBuffer, errorCode, 0);
    return ERR_NONE;
}

SocketPtr ConnectorSocketImpl::getSocketPtr() {
    return m_pSocketPtr;
}

void ConnectorSocketImpl::asyncReadSocket(BufferPtr mainBufferPtr, IOBufferPtr bufferPtr, ErrorCodeRef errorCode, size_t byteReaded) {
    if (byteReaded > 0) {
        onDataReaded(mainBufferPtr, bufferPtr, byteReaded);
    }
    if (errorCode.value() != boost::system::errc::success) {
        return;
    }
    m_pSocketPtr->async_read_some(boost::asio::buffer(*bufferPtr)
                                  , boost::bind(&ConnectorSocketImpl::asyncReadSocket
                                             , this
                                             , mainBufferPtr
                                             , bufferPtr
                                             , boost::asio::placeholders::error
                                             , boost::asio::placeholders::bytes_transferred));
}

void ConnectorSocketImpl::onDataReaded(BufferPtr mainBufferPtr, const IOBufferPtr& ioBuffer, const size_t& numberOfByteReaded){
    appendBuffer(mainBufferPtr, ioBuffer->data(), numberOfByteReaded);
}