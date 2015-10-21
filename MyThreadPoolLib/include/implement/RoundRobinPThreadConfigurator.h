/*
 * RoundRobinPThreadConfigurator.h
 *
 *  Created on: May 11, 2015
 *      Author: pham
 */

#ifndef ROUNDROBINPTHREADCONFIGURATOR_H_
#define ROUNDROBINPTHREADCONFIGURATOR_H_

#include "IPThreadConfigurator.h"

class RoundRobinPThreadConfigurator : public IPThreadConfigurator {

public:
	RoundRobinPThreadConfigurator();
	virtual ~RoundRobinPThreadConfigurator(){};

	//Setup params for pThreadAttribute functions like pthread_attr_setxxx
	virtual int configThreadAttiribute(pthread_attr_t* pThreadAttribute);
};



#endif /* ROUNDROBINPTHREADCONFIGURATOR_H_ */
