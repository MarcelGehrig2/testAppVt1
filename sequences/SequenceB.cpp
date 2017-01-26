#include "SequenceB.hpp"
#include "../steps/StepB.hpp"

using namespace testappsequencer;


SequenceB::SequenceB(Sequencer& S, BaseSequence* caller, std::__cxx11::string name): Sequence(S, caller, name)
{
	setIsNonBlocking();
}

int SequenceB::operator()()
{
	return Sequence::start();
}

int SequenceB::action()
{
	StepB sB = StepB(S, this);
	
	log.info() << "SequenceB::action()";
	sB.start();
	std::this_thread::sleep_for(std::chrono::seconds(2));
}