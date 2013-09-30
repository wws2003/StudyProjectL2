/*
 * WebServer.cpp
 *
 *  Created on: 2013/09/22
 *      Author: admini
 */


#include "WebServer.h"
#include "SocketWrapper.h"
#include <boost/thread.hpp>

using namespace std;

WebServer::WebServer(int port, int number_of_threads) : port_number(port) {
	//Initialize queue
	for(int i = 0; i < number_of_threads; i++) {
		IOServicePtr ioPtr(new boost::asio::io_service());
		io_queue.push_back(ioPtr);
	}

	//Initialize the acceptor
}

void WebServer::start() {
	//Start all io_services in the queue
	for(deque<IOServicePtr>::iterator sIter = io_queue.begin(); sIter != io_queue.end(); sIter++) {
		IOServicePtr io = *sIter;
		io->run();
	}

	//Or

	/*boost::thread_group io_thread_group;
	for(deque<IOServicePtr>::iterator sIter = io_queue.begin(); sIter != io_queue.end(); sIter++) {
			IOServicePtr io = *sIter;
			io_thread_group.create_thread(boost::bind(boost::asio::io_service::run, io))
		}
	io_thread_group.join_all();*/

	//Start asynchronously listening on an io_service
	listen();
}

void WebServer::listen() {
	//Create (but do not open yet) a peer socket
	SocketWrapperPtr newSocket(new SocketWrapper(io_queue.front()));

	//Asynchronously accept request on that socket
	acceptor->async_accept(newSocket->getSocket(), boost::bind(&WebServer::cb_handleRequest, this, newSocket, boost::asio::placeholders::error));
}

void WebServer::cb_handleRequest(SocketWrapperPtr socketPtr, ErrorCode error) {
	IOServicePtr top = io_queue.front();
	if(!error) {
		//Handle the request from the top of queue

		//TODO Get the opened socket (connection) via the wrapper and do the main work asynchronously

	}

	//Update the queue
	io_queue.pop_front();
	io_queue.push_back(top);

	//Start asynchronously listening on a new io_service
	listen();
}




