/*
 * TimerServer.cpp
 *
 *  Created on: 2013/08/18
 *      Author: admini
 */

#include "TimerServer.h"

TimerServer::TimerServer(boost::asio::io_service& io, long dT, Worker* worker)  : dT(dT) , worker(worker)  {
	// TODO Auto-generated constructor stub
	t = new boost::asio::deadline_timer(io, boost::posix_time::seconds(dT) );
	t->async_wait(boost::bind(&TimerServer::run, this));
	io.run();
}

TimerServer::~TimerServer() {
	// TODO Auto-generated destructor stub
	delete t;
}

void TimerServer::run() {
	if(worker->toBeCancelled())
		t->cancel();
	else {
		worker->doWork();
		t->expires_at(t->expires_at() + boost::posix_time::seconds(dT));
		t->async_wait(boost::bind(&TimerServer::run, this));
	}
}
