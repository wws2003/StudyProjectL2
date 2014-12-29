//
//  CellPool.h
//  VNOI1
//
//  Created by wws2003 on 3/9/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __VNOI1__CellPool__
#define __VNOI1__CellPool__

#include <iostream>
#include "Cell.h"
#include "PointerTypes.h"

class CellPool {
public:
    static CellPool* initInstance(integer numberOfRow, integer numberOfColumn);
    static CellPool* getInstance();
    virtual ~CellPool();
    
    CellPtr getCellAtPosition(integer x, integer y) const;
    integer getNumberOfColumn();
    integer getNumberOfRow();
    
private:
    integer m_numberOfRow;
    integer m_numberOfColumn;
    static CellPool* instancePtr;
    CellPool(){};
    CellPool(integer numberOfRow, integer numberOfColumn);
    CellPtr** m_cellPool;
};

typedef CellPool* CellPoolPtr;
#endif /* defined(__VNOI1__CellPool__) */
