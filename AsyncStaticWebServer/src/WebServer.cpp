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
#include <sys/syscall.h>
#include <unistd.h>

using namespace std;
using namespace boost::asio::ip;

WebServer::WebServer(int port, int number_of_threads)  {
	//Initialize service queue and assign work to each io_service instance, to prevent it from stopping
	for(int i = 0; i < number_of_threads; i++) {
		IOServicePtr ioPtr(new boost::asio::io_service());
		io_queue.push_back(ioPtr);
		IOServiceWorkPtr workPtr(new boost::asio::io_service::work(*ioPtr));
		io_work_queue.push_back(workPtr);
	}

	TCPAcceptorPtr acceptorPtr(new TCPAcceptor(*io_queue.front(), tcp::endpoint(tcp::v4(), port)));
	acceptor = acceptorPtr;
}

/**
 * Initialize event processing threads loop
 */
void WebServer::start() {


	//Start asynchronously listening on an io_service
	listen();

	//Below code doesn't work as no work instance exists, and more important, run() is a blocking method

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

}

void WebServer::listen() {
	std::cout << "Start listening "
				<< "  In thread  "
				<< boost::this_thread::get_id()
				<< "\n";

	//Create (but do not open yet) a peer socket
	SocketWrapperPtr newSocket(new SocketWrapper(io_queue.front()));

	//Asynchronously accept request on that socket
	acceptor->async_accept(newSocket->getSocket(), boost::bind(&WebServer::onRequest, this, newSocket.get()->shared_from_this(), boost::asio::placeholders::error));
}

void WebServer::onRequest(SocketWrapperPtr socketPtr, ErrorCode error) {
	std::cout << "Received a request, error message: "
			<< error.message()
			<< "  In thread  "
			<< boost::this_thread::get_id()
			<< "\n";

	IOServicePtr top = io_queue.front();
	if(!error) {
		//Handle the request from the top of queue
		socketPtr->work();
	}

	//Update the queue
	io_queue.pop_front();
	io_queue.push_back(top);

	//Start asynchronously listening on a new io_service
	listen();
}




