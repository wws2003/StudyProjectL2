//
//  RequestFromSocketFactoryNormalImpl.cpp
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#if INORMAL_PTR==1
#include "RequestFromSocketFactoryNormalImpl.h"
#include "RequestFromSocket.h"

IRequestPtr RequestFromSocketFactoryNormalImpl::createRequestPtrFromSocketPtr(SocketPtr socketPtr) {
    return new RequestFromSocket(socketPtr);
}
#endif