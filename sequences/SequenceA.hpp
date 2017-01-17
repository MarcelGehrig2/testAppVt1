#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>
#include <iostream>



namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class SequenceA : public Sequence {
	public:
		SequenceA(Sequencer& S, Sequence* caller, std::__cxx11::string name);
		
		bool blocking = true;
		void action();
	};

	
	
};