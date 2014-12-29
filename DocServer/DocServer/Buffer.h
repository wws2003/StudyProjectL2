//
//  Buffer.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef BufferUtil_Buffer_h
#define BufferUtil_Buffer_h

typedef unsigned char byte;

#define CHUNK_SIZE 256

typedef struct buffer {
    byte* data;
    size_t length;
    size_t maxSize;
} Buffer;

typedef Buffer* BufferPtr;

void initBuffer(BufferPtr bufferPtr);
void appendBuffer(BufferPtr bufferPtr, const char* dataToAppend, const size_t& lengthToAppend);
void freeBuffer(BufferPtr bufferPtr);

#endif