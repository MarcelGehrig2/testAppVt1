#include "SequenceA.hpp"
#include "../steps/StepA.hpp"

using namespace testappsequencer;


SequenceA::SequenceA(Sequencer& S, TestAppCS* CS, BaseSequence* caller, std::__cxx11::string name)
: Sequence(S, caller, name), CS(CS)
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
	
	log.info() << "SequenceA::action()";
	sA.start();
	sA.start();
// 	std::this_thread::sleep_for(std::chrono::seconds(1));
	sA.start();
}
