#ifndef CH_NTB_TESTAPP_CONTROLSYSTEM_HPP_
#define CH_NTB_TESTAPP_CONTROLSYSTEM_HPP_


#include <eeros/control/TimeDomain.hpp> 

#include "SequencerProbe.hpp"
#include "MyStep.hpp"


namespace testappsequencer {	
	
	class TestAppCS {		
	public:
		TestAppCS();
		
		std::string test = "test erfolgreich";
		
		// Define blocks
		MyStep<int> stepA;
		
		SequencerProbe<int> probeA;
		
		float maxPeriod[1000] = {0};
		static constexpr double dt = 0.01;
				
//	protected:
		eeros::control::TimeDomain timedomain;
		
	}; // END class
	
}; // END namespace

#endif // CH_NTB_TESTAPP_CONTROLSYSTEM_HPP_