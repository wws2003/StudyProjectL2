//
//  PointerDef.h
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef DocServer_PointerDef_h
#define DocServer_PointerDef_h

#include <boost/shared_ptr.hpp>

class IRequest;
class IRequestAcceptor;
class IRequestExecutor;
class IRequestProcessor;
class IRequestExecutorQueue;
class IRequestPostExecutor;
class IRequestExecutorFactory;
class IConnector;
class IResponseSender;
class IResponseSenderQueue;
class IResponseProcessor;
class IResponseSenderFactory;

#if INORMAL_PTR==1
typedef IRequest* IRequestPtr;
typedef IRequestAcceptor* IRequestAcceptorPtr;
typedef IRequestExecutor* IRequestExecutorPtr;
typedef IRequestProcessor* IRequestProcessorPtr;
typedef IRequestExecutorQueue* IRequestExecutorQueuePtr;
typedef IRequestPostExecutor* IRequestPostExecutorPtr;
typedef IRequestExecutorFactory* IRequestExecutorFactoryPtr;
typedef IConnector* IConnectorPtr;
typedef IResponseSender* IResponseSenderPtr;
typedef IResponseSenderQueue* IResponseSenderQueuePtr;
typedef IResponseProcessor* IResponseProcessorPtr;
typedef IResponseSenderFactory* IResponseSenderFactoryPtr;
#endif

#endif
