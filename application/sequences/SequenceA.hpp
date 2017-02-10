#include "../../control/sequences/SequenceExceptionA.hpp"


namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class TestAppCS;
	
	class SequenceA : public Sequence {
	public:
		SequenceA(Sequencer& S, TestAppCS* CS, BaseSequence* caller, std::__cxx11::string name);
		
		int operator()();
		int action();
		
		SequenceExceptionA seqEA2;
		
		TestAppCS* CS;
	};

};