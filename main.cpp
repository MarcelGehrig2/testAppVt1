#include <iostream>
#include <signal.h>
// #include <b
#include <eeros/core/Executor.hpp>
#include <eeros/task/Lambda.hpp>
#include <eeros/safety/SafetySystem.hpp>
#include <eeros/safety/SafetySystem.hpp>
#include <eeros/logger/Logger.hpp>
#include <eeros/logger/StreamLogWriter.hpp>


#include "control/controlSystem/TestAppCS.hpp"
#include "control/safetySystem/TestAppSafetyProperties.hpp"
#include "application/sequences/MainSequence.hpp"

using namespace eeros;
using namespace eeros::logger;
using namespace testappsequencer;



int main() {
	
	double dt = 0.01;
	
	StreamLogWriter w(std::cout);
	w.show(4);
	Logger<LogWriter>::setDefaultWriter(&w);
	Logger<LogWriter> log;
 
	log.info() << "EEROS started";
 
	
	// Executor
	// ////////////////////////////////////////////////////////////////////////
	auto &executor = eeros::Executor::instance();
	
	
	// Control System
	// ////////////////////////////////////////////////////////////////////////
	TestAppCS controlSystem; 
	
	
	// Safety System
	// ////////////////////////////////////////////////////////////////////////
	TestAppSafetyProperties safetyProperties(&controlSystem);
	eeros::safety::SafetySystem safetySystem(safetyProperties, dt);
	
	executor.setMainTask(safetySystem);
	
	
	// Sequencer
	// ////////////////////////////////////////////////////////////////////////
	eeros::sequencer::Sequencer S;
	MainSequence mainSequence(S, &controlSystem, "mainSequence");
	S.addMainSequence(&mainSequence);
	
	
	executor.run();

	
	mainSequence.join();
	
	
	return 0;
}