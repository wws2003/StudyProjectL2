//
//  SocketConnection.cpp
//  DocServer
//
//  Created by wws2003 on 1/14/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "SocketConnector.h"
#include <iostream>
#include <boost/bind.hpp>

SocketConnector::SocketConnector(SocketPtr socketPtr) : m_pSocketPtr(socketPtr){
    
}

void SocketConnector::cancel() {
    m_pSocketPtr->cancel();
}

SocketConnector::ConnectorOperationErr SocketConnector::readData(BufferPtr bufferPtr) {
    IOBuffer oneTimeBuffer;
    ErrorCode errorCode;
    assert(m_pSocketPtr->is_open());
    asyncReadSocket(bufferPtr, oneTimeBuffer, errorCode, 0);
    return ERR_NONE;
}

SocketPtr SocketConnector::getSocketPtr() {
    return m_pSocketPtr;
}

void SocketConnector::asyncReadSocket(BufferPtr mainBufferPtr, IOBuffer buffer, ErrorCodeRef errorCode, size_t byteReaded) {
    if (byteReaded > 0) {
        onDataReaded(mainBufferPtr, buffer, byteReaded);
    }
    if (errorCode.value() != boost::system::errc::success) {
        return;
    }
    m_pSocketPtr->async_read_some(boost::asio::buffer(buffer)
                                  , boost::bind(&SocketConnector::asyncReadSocket
                                             , this
                                             , boost::ref(mainBufferPtr)
                                             , boost::ref(buffer)
                                             , boost::asio::placeholders::error
                                             , boost::asio::placeholders::bytes_transferred));
}

void SocketConnector::onDataReaded(BufferPtr mainBufferPtr, const IOBuffer& ioBuffer, const size_t& numberOfByteReaded){
    appendBuffer(mainBufferPtr, ioBuffer.data(), numberOfByteReaded);
}