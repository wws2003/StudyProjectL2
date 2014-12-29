//
//  ITask.h
//  ThreadPoolSample
//
//  Created by wws2003 on 3/15/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef ThreadPoolSample_ITask_h
#define ThreadPoolSample_ITask_h

class ITask {
public:
    ITask(){};
    virtual ~ITask(){};
    virtual void execute() = 0;
};

#endif
