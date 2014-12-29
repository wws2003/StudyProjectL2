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

class ObjectPoolFactory {
public:
    static ObjectPoolPtr createObjectPool(POOL_TYPE type = SIMPLE);
};

#endif /* defined(__TestObjectPool__ObjectPoolManager__) */
