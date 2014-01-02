//
//  RequestExecutorCountImpl.cpp
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestExecutorCountImpl.h"

RequestExecutorCountImpl::RequestExecutorCountImpl(IRequestPtr requestPtr, IRequestPostExecutorPtr requestPostExecutorPtr) : IRequestExecutor(requestPtr, requestPostExecutorPtr), m_NumberOfRequest(0){
   
}

ResponsePtr RequestExecutorCountImpl::execute() {
    m_NumberOfRequest++;
    std::cout << "Number of request:" << m_NumberOfRequest << std::endl;
    return NULL;
}
