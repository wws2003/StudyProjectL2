/*
 * common.h
 *
 *  Created on: 2013/08/23
 *      Author: admini
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<boost::asio::io_service> IOSericePtr;

#endif /* COMMON_H_ */
