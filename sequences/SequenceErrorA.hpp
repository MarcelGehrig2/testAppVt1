#include <eeros/sequencer/Sequence.hpp>
// #include <eeros/sequencer/Sequencer.hpp>



namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class TestAppCS;
	
	class SequenceErrorA : public Sequence {
	public:
		SequenceErrorA(Sequencer& S, TestAppCS* CS, BaseSequence* caller, std::__cxx11::string name);

		int operator()();
		int action();
		
		TestAppCS* CS;
	};

	
	
};