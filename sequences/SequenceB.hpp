#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>



namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	
	class SequenceB : public Sequence {
	public:
		SequenceB(Sequencer& S, Sequence* caller, std::__cxx11::string name);

		int operator()();
		int action();
		
	};

	
	
};