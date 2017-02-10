#include <eeros/sequencer/Step.hpp>

namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class TestAppCS;
	
	class StepB : public Step {
	public:
		StepB(Sequencer& S, TestAppCS* CS, BaseSequence* caller);
		
		int action();
		
		TestAppCS* CS;
	};

	
	
};