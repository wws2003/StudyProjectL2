//
//  SocketConnection.h
//  DocServer
//
//  Created by wws2003 on 1/14/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __DocServer__SocketConnection__
#define __DocServer__SocketConnection__

#include <iostream>
#include "CommonTypes.h"
#include "IConnector.h"
#include <boost/enable_shared_from_this.hpp>

class SocketConnector : public IConnector, public boost::enable_shared_from_this<SocketConnector> {
public:
    SocketConnector(SocketPtr socketPtr);
    virtual ~SocketConnector(){};
    
    //@Override
    void cancel();
    
    SocketPtr getSocketPtr();
private:
    SocketPtr m_pSocketPtr;
};

#endif /* defined(__DocServer__SocketConnection__) */
