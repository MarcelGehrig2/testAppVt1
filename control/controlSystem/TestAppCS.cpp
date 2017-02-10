#include <math.h> 
#include <iomanip>

#include <eeros/core/Executor.hpp>
#include <eeros/task/Periodic.hpp>

#include "TestAppCS.hpp"

using namespace testappsequencer;
using namespace eeros::control;
using namespace std;

TestAppCS::TestAppCS() :
	
stepA(0, 5, 3),

timedomain("Main time domain", dt, false)

{
		
	// Connect Blocks
	probeA.getIn().connect(stepA.getOut());
			
	
	// Run blocks
	timedomain.addBlock(&stepA);
	timedomain.addBlock(&probeA);
// 				
	eeros::task::Periodic td("control system",dt, timedomain);	
	eeros::Executor::instance().add(td);
}
	