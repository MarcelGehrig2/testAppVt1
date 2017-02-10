#include "SequenceA.hpp"
#include "SequenceB.hpp"
#include "../../control/sequences/SequenceExceptionA.hpp"


namespace testappsequencer {

	class TestAppCS;
	
	class MainSequence : public eeros::sequencer::Sequence {
	public:
		MainSequence(Sequencer& S, TestAppCS* CS, std::__cxx11::string name);

		int action();
		
		SequenceA seqA1;
	// 	SequenceA seqA2;
		SequenceB seqB1; 
		SequenceB seqB2; 
		SequenceB seqB3; 
		
		SequenceExceptionA seqEA1;
		
		TestAppCS* CS;
	private:
	};
	
	
};