//
//  RequestExecutorCountImpl.h
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__RequestExecutorCountImpl__
#define __DocServer__RequestExecutorCountImpl__

#include <iostream>
#include "IRequestExecutor.h"
#include <boost/thread/mutex.hpp>

class RequestExecutorCountImpl : public IRequestExecutor {
public:
    RequestExecutorCountImpl(IRequestPtr requestPtr, IRequestPostExecutorPtr requestPostExecutorPtr);
    virtual ~RequestExecutorCountImpl(){};
    
    ResponsePtr execute();
    
private:
    static int s_NumberOfRequest;
    static boost::mutex s_CountingMutex;
};

#endif /* defined(__DocServer__RequestExecutorCountImpl__) */
