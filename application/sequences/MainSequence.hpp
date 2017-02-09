// #include <eeros/sequencer/Sequence.hpp>
// #include <eeros/sequencer/Sequencer.hpp>

// #include "TestAppSequencer.hpp"
#include "SequenceA.hpp"
#include "SequenceB.hpp"
#include "../../control/sequences/SequenceExceptionA.hpp"

// #include "../control/CS.hpp"

namespace testappsequencer {

	class TestAppCS;
	
	class MainSequence : public eeros::sequencer::Sequence {
	public:
// 		MainSequence(Sequencer& S, std::__cxx11::string name);
		MainSequence(Sequencer& S, TestAppCS* CS, std::__cxx11::string name);

		int action();
		
		SequenceA seqA1;
	// 	SequenceA seqA2;
		SequenceB seqB1; 
		SequenceB seqB2; 
		SequenceB seqB3; 
// 		SequenceB* seqB3; 
		
		SequenceExceptionA seqEA1;
		
// 		TestAppSequencer S;
// 		TestAppCS* getCS() const;
		TestAppCS* CS;
	private:
// 		static TestAppCS* CS;
	};
	
	
};