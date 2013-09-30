/*
 * QueuedTCPServer.cpp
 *
 *  Created on: 2013/08/31
 *      Author: admini
 */

#include "QueuedTCPServer.h"

QueuedTCPServer::QueuedTCPServer(IOQueue& queue, int portNumber) : ioQueue(queue) , portNumber(portNumber), tmpAcceptor(NULL)/*, acceptor(*queue.front(), tcp::endpoint(tcp::v4(), portNumber))*/ {
	// TODO Auto-generated constructor stub
	startAccept();
}

QueuedTCPServer::~QueuedTCPServer() {
	// TODO Auto-generated destructor stub
}

void QueuedTCPServer::startAccept() {
	/*IOSericePtr service = ioQueue.front();
   TCPConnectionPtr conn = TCPConnection::create(*service);
   acceptor.async_accept(conn->getSocket()
		   , boost::bind(&QueuedTCPServer::handleAccept, this, conn, boost::asio::placeholders::error));
  ioQueue.push_back(service);
  ioQueue.pop_front();*/

	IOSericePtr service = ioQueue.front();

	//It is impossible to create 2 pointers of tcp::acceptor on the same port at the same time,
	//regardless on 2 separate io_service instances. -> how about proxy?

	tmpAcceptor = new tcp::acceptor(*service, tcp::endpoint(tcp::v4(), portNumber));
	TCPConnectionPtr conn = TCPConnection::create(*service);
	tmpAcceptor->async_accept(conn->getSocket()
			, boost::bind(&QueuedTCPServer::handleAccept, this, conn, boost::asio::placeholders::error));
	ioQueue.push_back(service);
	ioQueue.pop_front();
}

void QueuedTCPServer::handleAccept(TCPConnectionPtr connPtr,  const boost::system::error_code& error) {
	if(!error) {
		connPtr->start();
	}
	delete tmpAcceptor;
	startAccept();
}
