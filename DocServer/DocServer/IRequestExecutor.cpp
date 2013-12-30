//
//  IRequestExecutor.cpp
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include "IRequestExecutor.h"

IRequestExecutor::IRequestExecutor(IRequestPtr requestPtr, IRequestPostExecutorPtr requestPostExecutorPtr) : m_pRequest(requestPtr), m_pRequestPostExecutor(requestPostExecutorPtr) {
    
}

void IRequestExecutor::executeRequest() {
    ResponsePtr responsePtr = execute();
    m_pRequestPostExecutor->onRequestExecutionEnd(responsePtr);
}