#include <eeros/sequencer/Step.hpp>

namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
// 	class Sequence;
// 	class Sequencer;
	class TestAppCS;
	
	class StepB : public Step {
	public:
// 		StepA(Sequencer& S, Sequence* caller, std::__cxx11::string name);
		StepB(Sequencer& S, TestAppCS* CS, BaseSequence* caller);
		
		int action();
		
		TestAppCS* CS;
	};

	
	
};