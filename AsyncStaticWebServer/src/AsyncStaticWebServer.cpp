//============================================================================
// Name        : AsyncStaticWebServer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "common.h"
#include "WebServer.h"

using namespace std;

int main() {
	int port = 8085, number_of_threads = 4;
	WebServer webServer(port, number_of_threads);
	webServer.start();
	return 0;
}
