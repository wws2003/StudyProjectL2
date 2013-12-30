//
//  Buffer.c
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include <stdlib.h>
#include "Buffer.h"

void freeBuffer(BufferPtr bufferPtr) {
    free(bufferPtr->data);
    bufferPtr->length = 0;
}