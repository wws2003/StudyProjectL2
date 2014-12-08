//
//  main.cpp
//  Lab
//
//  Created by wws2003 on 3/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>
#include "TestThread.h"

const int AA = 1;

void functionWithNonConstantPtrArgument(int* x) ;
void functionWithConstantPtrArgument(const int* x);
void functionWithNonConstantRefArgument(int& x);
void functionWithConstantRefArgument(const int& x);
void functionWithNonConstantArgument(int x);
void functionWithConstantArgument(const int x);
void functionWithConstantPtrVector(const std::vector<int*> vect);
void functionWithConstanceValueVector(std::vector<const int> vect);

void functionWithNonConstantPtrArgument(int* x) {
    functionWithConstantPtrArgument(x);
    std::cout << *x << std::endl;
}

void functionWithConstantPtrArgument(const int* x) {
    // functionWithNonConstantPtrArgument(x); Compile error
    std::cout << *x << std::endl;
}

void functionWithNonConstantRefArgument(int& x) {
    functionWithConstantRefArgument(x);
    std::cout << 2*x << std::endl;
}

void functionWithConstantRefArgument(const int& x) {
    //functionWithNonConstantRefArgument(x); Compile error
    std::cout << 2*x << std::endl;
}

void functionWithNonConstantArgument(int x) {
    std::cout << 2*x << std::endl;
}

void functionWithConstantArgument(const int x) {
    functionWithNonConstantArgument(x);
    std::cout << 2*x << std::endl;
}

void functionWithConstantPtrVector(const std::vector<int*> vect) {
    int* pFront = vect.front();
    *pFront = 1;
    //vect.push_back(NULL); Compile error
}

void functionWithConstanceValueVector(std::vector<const int> vect) {
    //Cause compile error
    //vect.push_back(AA);
}

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    //testThreadWaitOnTimedCondVar();
    std::vector<int> vect;
    vect.push_back(1);
    vect.reserve(vect.capacity() * 2);
    assert(vect[0] == 1);
    return 0;
}

