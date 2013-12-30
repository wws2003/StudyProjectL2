/*
 * TCPConnection.cpp
 *
 *  Created on: 2013/08/23
 *      Author: admini
 */

#include "TCPConnection.h"
#include<iostream>
#include <sys/syscall.h>
#include <unistd.h>

TCPConnection::TCPConnection(boost::asio::io_service& io_service) : socket_(io_service), readTimer(io_service) {
	// TODO Auto-generated constructor stub
}

TCPConnection::~TCPConnection() {
	// TODO Auto-generated destructor stub
}

void TCPConnection::start() {
	message_ = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n"
			"<html><head><title></title>"
			"</head><body><h1>Test</h1><p>message</p></body></html>";

	/**
	 * Try to assign time out 400ms for async_read
	 */
	readTimer.expires_from_now(boost::posix_time::milliseconds(400));
	readTimer.async_wait(boost::bind(&TCPConnection::cancelRead, this));

	/**
	 * If use this instead of shared_from_this(), error tr1::bad_weak_ptr
	 * Reason: this is destructed immediately
	 */
	boost::asio::async_read(socket_, boost::asio::buffer(readBuf)
	, boost::bind(&TCPConnection::handleRead
			, shared_from_this()
			, boost::asio::placeholders::error
			, boost::asio::placeholders::bytes_transferred));

}

shared_ptr<TCPConnection> TCPConnection::create(boost::asio::io_service& io_service) {
	shared_ptr<TCPConnection> ret(new TCPConnection(io_service));
	return ret;
}

tcp::socket& TCPConnection::getSocket() {
	return socket_;
}

void TCPConnection::handleRead(const boost::system::error_code& error, size_t transferredBytes) {
	/*
	 * Force all pending operations on timer, i.e. cancelRead to cancel
	 */
	readTimer.cancel();

	boost::asio::async_write(socket_, boost::asio::buffer(message_)
	, boost::bind(&TCPConnection::handleWrite
			, shared_from_this()
			, boost::asio::placeholders::error
			, boost::asio::placeholders::bytes_transferred));
}

void TCPConnection::cancelRead() {
	/*
	 * Force all pending operations on socket, i.e. handleRead to cancel
	 */
	socket_.cancel();
}

void TCPConnection::handleWrite(const boost::system::error_code& error, size_t transferredBytes ) {
	std::cout << "Message has been written " << error.message() << " " << transferredBytes << " In thread " << syscall(SYS_gettid)<< std::endl;
}
