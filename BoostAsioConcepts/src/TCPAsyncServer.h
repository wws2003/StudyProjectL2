/*
 * TCPAsyncServer.h
 *
 *  Created on: 2013/08/23
 *      Author: admini
 */

#ifndef TCPASYNCSERVER_H_
#define TCPASYNCSERVER_H_

#include "common.h"
#include "TCPConnection.h"
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

using  boost::asio::ip::tcp;

class TCP_Async_Server {
public:
	TCP_Async_Server(boost::asio::io_service& io, int portNumber =8085);
	void start();
	virtual ~TCP_Async_Server();

private:
	tcp::acceptor acceptor_;
	int waitingSocket;
	static const int BUFFER_SIZE = 5;
	boost::mutex io_mutex;

	void startAccept();
	void acceptHandle(TCPConnectionPtr newConnectionPtr, const boost::system::error_code& error);
};

#endif /* TCPASYNCSERVER_H_ */
