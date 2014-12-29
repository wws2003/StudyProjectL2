//
//  IRunable.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef DocServer_IRunable_h
#define DocServer_IRunable_h

class IRunable {
public:
    
    /**
     This class create another thread by start() and the created thread will invoke run() on the host instance
    **/
    
    virtual int start() = 0;
    virtual void run() = 0;
};

#endif
