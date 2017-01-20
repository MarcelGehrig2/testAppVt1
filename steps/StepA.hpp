// #include <eeros/sequencer/Step.hpp>
#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>
#include <iostream>

namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class StepA : public Step {
	public:
// 		StepA(Sequencer& S, Sequence* caller, std::__cxx11::string name);
		StepA(Sequencer& S, Sequence* caller);
		
		int action();
	};

	
	
};