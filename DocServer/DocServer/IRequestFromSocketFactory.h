//
//  IRequestFromSocketFactory.h
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__IRequestFromSocketFactory__
#define __DocServer__IRequestFromSocketFactory__

#include <iostream>
#include "PointerDef.h"
#include "IRequest.h"
#include "CommonTypes.h"
#include <boost/shared_ptr.hpp>

class IRequestFromSocketFactory {
public:
    virtual ~IRequestFromSocketFactory(){};
    
    virtual IRequestPtr createRequestPtrFromSocketPtr(SocketPtr socketPtr) = 0;
};

typedef IRequestFromSocketFactory* IRequestFromSocketFactoryPtr;

#endif /* defined(__DocServer__IRequestFromSocketFactory__) */
