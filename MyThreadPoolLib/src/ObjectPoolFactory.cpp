//
//  ObjectPoolManager.cpp
//  TestObjectPool
//
//  Created by wws2003 on 8/10/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "ObjectPoolFactory.h"
#include "ObjectPoolSimpleImpl.h"

ObjectPoolPtr ObjectPoolFactory::createObjectPool(POOL_TYPE type) {
    switch (type) {
        case SIMPLE:
            return new ObjectPoolSimpleImpl();
        default:
            break;
    }
    return  NULL;
}