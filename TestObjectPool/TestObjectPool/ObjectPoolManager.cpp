//
//  ObjectPoolManager.cpp
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ObjectPoolManager.h"
#include "ObjectPoolSimpleImpl.h"

ObjectPoolPtr ObjectPoolManager::g_pObjectPool = NULL;
ObjectPoolPtr ObjectPoolManager::getObjectPool(/* May add some params */) {
    if (!g_pObjectPool) {
        g_pObjectPool = new ObjectPoolSimpleImpl();
    }
    return g_pObjectPool;
}