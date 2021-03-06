//
//  RequestAcceptorBoostImpl.h
//  DocServer
//
//  Created by wws2003 on 1/1/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestAcceptorBoostImpl__
#define __DocServer__RequestAcceptorBoostImpl__

#include <iostream>

#include "IRequestAcceptor.h"
#include "CommonTypes.h"
#include "IRequestFromSocketFactory.h"

class RequestAcceptorBoostImpl : public IRequestAcceptor{
public:
    RequestAcceptorBoostImpl(IRequestProcessorPtr requestProcessorPtr, IRequestExecutorFactoryPtr requestExecutorFactory, IRequestFromSocketFactoryPtr requestFromSocketFactoryPtr, int acceptPort);
    
    //@Override
    virtual int start();

private:
    //@Override
    virtual void run();
    
    void createIOService();
    
    void createTCPAcceptor();
    
    void async_accept(SocketPtr listeningSocketPtr);
    
    void onAccepted(SocketPtr socketPtr, ErrorCodeRef errorCode);
    
    IOServicePtr m_pIOService;
    TCPAcceptorPtr m_pTCPAcceptor;
    IRequestFromSocketFactoryPtr m_pRequestFromSocketFactory;
};

#endif /* defined(__DocServer__RequestAcceptorBoostImpl__) */
