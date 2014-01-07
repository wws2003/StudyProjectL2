//
//  RequestFromSocket.cpp
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestFromSocket.h"
#include <boost/bind.hpp>

RequestFromSocket::RequestFromSocket(SocketPtr socketPtr) : IRequest(socketPtr2ConnectorPtr(socketPtr)) {
    assert(socketPtr->is_open());
    ErrorCode ec;
    size_t numberOfByteRead = 0;
    
    //TODO Create timer
    
    /*do {
        IOBuffer buffer;
        numberOfByteRead = socketPtr->read_some(boost::asio::buffer(buffer), ec);
        std::string param(buffer.data());
        m_TmpParams.push_back(param);
    }
    while (numberOfByteRead > 0);*/

    //TODO How to wait async method ?
    asyncReadSocket(socketPtr, ec, numberOfByteRead);
}

int RequestFromSocket::getRequestType() {
    return 0;
}

void RequestFromSocket::asyncReadSocket(SocketPtr socketPtr, ErrorCodeRef errorCode, size_t byteReaded) {
    if (byteReaded > 0) {
        std::string param(oneTimeBuffer.data(), byteReaded);
        std::cout << "Read: " << param << std::endl;
        m_TmpParams.push_back(param);
    }
    if (errorCode.value() != boost::system::errc::success) {
        return;
    }
    socketPtr->async_read_some(boost::asio::buffer(oneTimeBuffer)
                               , boost::bind(&RequestFromSocket::asyncReadSocket
                                             , this
                                             , socketPtr
                                             , boost::asio::placeholders::error
                                             , boost::asio::placeholders::bytes_transferred));
}

IRequest::RequestOperationErr RequestFromSocket::parseRequestParams(std::list<std::string>& params) {
    params.insert(params.begin(), m_TmpParams.begin(), m_TmpParams.end());
    return ERR_NONE;
}

IConnectorPtr RequestFromSocket::socketPtr2ConnectorPtr(SocketPtr socketPtr) {
    return NULL;
}