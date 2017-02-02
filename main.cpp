#include <iostream>
#include <signal.h>
// #include <b
#include <eeros/core/Executor.hpp>
#include <eeros/task/Lambda.hpp>
#include <eeros/safety/SafetySystem.hpp>
#include <eeros/safety/SafetySystem.hpp>
#include <eeros/logger/Logger.hpp>
#include <eeros/logger/StreamLogWriter.hpp>

#include <eeros/sequencer/Sequence.hpp>

#include "control/TestAppCS.hpp"
#include "safety/TestAppSafetyProperties.hpp"
#include "sequences/MainSequence.hpp"


using namespace eeros;
using namespace eeros::logger;
// using namespace eeros::safety;
// 	using namespace eeros::sequencer;
using namespace testappsequencer;


volatile bool running = true;
void signalHandler(int signum) {
	running = false;
}

int main() {
// 	signal(SIGINT, signalHandler);
	
	double dt = 0.01;
	
	StreamLogWriter w(std::cout);
	w.show(4);
	Logger<LogWriter>::setDefaultWriter(&w);
	Logger<LogWriter> log;
 
	log.info() << "Hello, EEROS";
 
	
	
	auto &executor = eeros::Executor::instance();
	// ////////////////////////////////////////////////////////////////////////
	// Executor
	// ////////////////////////////////////////////////////////////////////////
// 	auto &executor = eeros::Executor::instance();
	
	
	
	// ////////////////////////////////////////////////////////////////////////
	// Control System
	// ////////////////////////////////////////////////////////////////////////
	TestAppCS controlSystem; 
// 	executor.setMainTask(controlSystem);
	
	TestAppSafetyProperties safetyProperties(&controlSystem);
	eeros::safety::SafetySystem safetySystem(safetyProperties, dt);
	
	executor.setMainTask(safetySystem);
	
	// ////////////////////////////////////////////////////////////////////////
	// Sequencer
	// ////////////////////////////////////////////////////////////////////////
	eeros::sequencer::Sequencer S;

// 	MainSequence 
	MainSequence mainSequence(S, &controlSystem, "mainSequence");
// 	MainSequence mainSequence(S, controlSystem, "mainSequence");
	
	log.info() << "Main Pre S.addMainSequence(&mainSequence);";
	S.addMainSequence(&mainSequence);
// 	S.run();
	log.info() << "Main Sequence added";
	
	executor.run();
	log.info() << "executor stopped";
	
	mainSequence.join();
	log.info() << "Main Sequence joined";
// 	std::this_thread::sleep_for(std::chrono::seconds(3));
// 	log.info() << "Main Sequence joined";

	
// 	return 0;
}