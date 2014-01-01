//
//  RequestFactory.h
//  DocServer
//
//  Created by wws2003 on 1/1/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestFactory__
#define __DocServer__RequestFactory__

#include <iostream>
#include "IRequest.h"
#include "CommonTypes.h"

class RequestFactory {
public:
    static IRequestPtr createRequestFromSocket(SocketPtr socket);
};

#endif /* defined(__DocServer__RequestFactory__) */
