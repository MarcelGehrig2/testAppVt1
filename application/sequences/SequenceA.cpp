#include "SequenceA.hpp"
#include "../../control/steps/StepA.hpp"

using namespace testappsequencer;


SequenceA::SequenceA(Sequencer& S, TestAppCS* CS, BaseSequence* caller, std::__cxx11::string name)
: Sequence(S, caller, name), CS(CS),

seqEA2(S, CS, this, "seqEA2Step")
{
	setIsBlocking();
}

int SequenceA::operator()()
{
	return Sequence::start();
}



int SequenceA::action()
{
	StepA sA = StepA(S, CS, this);
	sA.setTimeoutTime(5);
	sA.setTimeoutBehavior(eeros::sequencer::restartCallerOfOwner);
	sA.setTimeoutExceptionSequence(&seqEA2);
	
	log.info() << "SequenceA::action()";
	log.info() << "SequenceA: sA.start() 1";
	sA.start();
	log.info() << "SequenceA: sA.start() 2";
	sA.start();
// 	restartSequence();
	log.info() << "SequenceA: sA.start() 3";
	sA.start();
}
