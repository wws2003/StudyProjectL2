/*
 * WebServer.h
 *
 *  Created on: 2013/09/22
 *      Author: admini
 */

#ifndef WEBSERVER_H_
#define WEBSERVER_H_

#include "common.h"
#include "SocketWrapper.h"
#include <deque>

class WebServer {
public:
	WebServer(int port, int number_of_threads);
	void start();

	void  cb_handleRequest(SocketWrapperPtr socketPtr, ErrorCode error);

protected:
	void listen();

	std::deque<IOServicePtr> io_queue;
	TCPAcceptorPtr acceptor;
	int port_number;
};



#endif

/* WEBSERVER_H_ */
