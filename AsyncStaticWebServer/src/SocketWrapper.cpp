/*
 * SocketWrapper.cpp
 *
 *  Created on: 2013/09/22
 *      Author: admini
 */

#include <SocketWrapper.h>

SocketWrapper::SocketWrapper(IOServicePtr ioPtr) : socket(*ioPtr){

}

Socket& SocketWrapper::getSocket() {
	return socket;
}

void SocketWrapper::work() {
	//Read query to extract requested file name
	boost::asio::async_read(socket, boost::asio::buffer(buff) ,boost::bind(&SocketWrapper::cb_read
			, enable_shared_from_this()
			, boost::asio::placeholders::error
			, boost::asio::placeholders::bytes_transferred));
}


void  SocketWrapper::cb_read(ErrorCode error, std::size_t bytes_transferred) {

}

void  SocketWrapper::cb_write() {

}
