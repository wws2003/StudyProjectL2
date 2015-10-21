//
//  PMutex.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ThreadPoolSample__PMutex__
#define __ThreadPoolSample__PMutex__

#include <iostream>
#include <pthread.h>
#include "IMutex.h"

class PMutex : public IMutex {
public:
    PMutex();
    virtual ~PMutex();
    
    //@Override
    virtual void lock();
    //@Override
    virtual void unlock();
    
    pthread_mutex_t* getMutexPtr();
    
private:
    pthread_mutex_t m_mutex;
};

#endif /* defined(__ThreadPoolSample__PMutex__) */
