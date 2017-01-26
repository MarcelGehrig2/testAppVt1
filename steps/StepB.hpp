#include <eeros/sequencer/Step.hpp>

namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
// 	class Sequence;
// 	class Sequencer;
	
	class StepB : public Step {
	public:
// 		StepA(Sequencer& S, Sequence* caller, std::__cxx11::string name);
		StepB(Sequencer& S, Sequence* caller);
		
		int action();
	};

	
	
};