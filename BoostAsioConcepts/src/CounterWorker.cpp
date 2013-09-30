/*
 * CounterWorker.cpp
 *
 *  Created on: 2013/08/18
 *      Author: admini
 */

#include "CounterWorker.h"
#include <iostream>

CounterWorker::CounterWorker() {
	// TODO Auto-generated constructor stub
	count = 0;
}

CounterWorker::~CounterWorker() {
	// TODO Auto-generated destructor stub
}

bool CounterWorker::toBeCancelled() {
	return count > MAX;
}

void CounterWorker::doWork() {
	std::cout << count << std::endl;
	count++;
}
