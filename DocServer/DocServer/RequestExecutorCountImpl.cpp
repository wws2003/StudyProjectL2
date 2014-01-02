//
//  RequestExecutorCountImpl.cpp
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestExecutorCountImpl.h"

int RequestExecutorCountImpl::s_NumberOfRequest = 0;

RequestExecutorCountImpl::RequestExecutorCountImpl(IRequestPtr requestPtr, IRequestPostExecutorPtr requestPostExecutorPtr) : IRequestExecutor(requestPtr, requestPostExecutorPtr){
   
}

ResponsePtr RequestExecutorCountImpl::execute() {
    boost::mutex::scoped_lock lock(m_CountingMutex);
    s_NumberOfRequest++;
    std::cout << "Number of request:" << s_NumberOfRequest << std::endl;
    return NULL;
}
