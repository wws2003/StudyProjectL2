//
//  IRequestPostExecutor.h
//  DocServer
//
//  Created by wws2003 on 12/31/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef DocServer_IRequestPostExecutor_h
#define DocServer_IRequestPostExecutor_h

#include "IRequest.h"
#include "Response.h"

class IRequestPostExecutor {
public:
    virtual ~IRequestPostExecutor(){};
    
    virtual bool onRequestExecutionEnd(ResponsePtr responsePtr) = 0;
};

#if INORMAL_PTR
    typedef IRequestPostExecutor* IRequestPostExecutorPtr;
#endif

#endif
