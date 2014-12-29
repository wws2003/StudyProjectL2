//
//  BinClearTask.cpp
//  ParallelParticles
//
//  Created by wws2003 on 7/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "BinClearTask.h"
#include "Bin.h"
#include "ObjectPoolFactory.h"
#include "IObjectPool.h"
#include <iostream>

ObjectPoolPtr BinClearTask::g_pObjectPool = ObjectPoolFactory::createObjectPool(SIMPLE);

BinClearTask::BinClearTask(BinPtr pBin) : m_pBin(pBin){
    
}

//@Override
void* BinClearTask::operator new (size_t size) throw (std::bad_alloc) {
    return PoolObject::operator new(size, g_pObjectPool);
}

//@Override
void BinClearTask::operator delete(void* objectPtr) {
    return PoolObject::operator delete(objectPtr, g_pObjectPool);
}

//Override
//Can run on other thread
void BinClearTask::execute() {
    //std::cout << "Executing task BinClearTask \n";
    m_pBin->clear();
}

void BinClearTask::refreshPool() {
    if (g_pObjectPool) {
        g_pObjectPool->refresh();
    }
}