/*
 * common.h
 *
 *  Created on: 2013/09/22
 *      Author: admini
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<boost::asio::io_service> IOServicePtr;
typedef boost::shared_ptr<boost::asio::io_service::work> IOServiceWorkPtr;
typedef boost::asio::ip::tcp::acceptor TCPAcceptor;
typedef boost::asio::ip::tcp::socket Socket;
typedef boost::shared_ptr<boost::asio::ip::tcp::socket> SocketPtr;
typedef boost::shared_ptr<TCPAcceptor> TCPAcceptorPtr;
typedef const boost::system::error_code& ErrorCode;



#endif /* COMMON_H_ */
