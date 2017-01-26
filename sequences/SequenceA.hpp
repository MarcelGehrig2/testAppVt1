#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>
// #include <iostream>



namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class SequenceA : public Sequence {
	public:
		SequenceA(Sequencer& S, BaseSequence* caller, std::__cxx11::string name);
		
		int operator()();
		int action();
	};

	
	
};