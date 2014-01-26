//
//  Buffer.c
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include "Buffer.h"

#define CHUNK_SIZE 256

void freeBuffer(BufferPtr bufferPtr) {
    free(bufferPtr->data);
    bufferPtr->length = 0;
}

void initBuffer(BufferPtr bufferPtr) {
    bufferPtr->length = 0;
    bufferPtr->data = (byte*)malloc(CHUNK_SIZE * sizeof(byte));
    bufferPtr->maxSize = CHUNK_SIZE;
    memset_s(bufferPtr->data, bufferPtr->maxSize, 0, bufferPtr->maxSize);
}

void appendBuffer(BufferPtr bufferPtr, const char* dataToAppend, const size_t& lengthToAppend) {
    size_t newMaxSize = bufferPtr->maxSize;
    size_t newSize = bufferPtr->length + lengthToAppend;
    while (newSize > newMaxSize) {
        newMaxSize += CHUNK_SIZE;
    }
    
    if(newMaxSize > bufferPtr->maxSize) {
        byte* newData = (byte*)malloc(newMaxSize * sizeof(byte));
        memcpy(newData, bufferPtr->data, bufferPtr->length);
        free(bufferPtr->data);
        bufferPtr->data = newData;
        bufferPtr->maxSize = newMaxSize;
    }

    memcpy(bufferPtr->data + bufferPtr->length, dataToAppend, lengthToAppend);
    bufferPtr->length = newSize;
}