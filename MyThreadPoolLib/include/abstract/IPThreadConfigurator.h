/*
 * IPThreadConfigurator.h
 *
 *  Created on: May 11, 2015
 *      Author: pham
 */

#ifndef IPTHREADCONFIGURATOR_H_
#define IPTHREADCONFIGURATOR_H_

#include <pthread.h>

class IPThreadConfigurator {
public:
	virtual ~IPThreadConfigurator(){};

	//Setup params for pThreadAttribute functions like pthread_attr_setxxx
	virtual int configThreadAttiribute(pthread_attr_t* pThreadAttribute) = 0;
};


#endif /* IPTHREADCONFIGURATOR_H_ */
