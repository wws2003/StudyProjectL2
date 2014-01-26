//
//  RequestFromSocket.cpp
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestFromSocket.h"
#include "ConnectorSocketImpl.h"
#include <boost/bind.hpp>
#include <boost/asio/deadline_timer.hpp>

RequestFromSocket::RequestFromSocket(SocketPtr socketPtr) : IRequest(socketPtr2ConnectorPtr(socketPtr)), m_pReadBufferPtr(NULL) {
    assert(socketPtr->is_open());
    
    IOServiceRef ioServiceForTimer = socketPtr->get_io_service();
    boost::asio::deadline_timer timer(ioServiceForTimer);
    
    //Wait for 3s to read data on the socket
    timer.expires_from_now(boost::posix_time::seconds(3));
    
    //Register invocation onTimedOut at deadline
    timer.async_wait(boost::bind(&RequestFromSocket::onTimedOut, this));
    //timer.wait();
    
    m_pReadBufferPtr = new Buffer();
    initBuffer(m_pReadBufferPtr);
    m_pConnector->readData(m_pReadBufferPtr);
    
    ioServiceForTimer.run();
}

RequestFromSocket::~RequestFromSocket() {
    freeBuffer(m_pReadBufferPtr);
    delete m_pReadBufferPtr;
}

int RequestFromSocket::getRequestType() {
    return 0;
}

void RequestFromSocket::onTimedOut() {
    std::cout << "Timed out" << std::endl;
    m_pConnector->cancel();
    std::cout << "Readed buffer length: " << m_pReadBufferPtr->length << std::endl;
}

IRequest::RequestOperationErr RequestFromSocket::parseRequestParams(std::list<std::string>& params) {
    //TODO Parse params from m_tmpBuffer
    return ERR_NONE;
}

IConnectorPtr RequestFromSocket::socketPtr2ConnectorPtr(SocketPtr socketPtr) {
    IConnectorPtr connectorPtr(new ConnectorSocketImpl(socketPtr));
    return connectorPtr;
}