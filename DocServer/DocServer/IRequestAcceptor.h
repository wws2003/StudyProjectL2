//
//  IRequestAcceptor.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef __DocServer__IRequestAcceptor__
#define __DocServer__IRequestAcceptor__

#include <iostream>

#include "IRunable.h"
#include "IRequest.h"
#include "IRequestProcessor.h"
#include "IRequestExecutorFactory.h"

class IRequestAcceptor : public IRunable {
public:
    
    IRequestAcceptor(IRequestProcessorPtr requestProcessorPtr, IRequestExecutorFactoryPtr requestExecutorFactory, int acceptPort);
    virtual ~IRequestAcceptor(){};
    
protected:
    
    /**To be called in the thread started by start().
     The result is only true/false: whether the request is added to the processor
     properly or not
     **/
    virtual bool onRequest(IRequestPtr newRequest);
    
    IRequestProcessorPtr m_pRequestProcessor;
    IRequestExecutorFactoryPtr m_pRequestExecutorFactory;
    
    int m_AcceptPort;
};

#endif /* defined(__DocServer__IRequestAcceptor__) */
