/*
 * TCPAsyncServer.cpp
 *
 *  Created on: 2013/08/23
 *      Author: admini
 */

#include "TCPAsyncServer.h"
#include <iostream>

TCP_Async_Server::TCP_Async_Server(boost::asio::io_service& io,  int portNumber) : acceptor_(io, tcp::endpoint(tcp::v4(), portNumber)) {
	// TODO Auto-generated constructor stub
	start();
}

TCP_Async_Server::~TCP_Async_Server() {
	// TODO Auto-generated destructor stub
}

void TCP_Async_Server::start() {
	startAccept();
}

void TCP_Async_Server::startAccept() {
	waitingSocket = BUFFER_SIZE;
	int i=0;
	while(i++ < BUFFER_SIZE) {
		//Create a socket but haven't opened it yet. Socket opening requires accept/connect
		TCPConnectionPtr newConnectionPtr = TCPConnection::create(acceptor_.get_io_service());

		//One io_service can create how many sockets?

		/*This function is used to asynchronously accept a new connection into a
	socket. The function call always returns immediately.*/
		acceptor_.async_accept(newConnectionPtr->getSocket()
				,boost::bind(&TCP_Async_Server::acceptHandle, this,  newConnectionPtr, boost::asio::placeholders::error));
		std::cout << "Ready to accept a connection\n";
	}
}

void TCP_Async_Server::acceptHandle(TCPConnectionPtr newConnectionPtr, const boost::system::error_code& error) {
	if(!error) {
		std::cout << "Start handling request\n";
		newConnectionPtr->start();
	}

	waitingSocket--;
	if(waitingSocket == 0)
		startAccept();
}
