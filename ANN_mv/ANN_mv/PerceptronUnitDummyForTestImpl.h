//
//  PerceptronUnitDummyForTestImpl.h
//  ANN_mv
//
//  Created by wws2003 on 10/27/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef __ANN_mv__PerceptronUnitDummyForTestImpl__
#define __ANN_mv__PerceptronUnitDummyForTestImpl__

#include <iostream>
#include "PerceptronUnitDummyImpl.h"

class PerceptronUnitDummyForTestImpl : public PerceptronUnitDummyImpl {
public:
    //@Override
    virtual double inline getErrorTerm() const {return 1;}
};

#endif /* defined(__ANN_mv__PerceptronUnitDummyForTestImpl__) */
