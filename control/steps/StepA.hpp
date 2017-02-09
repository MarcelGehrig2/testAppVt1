// #include <eeros/sequencer/Step.hpp>
// #include <eeros/sequencer/Sequence.hpp>
// #include <eeros/sequencer/Sequencer.hpp>
// #include <iostream>
#include <eeros/sequencer/Step.hpp>

namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class  TestAppCS;
	
	class StepA : public Step {
	public:
// 		StepA(Sequencer& S, Sequence* caller, std::__cxx11::string name);
		StepA(Sequencer& S, TestAppCS* CS, BaseSequence* caller);
		
		int action();
		bool checkExitCondition();
		
		TestAppCS* CS;
	};

	
	
};