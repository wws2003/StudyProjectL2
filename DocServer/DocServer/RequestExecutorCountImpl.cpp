//
//  RequestExecutorCountImpl.cpp
//  DocServer
//
//  Created by wws2003 on 1/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "RequestExecutorCountImpl.h"

int RequestExecutorCountImpl::s_NumberOfRequest = 0;
boost::mutex RequestExecutorCountImpl::s_CountingMutex;

RequestExecutorCountImpl::RequestExecutorCountImpl(IRequestPtr requestPtr, IRequestPostExecutorPtr requestPostExecutorPtr) : IRequestExecutor(requestPtr, requestPostExecutorPtr){
   
}

ResponsePtr RequestExecutorCountImpl::execute() {
    boost::mutex::scoped_lock lock(s_CountingMutex);
    s_NumberOfRequest++;
    std::cout << "Number of request:" << s_NumberOfRequest << std::endl;
    if(m_pRequest != NULL) {
        std::list<std::string> requestParams;
        m_pRequest->parseRequestParams(requestParams);
        for (std::list<std::string>::const_iterator paramIter = requestParams.begin(); paramIter != requestParams.end(); paramIter++) {
            std::cout << *paramIter << std::endl;
        }
    }
    return NULL;
}
