#include "SequenceA.hpp"
#include "../steps/StepA.hpp"

using namespace testappsequencer;


SequenceA::SequenceA(Sequencer& S, Sequence* caller, std::__cxx11::string name): Sequence(S, caller, name)
{
	setIsBlocking();
}


int SequenceA::action()
{
	StepA sA = StepA(S, this);
	
	log.info() << "SequenceA::action()";
	sA.start();
	std::this_thread::sleep_for(std::chrono::seconds(1));
}