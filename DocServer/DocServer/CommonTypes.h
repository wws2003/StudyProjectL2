//
//  CommonTypes.h
//  DocServer
//
//  Created by wws2003 on 1/1/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#ifndef DocServer_CommonTypes_h
#define DocServer_CommonTypes_h

#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>

typedef boost::asio::io_service IOService;
typedef boost::asio::io_service& IOServiceRef;
typedef boost::shared_ptr<boost::asio::io_service> IOServicePtr;
typedef boost::asio::io_service::work IOServiceWork;
typedef boost::shared_ptr<boost::asio::io_service::work> IOServiceWorkPtr;
typedef boost::asio::ip::tcp::acceptor TCPAcceptor;
typedef boost::asio::ip::tcp::socket Socket;
typedef boost::shared_ptr<boost::asio::ip::tcp::socket> SocketPtr;
typedef boost::shared_ptr<TCPAcceptor> TCPAcceptorPtr;
typedef const boost::system::error_code& ErrorCodeRef;
typedef boost::system::error_code ErrorCode;
typedef boost::array<char, 128> IOBuffer;

#endif
