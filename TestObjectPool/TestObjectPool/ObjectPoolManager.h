//
//  ObjectPoolManager.h
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __TestObjectPool__ObjectPoolManager__
#define __TestObjectPool__ObjectPoolManager__

#include <iostream>
#include "TypeDefs.h"

class ObjectPoolManager {
public:
    static ObjectPoolPtr getObjectPool(/* May add some params */);
private:
    static ObjectPoolPtr g_pObjectPool;
};

#endif /* defined(__TestObjectPool__ObjectPoolManager__) */
