//
//  main.cpp
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <sys/time.h>
#include "PoolObject.h"
#include "DerivedPoolObject.h"
#include "IObjectPool.h"
#include "ObjectPoolManager.h"

class Timer {
public:
    Timer(){gettimeofday(&m_tv, NULL);};
    virtual ~Timer(){
        struct timeval tv2;
        gettimeofday(&tv2, NULL);
        std::cout << "Run time " << ((tv2.tv_sec - m_tv.tv_sec) * 1e6 + (tv2.tv_usec - m_tv.tv_usec)) << std::endl;
    };
private:
    struct timeval m_tv;
};

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    PoolObject* p1 = new DerivedPoolObject(22, 9);
    delete p1;
    
    {
        Timer t;
        int n = 50000000;
        for (int i = 0; i < n; i++) {
            PoolObject* p = new DerivedPoolObject(i, 2 * i);
            delete p;
        }
    }
    
    PoolObject* p2 = new DerivedPoolObject(3, 8);
    delete p2;
    
    ObjectPoolManager::getObjectPool()->drain();
    
    //int* pInt = new (int)(3);
    return 0;
}

