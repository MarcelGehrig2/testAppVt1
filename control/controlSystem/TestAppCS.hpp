#ifndef CH_NTB_TESTAPP_CONTROLSYSTEM_HPP_
#define CH_NTB_TESTAPP_CONTROLSYSTEM_HPP_

// #include <eeros/math/Matrix.hpp>
#include <eeros/control/TimeDomain.hpp> 
// #include <eeros/control/Gain.hpp>
// #include <eeros/control/PeripheralInput.hpp>
// #include <eeros/control/PeripheralOutput.hpp>
// #include <eeros/control/Mux.hpp>
// #include <eeros/control/DeMux.hpp>
// #include <eeros/control/Switch.hpp>
// #include <eeros/hal/PeripheralOutput.hpp>
// #include <eeros/control/Step.hpp>

#include "SequencerProbe.hpp"
#include "MyStep.hpp"

// #include "kinematic/ParallelScaraInverseKinematic.hpp"
// #include "kinematic/ParallelScaraDirectKinematic.hpp"
// #include "pathplanner/PathPlanner.hpp"
// #include "pathplanner/PathPlannerEllipse.hpp"
// #include "RobotController.hpp"
// #include "PendulumController.hpp"
// #include "hallsensors/HallSensorsDataAcquisition.hpp"
// #include "hallsensors/HallPhiRotationMatrix.hpp"
// #include "SetWatchdog.hpp"
// 
// // #include <eeros/control/SystemTime.hpp>
// #include <eeros/control/SignalProbeBlock.hpp>
// #include "NANto0Block.hpp"
// 
// #include <chrono>
// #include "testTimestampStdChronoSteadyClock.hpp"
// // #include "MeasuringDataBlock2.hpp"
// // #include "MeasuringDataBlock3.hpp"
// 
// #include "../constants.hpp"
// #include "../types.hpp"

// using namespace testappsequencer;
// using namespace eeros;

namespace testappsequencer {	
	
	class TestAppCS {
// 		using clk = std::chrono::steady_clock;
		
	public:
		TestAppCS();
		
		std::string test = "test erfolgreich";
// 		void start();
// 		void stop();
// 		
// 		void setRefSwitch(bool s);
		
		// Define blocks
		MyStep<int> stepA;
		
		SequencerProbe<int> probeA;

// 		parallelscara::NANto0Block<2,double> nanTo0Block1;
		
		float maxPeriod[1000] = {0};
		static constexpr double dt = 0.01;
				
//	protected:
		eeros::control::TimeDomain timedomain;
// // 		eeros::control::TimeDomain timedomain1000;
		
	}; // END class
	
}; // END namespace

#endif // CH_NTB_TESTAPP_CONTROLSYSTEM_HPP_