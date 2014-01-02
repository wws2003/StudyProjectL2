//
//  main.cpp
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include <iostream>
#include <boost/shared_ptr.hpp>

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    boost::shared_ptr<int> ptr = NULL;
    if (ptr == NULL) {
        std::cout << "NULL PTr" << std::endl;
    }
    return 0;
}

