#include "StepA.hpp"
#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>

using namespace testappsequencer;

StepA::StepA(Sequencer& S, Sequence* caller)
: Step(S, caller)
{
	
}

int StepA::action()
{
	log.info() << "StepA::action()";
// 	log.info() << "caller Sequence of StepA is: " << this->getCallerSequence()->getName();
	for ( Sequence *seq : this->getCallerStack() ) {
		log.info() << "___caller Strack of StepA consist of: " << seq->getName();
	}
	for ( Sequence *seq : this->getCallerStackBlocking() ) {
		log.info() << "___caller StrackBlocking of StepA consist of: " << seq->getName();
	}
	std::this_thread::sleep_for(std::chrono::seconds(3));

}
