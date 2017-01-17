#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>

#include "SequenceA.hpp"
#include "SequenceB.hpp"

namespace testappsequencer {

	
	
	class MainSequence : public eeros::sequencer::Sequence {
	public:
		MainSequence(eeros::sequencer::Sequencer& S, std::__cxx11::string name);


	// MainSequence(Sequencer& S, Sequence* caller, std::__cxx11::string name);

		int action();
// 		void start();
		
		SequenceA seqA1;
	// 	SequenceA seqA2;
		SequenceB seqB1; 
	};
	
	
};