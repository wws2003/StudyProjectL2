/*
 * RoundRobinPThreadConfigurator.cpp
 *
 *  Created on: May 11, 2015
 *      Author: pham
 */

#include "RoundRobinPThreadConfigurator.h"
#include <pthread.h>
#include <sched.h>

RoundRobinPThreadConfigurator::RoundRobinPThreadConfigurator() {

}

//Setup params for pThreadAttribute functions like pthread_attr_setxxx
int RoundRobinPThreadConfigurator::configThreadAttiribute(pthread_attr_t* pThreadAttribute) {
	pthread_attr_t threadAttribute;
	pthread_attr_init(&threadAttribute);

	pthread_attr_setschedpolicy(&threadAttribute, SCHED_RR);
	pthread_attr_setinheritsched(&threadAttribute, PTHREAD_EXPLICIT_SCHED);

	*pThreadAttribute = threadAttribute;

	return 0;
}


