/*
 * TCPConnection.h
 *
 *  Created on: 2013/08/23
 *      Author: admini
 */

#ifndef TCPCONNECTION_H_
#define TCPCONNECTION_H_

#include "common.h"
#include "boost/shared_ptr.hpp"
#include <string>

using boost::shared_ptr;
using  boost::asio::ip::tcp;

class TCPConnection : public boost::enable_shared_from_this<TCPConnection>{
public:
	virtual ~TCPConnection();

	static  shared_ptr<TCPConnection> create(boost::asio::io_service& io_service);
	void start();
	tcp::socket& getSocket();

private:
	TCPConnection(boost::asio::io_service& io_service);

	void handleRead(const boost::system::error_code& error, size_t transferredBytes);
	void cancelRead();

	void handleWrite(const boost::system::error_code& error, size_t transferredBytes );

	std::string message_;
	tcp::socket socket_;
	boost::asio::deadline_timer readTimer;
	boost::array<char, 1> readBuf;
};

typedef shared_ptr<TCPConnection> TCPConnectionPtr;

#endif /* TCPCONNECTION_H_ */
