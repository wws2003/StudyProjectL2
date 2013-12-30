/*
 * SocketWrapper.cpp
 *
 *  Created on: 2013/09/22
 *      Author: admini
 */

#include <SocketWrapper.h>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

SocketWrapper::SocketWrapper(IOServicePtr ioPtr) : socket(*ioPtr){

}

Socket& SocketWrapper::getSocket() {
	return socket;
}

void SocketWrapper::work() {
	//TODO Read query to extract requested file name
	assert(socket.is_open());

	socket.async_read_some( boost::asio::buffer(buff) ,boost::bind(&SocketWrapper::cb_read
			, shared_from_this()
			, boost::asio::placeholders::error
			, boost::asio::placeholders::bytes_transferred));
}


void  SocketWrapper::cb_read(ErrorCode error, std::size_t bytes_transferred) {
	std::cout << "Number of byte read: " << bytes_transferred << std::endl;

	//TODO Move write code to cb_write
	std::string responseMessage = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n"
			"<html><head><title>Techburg</title>"
			"</head><body><h1>Dare_to_dream</h1><p>message</p></body></html>";

	boost::asio::async_write(socket, boost::asio::buffer(responseMessage), boost::bind(&SocketWrapper::cb_write,
			shared_from_this(),
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void  SocketWrapper::cb_write(ErrorCode error, std::size_t bytes_transferred) {
	std::cout << "Written  a respone, error message: "
			<< error.message()
			<< "  In thread  "
			<< boost::this_thread::get_id()
			<< "\n";
}
