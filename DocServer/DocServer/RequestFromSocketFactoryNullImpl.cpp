//
//  IRequestFromSocketFactoryNullImpl.cpp
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#if INORMAL_PTR==1
#include "RequestFromSocketFactoryNullImpl.h"

IRequestPtr RequestFromSocketFactoryNullImpl::createRequestPtrFromSocketPtr(SocketPtr socketPtr) {
    return NULL;
}
#endif
