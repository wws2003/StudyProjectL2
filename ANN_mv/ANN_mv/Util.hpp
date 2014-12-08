//
//  Util.h
//  ANN_mv
//
//  Created by wws2003 on 10/21/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__Util__
#define __ANN_mv__Util__

#include <iostream>
#include <vector>
#include <cassert>

class Util {
public:
    template <class T>
    static void releaseVector(std::vector<T*>& vector) {
        for (typename std::vector<T*>::iterator iter = vector.begin(); iter != vector.end();) {
            T* p = *iter;
            iter = vector.erase(iter);
            delete p;
        }
        assert(vector.size() == 0);
    };
};

#endif /* defined(__ANN_mv__Util__) */
