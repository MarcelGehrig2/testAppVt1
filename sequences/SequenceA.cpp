#include "SequenceA.hpp"
#include "../steps/StepA.hpp"

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
// 	sA.setTimeoutBehavior(restartOwner);
	sA.setTimeoutExceptionSequence(&seqEA2);
	
	log.info() << "SequenceA::action()";
	log.info() << "SequenceA: sA.start() 1";
	sA.start();
// 	pauseSequence();
// 	sA.setTimeoutTime(2);
	log.info() << "SequenceA: sA.start() 2";
	sA.start();
	restartSequence();
// 	std::this_thread::sleep_for(std::chrono::seconds(1));
	log.info() << "SequenceA: sA.start() 3";
	sA.start();
}
