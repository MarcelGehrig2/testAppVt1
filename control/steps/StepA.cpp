#include "StepA.hpp"
#include "../controlSystem/TestAppCS.hpp"
#include <eeros/sequencer/Sequencer.hpp>
#include "../../application/sequences/SequenceB.hpp"


using namespace testappsequencer;

StepA::StepA(Sequencer& S, TestAppCS* CS, BaseSequence* caller)
: Step(S, caller), CS(CS)
{
	
}

int StepA::action()
{
	log.info() << "StepA::action()";
	CS->stepA.reset();
	
// 	log.info() << "caller Sequence of StepA is: " << this->getCallerSequence()->getName();
// 	for ( BaseSequence *seq : this->getCallerStack() ) {
// 		log.info() << "___caller Strack of StepA consist of: " << seq->getName();
// 	}
// 	for ( BaseSequence *seq : this->getCallerStackBlocking() ) {
// 		log.info() << "___caller StrackBlocking of StepA consist of: " << seq->getName();
// 	}
	

	SequenceB* seqB1 = (SequenceB*)(S.getSeqenceByName("seqB1"));
	seqB1->say("hallo");

}


bool StepA::checkExitCondition()
{
// 	log.info() << CS->probeA.getActValue();
	if ( CS->probeA.getActValue() > 0 ) return true;
	return false;
}
