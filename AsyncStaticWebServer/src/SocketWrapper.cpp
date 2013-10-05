/*
 * SocketWrapper.cpp
 *
 *  Created on: 2013/09/22
 *      Author: admini
 */

#include <SocketWrapper.h>
#include <boost/bind.hpp>

SocketWrapper::SocketWrapper(IOServicePtr ioPtr) : socket(*ioPtr){

}

Socket& SocketWrapper::getSocket() {
	return socket;
}

void SocketWrapper::work() {
	//Read query to extract requested file name
	boost::asio::async_read(socket, boost::asio::buffer(buff) ,boost::bind(&SocketWrapper::cb_read
			, shared_from_this()
			, boost::asio::placeholders::error
			, boost::asio::placeholders::bytes_transferred));
}


void  SocketWrapper::cb_read(ErrorCode error, std::size_t bytes_transferred) {
	std::cout << "Number of byte read: " << bytes_transferred << std::endl;

	//TODO Move write code to cb_write
	std::string responseMessage = "Techburg";
	boost::asio::async_write(socket, boost::asio::buffer(responseMessage), boost::bind(&SocketWrapper::cb_write,
			shared_from_this(),
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void  SocketWrapper::cb_write(ErrorCode error, std::size_t bytes_transferred) {

}
