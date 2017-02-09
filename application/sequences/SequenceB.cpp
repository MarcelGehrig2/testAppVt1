#include "SequenceB.hpp"
#include "../../control/steps/StepB.hpp"

using namespace testappsequencer;


SequenceB::SequenceB(Sequencer& S, TestAppCS* CS, BaseSequence* caller, std::__cxx11::string name)
: Sequence(S, caller, name), CS(CS)
{
	setIsNonBlocking();
}

int SequenceB::operator()()
{
	return Sequence::start();
}

int SequenceB::action()
{
	StepB sB = StepB(S, CS, this);
	
	log.info() << "SequenceB::action()";
	sB.start();
	std::this_thread::sleep_for(std::chrono::seconds(2));
}


void SequenceB::say(std::string stuff)
{
// 	myStuff = stuff;
	log.info() << "Sequence " << getName() << " says: " << stuff;
}
