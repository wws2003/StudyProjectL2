/*
 * QueuedTCPServer.h
 *
 *  Created on: 2013/08/31
 *      Author: admini
 */

#ifndef QUEUEDTCPSERVER_H_
#define QUEUEDTCPSERVER_H_

#include "common.h"
#include "TCPConnection.h"
#include <deque>

using boost::asio::ip::tcp;

typedef std::deque<IOSericePtr> IOQueue;

typedef boost::shared_ptr<tcp::acceptor> AcceptorPtr;
typedef std::deque<AcceptorPtr> AcceptorQueue;

class QueuedTCPServer {
public:
	QueuedTCPServer(IOQueue& queue, int portNumber = 8085);
	virtual ~QueuedTCPServer();

private:
	void startAccept();
	void handleAccept(TCPConnectionPtr connPtr,  const boost::system::error_code& error);

	IOQueue ioQueue;
	int portNumber;
	tcp::acceptor*  tmpAcceptor;
	//AcceptorQueue acceptorQueue;
	//tcp::acceptor acceptor;
};

#endif /* QUEUEDTCPSERVER_H_ */
