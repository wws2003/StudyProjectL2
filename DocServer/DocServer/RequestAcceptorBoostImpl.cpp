//
//  RequestAcceptorBoostImpl.cpp
//  DocServer
//
//  Created by wws2003 on 1/1/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestAcceptorBoostImpl.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>

RequestAcceptorBoostImpl::RequestAcceptorBoostImpl(IRequestProcessorPtr requestProcessorPtr, IRequestExecutorFactoryPtr requestExecutorFactory, IRequestFromSocketFactoryPtr requestFromSocketFactoryPtr, int acceptPort) : IRequestAcceptor(requestProcessorPtr, requestExecutorFactory, acceptPort), m_pRequestFromSocketFactory(requestFromSocketFactoryPtr){
    
    createIOService();
    
    createTCPAcceptor();
}

int RequestAcceptorBoostImpl::start() {
    
    boost::thread_group threadGroups;
    //Start ioservice thread
    boost::thread* ioServiceThread = new boost::thread(boost::bind(&boost::asio::io_service::run, m_pIOService));
    
    //Start the accepting loop
    boost::thread* acceptingThread = new boost::thread(boost::bind(&RequestAcceptorBoostImpl::run, this));
    
    threadGroups.add_thread(ioServiceThread);
    threadGroups.add_thread(acceptingThread);
    
    threadGroups.join_all();
    
    delete ioServiceThread;
    delete acceptingThread;
    
    return 0;
}

void RequestAcceptorBoostImpl::run() {
    while (1) {
        //Create a new socket bound to the ioservice instance
        SocketPtr newListeningSocket(new Socket(*m_pIOService));
        
        /**Send async_accept/accept message to the acceptor instance.
           The previous code is done in the second way (accepting synchronously)
         **/
        
        ErrorCode err;
        m_pTCPAcceptor->accept(*newListeningSocket, err);
        
        onAccepted(newListeningSocket, err);
    }
    
}

void RequestAcceptorBoostImpl::createIOService() {
    IOServicePtr servicePtr(new boost::asio::io_service());
    m_pIOService = servicePtr;
}

void RequestAcceptorBoostImpl::createTCPAcceptor() {
    using namespace boost::asio::ip;
    TCPAcceptorPtr tcpAcceptorPtr(new tcp::acceptor(*m_pIOService, tcp::endpoint(tcp::v4(), m_AcceptPort)));
    m_pTCPAcceptor = tcpAcceptorPtr;
}

void RequestAcceptorBoostImpl::async_accept(SocketPtr listeningSocketPtr) {
    //Not implemented yet
}


void RequestAcceptorBoostImpl::onAccepted(SocketPtr socketPtr, ErrorCodeRef errorCode) {
    if (errorCode.value() == boost::system::errc::success) {
        IRequestPtr requestPtr = m_pRequestFromSocketFactory->createRequestPtrFromSocketPtr(socketPtr);
        onRequest(requestPtr);
    }
}

