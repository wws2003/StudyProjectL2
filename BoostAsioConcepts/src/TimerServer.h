/*
 * TimerServer.h
 *
 *  Created on: 2013/08/18
 *      Author: admini
 */

#ifndef TIMERSERVER_H_
#define TIMERSERVER_H_

#include "Worker.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class TimerServer {
public:
	TimerServer(boost::asio::io_service& io, long dT, Worker* worker);
	virtual ~TimerServer();

protected:
	void run();

	boost::asio::deadline_timer* t;
	long dT;
	Worker* worker;
};

#endif /* TIMERSERVER_H_ */
