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

class RequestAcceptorBoostImpl : public IRequestAcceptor{
public:
    RequestAcceptorBoostImpl(IRequestProcessorPtr requestProcessorPtr, IRequestExecutorFactoryPtr requestExecutorFactory, int acceptPort);
    
    //@Override
    virtual int start();
    
    //@Override
    virtual void run();

private:
    void createIOService();
    
    void createTCPAcceptor();
    
    void async_accept(SocketPtr listeningSocketPtr);
    
    void onAccepted(SocketPtr socketPtr, ErrorCodeRef errorCode);
    
    IOServicePtr m_pIOService;
    TCPAcceptorPtr m_pTCPAcceptor;
};

#endif /* defined(__DocServer__RequestAcceptorBoostImpl__) */
