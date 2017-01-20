#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>

#include "SequenceA.hpp"
#include "SequenceB.hpp"

namespace testappsequencer {

	
	
	class MainSequence : public eeros::sequencer::Sequence {
	public:
		MainSequence(eeros::sequencer::Sequencer& S, std::__cxx11::string name);

		int action();
		
		SequenceA seqA1;
	// 	SequenceA seqA2;
		SequenceB seqB1; 
		SequenceB seqB2; 
		SequenceB seqB3; 
// 		SequenceB* seqB3; 
		
		
	};
	
	
};