/*
 * SocketWrapper.h
 *
 *  Created on: 2013/09/22
 *      Author: admini
 */

#ifndef SOCKETWRAPPER_H_
#define SOCKETWRAPPER_H_

#include "common.h"
#include <boost/enable_shared_from_this.hpp>

#define BUFFER_SIZE 1024

class SocketWrapper : public boost::enable_shared_from_this<SocketWrapper> {
public:
	SocketWrapper(IOServicePtr ioPtr);
	Socket& getSocket();

protected:
	void work();

	void cb_read(ErrorCode error, std::size_t bytes_transferred );
	void cb_write();

	Socket socket;
	boost::array<char, BUFFER_SIZE> buff;
};

typedef boost::shared_ptr<SocketWrapper> SocketWrapperPtr;



#endif /* SOCKETWRAPPER_H_ */
