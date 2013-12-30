//
//  IRequestExecutor.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef __DocServer__IRequestExecutor__
#define __DocServer__IRequestExecutor__

#include <iostream>

#include "IRequest.h"
#include "IRequestPostExecutor.h"
#include "Response.h"

class IRequestExecutor {
public:
    IRequestExecutor(IRequestPtr requestPtr, IRequestPostExecutorPtr requestPostExecutorPtr);
    virtual ~IRequestExecutor(){};
    
    virtual void executeRequest();
    
protected:
    virtual ResponsePtr execute() = 0;
    
    IRequestPtr m_pRequest;
    IRequestPostExecutorPtr m_pRequestPostExecutor;
};

#if INORMAL_PTR == 1
typedef IRequestExecutor* IRequestExecutorPtr;
#endif

#endif /* defined(__DocServer__IRequestExecutor__) */
