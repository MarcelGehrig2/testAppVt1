#include "TestAppCS.hpp"
// #include <eeros/math/Matrix.hpp>
// #include <iostream>
// #include <unistd.h>
// #include <eeros/core/EEROSException.hpp>
// #include <eeros/hal/HAL.hpp>
#include <eeros/core/Executor.hpp>
#include <eeros/task/Periodic.hpp>
// #include <eeros/core/PeriodicCounter.hpp>

// #include <eeros/control/SignalProbeBlock.hpp>
// #include "NANto0Block.hpp"
#include <math.h> 

#include <iomanip>

using namespace testappsequencer;
using namespace eeros::control;
using namespace std;

	TestAppCS::TestAppCS() :
	
	stepA(0, 5, 3),
// 	stepA(0, 4, 400000),
	
// 	probeA();


	timedomain("Main time domain", dt, false)
// // 	timedomain1000("Logger time domain", 1, true)

	{
// 		stepA.setInitValue(3);
// 		using clk = std::chrono::steady_clock;		
		
		// Connect Blocks
		probeA.getIn().connect(stepA.getOut());
				
		
		// Run blocks
		timedomain.addBlock(&stepA);
		timedomain.addBlock(&probeA);
// 				
		eeros::task::Periodic td("control system",dt, timedomain);	
		eeros::Executor::instance().add(td);
// 		td
	}
	
// 	void TestAppCS::start() {
// 		//timedomain.start();
// 	}
// 
// 	void TestAppCS::stop() {
// 		//timedomain.stop();
// 		//timedomain.join();
// 	}
// 
// 	void TestAppCS::setRefSwitch(bool s) {
// 		xy_refPos_switch.switchToInput(s);
// 	}