//============================================================================
// Name        : BoostAsioConcepts.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "CounterWorker.h"
#include "TimerServer.h"
#include "SynchronizeServer.h"
#include "TCPAsyncServer.h"
#include "QueuedTCPServer.h"

void synchronousTimer() {
	boost::asio::io_service io;

	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	t.wait(); //blocking wait

	std::cout << "Hello, world!\n";
}

void callbackFunc(const boost::system::error_code& e) {
	std::cout << "Hello, world!\n";
}
void asynchronousTimer() {
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

	//callbackFunc is to be called when the timer timeout, by the same thread of io.run() thread
	t.async_wait(&callbackFunc);
	std::cout << "Out of wait\n";
	io.run();
}

void callbackFuncWithParam(const boost::system::error_code& /*e*/,
		boost::asio::deadline_timer* t, int* count) {
	if (*count < 5)
	{
		std::cout << *count  << " In thread " << syscall(SYS_gettid) << "\n";
		++(*count);

		t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
		t->async_wait(boost::bind(callbackFuncWithParam,  boost::asio::placeholders::error, t, count));
	}
}

void asynchronousTimerWithParam() {
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));
	int count = 0;

	//callbackFunc is to be called when the timer timeout, by the same thread of io.run() thread
	//, with parameters are addresses of t and count
	t.async_wait(boost::bind(callbackFuncWithParam, boost::asio::placeholders::error, &t, &count));
	std::cout << "Out of wait\n";
	std::cout << io.run() << std::endl;
}

void memberFuncHandler() {
	boost::asio::io_service io;
	long dT = 1;
	Worker* worker = new CounterWorker();
	TimerServer server(io, dT, worker);
}

void multiThreadedServer() {
	boost::asio::io_service io;
	SynchronizeServer server(io);
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
	io.run();
	t.join();
}

void asyncServer() {
	try
	{
		boost::asio::io_service io_service;
		TCP_Async_Server server(io_service);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void asyncServerSimpleMultiThread() {
	/* How about thread group ?*/
	int number_of_threads = 8;
	boost::asio::io_service* io_services =new boost::asio::io_service[number_of_threads];
	boost::thread_group threadGroup;

	for(int i = 0; i < number_of_threads; i++) {
		TCP_Async_Server server(io_services[i]);

		//Not possible because of taking address of constructor.  Why?
		//boost::thread t(boost::bind(&TCP_Async_Server::TCP_Async_Server, io_services[i]));

		//The recently created thread has started?
		threadGroup.create_thread(boost::bind(&boost::asio::io_service::run, &io_services[i]));
	}

	threadGroup.join_all();
	delete io_services;
}

void queuedTCPServer(){
	int number_of_threads = 8;
	IOQueue ioQueue;
	for(int i = 0; i < number_of_threads; i++) {
		boost::shared_ptr<boost::asio::io_service> service(new boost::asio::io_service());
		ioQueue.push_back(service);
	}

	std::deque< boost::asio::io_service::work> works;

	boost::thread_group threadGroup;
	for(IOQueue::iterator sIter = ioQueue.begin(); sIter != ioQueue.end(); sIter++) {
		IOSericePtr service = *sIter;

		//Make sure service doesn't stop by work instance?
		 boost::asio::io_service::work work(*service);
		 works.push_back(work);

		 threadGroup.create_thread(boost::bind(&boost::asio::io_service::run, service));
	}

	QueuedTCPServer server(ioQueue);

	threadGroup.join_all();
}
int main() {
	//synchronousTimer();
	//asynchronousTimerWithParam();
	//memberFuncHandler();
	//multiThreadedServer();
	//asyncServer();
	queuedTCPServer();
	return 0;
}
