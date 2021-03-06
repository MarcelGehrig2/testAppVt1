#include <eeros/sequencer/Step.hpp>

namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class  TestAppCS;
	
	class StepA : public Step {
	public:
		StepA(Sequencer& S, TestAppCS* CS, BaseSequence* caller);
		
		int action();
		bool checkExitCondition();
		
		TestAppCS* CS;
	};

	
	
};