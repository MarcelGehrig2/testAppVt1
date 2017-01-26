#include <iostream>
// #include <b
#include <eeros/logger/Logger.hpp>
#include <eeros/logger/StreamLogWriter.hpp>

#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>

#include "sequences/MainSequence.hpp"


using namespace eeros;
using namespace eeros::logger;		
// 	using namespace eeros::sequencer;
using namespace testappsequencer;
	
int main() {
	
	StreamLogWriter w(std::cout);
	w.show(4);
	Logger<LogWriter>::setDefaultWriter(&w);
	Logger<LogWriter> log;
 
	log.info() << "Hello, EEROS";
 
	
	
	
	
	
	eeros::sequencer::Sequencer S;

// 	MainSequence 
	MainSequence mainSequence(S, "mainSequence");
	
	log.info() << "Main Pre S.addMainSequence(&mainSequence);";
	S.addMainSequence(&mainSequence);
// 	S.run();
	
	log.info() << "Main Sequence added";
	mainSequence.join();
	log.info() << "Main Sequence joined";
	
	
	
	
	return 0;
}