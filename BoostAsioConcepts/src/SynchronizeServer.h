/*
 * SynchronizeServer.h
 *
 *  Created on: 2013/08/19
 *      Author: admini
 */

#ifndef SYNCHRONIZESERVER_H_
#define SYNCHRONIZESERVER_H_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class SynchronizeServer {
public:
	SynchronizeServer(boost::asio::io_service& io);
	virtual ~SynchronizeServer();

	void print1();
	void print2();

private:
	boost::asio::strand _strand;
	boost::asio::deadline_timer t1;
	boost::asio::deadline_timer t2;
	int count;
};

#endif /* SYNCHRONIZESERVER_H_ */
