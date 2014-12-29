/*
 * SynchronizeServer.cpp
 *
 *  Created on: 2013/08/19
 *      Author: admini
 */

#include "SynchronizeServer.h"

SynchronizeServer::SynchronizeServer(boost::asio::io_service& io) :_strand(io),
t1(io, boost::posix_time::seconds(1)),
t2(io, boost::posix_time::seconds(1)),
count(0) {
	/**
	 * Synchronize print1 & print2 by using wrapped handler
	 */
	t1.async_wait(_strand.wrap(boost::bind(&SynchronizeServer::print1, this)));
	t2.async_wait(_strand.wrap(boost::bind(&SynchronizeServer::print2, this)));
}

SynchronizeServer::~SynchronizeServer() {
	// TODO Auto-generated destructor stub
}

void SynchronizeServer::print1() {
	if (count < 10)
	{
		std::cout << "Timer 1: " << count << "\n";
		++count;

		t1.expires_at(t1.expires_at() + boost::posix_time::seconds(1));
		t1.async_wait(_strand.wrap(boost::bind(&SynchronizeServer::print1, this)));
	}
}

void SynchronizeServer::print2() {
	if (count < 10)
	{
		std::cout << "Timer 2: " << count << "\n";
		++count;

		t2.expires_at(t2.expires_at() + boost::posix_time::seconds(1));
		t2.async_wait(_strand.wrap(boost::bind(&SynchronizeServer::print2, this)));
	}
}
