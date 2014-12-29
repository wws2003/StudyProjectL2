/*
 * CounterWorker.h
 *
 *  Created on: 2013/08/18
 *      Author: admini
 */

#ifndef COUNTERWORKER_H_
#define COUNTERWORKER_H_

#include "Worker.h"

class CounterWorker: public Worker {
public:
	CounterWorker();
	virtual ~CounterWorker();

	bool toBeCancelled();
	void doWork();

private:
	int count;
	static const int MAX = 5;
};

#endif /* COUNTERWORKER_H_ */
