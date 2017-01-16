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
	Logger<LogWriter>::setDefaultWriter(&w);
	Logger<LogWriter> log;
 
	log.info() << "Hello, EEROS";
 
	
	
	
	
	
	eeros::sequencer::Sequencer S;
	
	std::__cxx11::string name="mainSequence";
// 	MainSequence 
	MainSequence mainSequence(S, name);
// 	MainSequence mainSequence(S);
// 	ParallelScaraMainSequence mainSequence(&sequencer, &controlSystem, &safetySystem);
	
	S.addMainSequence(&mainSequence);
	S.run();
	
	log.info() << "Main Sequence added";
	
// 	S.join();
	
	mainSequence.join();
	
	
	
	
	
	return 0;
}