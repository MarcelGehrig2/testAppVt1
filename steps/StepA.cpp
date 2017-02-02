#include "StepA.hpp"
#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>
#include "../control/SequencerProbe.hpp"
#include "../control/TestAppCS.hpp"
#include "../sequences/MainSequence.hpp"


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
// 	std::this_thread::sleep_for(std::chrono::seconds(3));
	
// 	CS->

}


bool StepA::checkExitCondition()
{
	log.info() << CS->probeA.getActValue();
	if ( CS->probeA.getActValue() > 0 ) return true;
// 	if ( true ) return true;
	return false;
}
