/*
 * WebServer.cpp
 *
 *  Created on: 2013/09/22
 *      Author: admini
 */


#include "WebServer.h"
#include "SocketWrapper.h"
#include <boost/bind.hpp>
#include <boost/thread.hpp>

using namespace std;
using namespace boost::asio::ip;

WebServer::WebServer(int port, int number_of_threads) : 	acceptor(new TCPAcceptor(*io_queue.front(), tcp::endpoint(tcp::v4(), port))) {
	//Initialize service queue and assign work to each io_service instance, to prevent it from stopping
	for(int i = 0; i < number_of_threads; i++) {
		IOServicePtr ioPtr(new boost::asio::io_service());
		io_queue.push_back(ioPtr);
		IOServiceWorkPtr workPtr(new boost::asio::io_service::work(*ioPtr));
		io_work_queue.push_back(workPtr);
	}
}

/**
 * Initialize event processing threads loop
 */
void WebServer::start() {

	//Doesn't work as no work instance exists, and more important, run() is a blocking method

	/*for(deque<IOServicePtr>::iterator sIter = io_queue.begin(); sIter != io_queue.end(); sIter++) {
		IOServicePtr io = *sIter;
		io->run();
	}*/

	//Use thread group instead

	boost::thread_group io_thread_group;
	for(deque<IOServicePtr>::iterator sIter = io_queue.begin(); sIter != io_queue.end(); sIter++) {
		IOServicePtr io = *sIter;
		io_thread_group.create_thread(boost::bind(&boost::asio::io_service::run, io));
	}
	io_thread_group.join_all();

	//Start asynchronously listening on an io_service
	listen();
}

void WebServer::listen() {
	//Create (but do not open yet) a peer socket
	SocketWrapperPtr newSocket(new SocketWrapper(io_queue.front()));

	//Asynchronously accept request on that socket
	acceptor->async_accept(newSocket->getSocket(), boost::bind(&WebServer::onRequest, this, newSocket, boost::asio::placeholders::error));
}

void WebServer::onRequest(SocketWrapperPtr socketPtr, ErrorCode error) {
	IOServicePtr top = io_queue.front();
	if(!error) {
		//Handle the request from the top of queue

		//TODO Get the opened socket (connection) via the wrapper and do the main work asynchronously
		socketPtr->work();
	}

	//Update the queue
	io_queue.pop_front();
	io_queue.push_back(top);

	//Start asynchronously listening on a new io_service
	listen();
}




