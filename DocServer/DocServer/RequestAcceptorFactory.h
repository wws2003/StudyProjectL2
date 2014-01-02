//
//  RequestAcceptorFactory.h
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestAcceptorFactory__
#define __DocServer__RequestAcceptorFactory__

#include <iostream>
#include "IRequestAcceptor.h"
#include "PointerDef.h"

class RequestAcceptorFactory {
public:
    static IRequestAcceptorPtr createRequestAcceptor(int portNumber);
};

#endif /* defined(__DocServer__RequestAcceptorFactory__) */
