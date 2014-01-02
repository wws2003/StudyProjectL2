//
//  main.cpp
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include <iostream>
#include "RequestAcceptorFactory.h"
#include "IRequestAcceptor.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    int portNumber = 8085;
    IRequestAcceptorPtr acceptorPtr = RequestAcceptorFactory::createRequestAcceptor(portNumber);
    acceptorPtr->start();
    return 0;
}

