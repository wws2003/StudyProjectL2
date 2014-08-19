//
//  CellPool.cpp
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "CellPool.h"
#include <assert.h>

CellPoolPtr CellPool::instancePtr = NULL;

CellPool* CellPool::initInstance(integer numberOfRow, integer numberOfColumn) {
    if (instancePtr == NULL) {
        instancePtr = new CellPool(numberOfRow, numberOfColumn);
    }
    return instancePtr;
}

CellPool* CellPool::getInstance() {
    assert(instancePtr != NULL && "Instance must be initialized beforehand");
    return instancePtr;
}

CellPool::~CellPool() {
    for (integer i = 0; i < m_numberOfRow; i++) {
        for (integer j = 0; j < m_numberOfColumn; j++) {
            delete m_cellPool[i][j];
        }
        delete m_cellPool[i];
    }
    delete m_cellPool;
}

CellPtr CellPool::getCellAtPosition(integer x, integer y) const {
    assert(m_cellPool[x][y]->row == x && m_cellPool[x][y]->column == y);
    return  m_cellPool[x][y];
}

integer CellPool::getNumberOfColumn() {
    return m_numberOfColumn;
}

integer CellPool::getNumberOfRow() {
    return m_numberOfRow;
}

CellPool::CellPool(integer numberOfRow, integer numberOfColumn) : m_numberOfRow(numberOfRow), m_numberOfColumn(numberOfColumn){
    m_cellPool = new CellPtr*[numberOfRow];
    for (integer i = 0; i < numberOfRow; i++) {
        m_cellPool[i] = new CellPtr[numberOfColumn];
        for (integer j = 0; j < numberOfColumn; j++) {
            m_cellPool[i][j] = new Cell();
            m_cellPool[i][j]->row = i;
            m_cellPool[i][j]->column = j;
        }
    }
}