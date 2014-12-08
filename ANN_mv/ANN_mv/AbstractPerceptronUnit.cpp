//
//  AbstractPerceptronUnit.cpp
//  ANN_mv
//
//  Created by wws2003 on 10/20/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include "AbstractPerceptronUnit.h"

AbstractPerceptronUnit::AbstractPerceptronUnit() : m_currentOutput(0), m_currentErrorTerm(0), m_pCurrentInputs(NULL) {
}

AbstractPerceptronUnit::~AbstractPerceptronUnit() {
    
}