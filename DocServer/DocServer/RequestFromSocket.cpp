//
//  RequestFromSocket.cpp
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestFromSocket.h"
#include "SocketConnector.h"
#include <boost/bind.hpp>
#include <boost/asio/deadline_timer.hpp>

RequestFromSocket::RequestFromSocket(SocketPtr socketPtr) : IRequest(socketPtr2ConnectorPtr(socketPtr)) {
    assert(socketPtr->is_open());
    ErrorCode ec;
    size_t numberOfByteRead = 0;
    
    IOServiceRef ioServiceForTimer = socketPtr->get_io_service();
    boost::asio::deadline_timer timer(ioServiceForTimer);
    
    //Wait for 10s to read data on the socket
    timer.expires_from_now(boost::posix_time::seconds(10));
    
    //Register invocation onTimedOut at deadline
    timer.async_wait(boost::bind(&RequestFromSocket::onTimedOut, this));
    //timer.wait();
    
    IOBuffer buffer;
    asyncReadSocket(socketPtr, buffer, ec, numberOfByteRead);
    
    ioServiceForTimer.run();
}

int RequestFromSocket::getRequestType() {
    return 0;
}

void RequestFromSocket::asyncReadSocket(SocketPtr socketPtr, IOBuffer buffer, ErrorCodeRef errorCode, size_t byteReaded) {
    if (byteReaded > 0) {
        onDataReaded(buffer, byteReaded);
    }
    if (errorCode.value() != boost::system::errc::success) {
        return;
    }
    assert(socketPtr->is_open());
    socketPtr->async_read_some(boost::asio::buffer(buffer)
                               , boost::bind(&RequestFromSocket::asyncReadSocket
                                             , this
                                             , socketPtr
                                             , boost::ref(buffer)
                                             , boost::asio::placeholders::error
                                             , boost::asio::placeholders::bytes_transferred));
}

void RequestFromSocket::onTimedOut() {
    std::cout << "Timed out" << std::endl;
    m_pConnector->cancel();
}

void RequestFromSocket::onDataReaded(const IOBuffer& ioBuffer, const size_t&  numberOfByteReaded) {
    std::string param(ioBuffer.data(), numberOfByteReaded);
    std::cout << "Number of bytes readed " << numberOfByteReaded << std::endl;
    m_TmpParams.push_back(param);
}

IRequest::RequestOperationErr RequestFromSocket::parseRequestParams(std::list<std::string>& params) {
    params.insert(params.begin(), m_TmpParams.begin(), m_TmpParams.end());
    return ERR_NONE;
}

IConnectorPtr RequestFromSocket::socketPtr2ConnectorPtr(SocketPtr socketPtr) {
    IConnectorPtr connectorPtr(new SocketConnector(socketPtr));
    return connectorPtr;
}