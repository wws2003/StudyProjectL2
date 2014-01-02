//
//  RequestProcessorFactory.h
//  DocServer
//
//  Created by wws2003 on 1/3/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestProcessorFactory__
#define __DocServer__RequestProcessorFactory__

#include <iostream>
#include "IRequestProcessor.h"

class RequestProcessorFactory {
public:
    static IRequestProcessorPtr createRequestProcessor();
};

#endif /* defined(__DocServer__RequestProcessorFactory__) */
