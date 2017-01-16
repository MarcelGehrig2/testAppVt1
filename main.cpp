#include <iostream>
// #include <b
#include <eeros/logger/Logger.hpp>
#include <eeros/logger/StreamLogWriter.hpp>
 
int main() {
	using namespace eeros::logger;
 
	StreamLogWriter w(std::cout);
	Logger<LogWriter>::setDefaultWriter(&w);
	Logger<LogWriter> log;
 
	log.info() << "Hello, EEROS";
 
	return 0;
}