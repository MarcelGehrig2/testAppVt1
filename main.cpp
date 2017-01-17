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
	
	std::__cxx11::string name="mainSequence";
// 	MainSequence 
	MainSequence mainSequence(S, name);
// 	MainSequence mainSequence(S);
// 	ParallelScaraMainSequence mainSequence(&sequencer, &controlSystem, &safetySystem);
	
	S.addMainSequence(&mainSequence);
	S.run();
	
	log.info() << "Main Sequence added";
	
// 	S.join();
// 	std::this_thread::sleep_for(std::chrono::milliseconds(100));
// 	mainSequence.seqB1.cv.notify_all();
	
	mainSequence.join();
	log.info() << "Main Sequence joined";
	
	
	
	
	return 0;
}