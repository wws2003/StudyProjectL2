//
//  Buffer.h
//  DocServer
//
//  Created by wws2003 on 12/30/13.
//  Copyright (c) 2013 wws2003. All rights reserved.
//

#ifndef DocServer_Buffer_h
#define DocServer_Buffer_h

typedef unsigned char* byte;
typedef struct buffer {
    byte* data;
    int length;
} Buffer;

typedef Buffer* BufferPtr;

void freeBuffer(BufferPtr bufferPtr);

#endif
