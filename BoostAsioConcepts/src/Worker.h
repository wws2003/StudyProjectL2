/*
 * Worker.h
 *
 *  Created on: 2013/08/18
 *      Author: admini
 */

#ifndef WORKER_H_
#define WORKER_H_

class Worker {
public:
	Worker();
	virtual ~Worker();

	virtual bool toBeCancelled() = 0;
	virtual void doWork() = 0;
};

#endif /* WORKER_H_ */
