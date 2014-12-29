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
    //Start the accepting loop
    boost::thread* acceptingThread = new boost::thread(boost::bind(&RequestAcceptorBoostImpl::run, this));
    acceptingThread->join();
    delete acceptingThread;
    return 0;
}

void RequestAcceptorBoostImpl::run() {
    /*Try to move calling to io_service run() method here to satisfy the requirement: Callback handler of
     io object must be called by the same thread which called io_service.run. But run is a blocking method
     -> paradox? 
    */
    
    //Currently do not know how to use one ioservice
    //IOServiceWorkPtr workPtr(new IOServiceWork(*m_pIOService));
    //m_pIOService->run();

    while (1) {
        //Use a temporal ioservice
        IOServicePtr connectingIOServicePtr(new IOService());
        
        //Create a new socket bound to the ioservice instance
        SocketPtr newListeningSocket(new Socket(*connectingIOServicePtr));
        
        /**Send async_accept/accept message to the acceptor instance.
           The following code is done in the second way (accepting synchronously)
         **/
        
        ErrorCode err;
        m_pTCPAcceptor->accept(*newListeningSocket, err);
        
        onAccepted(newListeningSocket, err);
    }
    
}

void RequestAcceptorBoostImpl::createIOService() {
    IOServicePtr servicePtr(new IOService());
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

