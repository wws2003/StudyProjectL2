//
//  IMutext.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ThreadPoolSample_IMutex_h
#define ThreadPoolSample_IMutex_h

class IMutex {
public:
    IMutex(){};
    virtual ~IMutex(){};
    
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

#endif
