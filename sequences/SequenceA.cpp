#include "SequenceA.hpp"


using namespace testappsequencer;


SequenceA::SequenceA(Sequencer& S, Sequence* caller, std::__cxx11::string name): Sequence(S, caller, name)
{
	setIsBlocking();
}


int SequenceA::action()
{
	log.info() << "SequenceA::action()";
	std::this_thread::sleep_for(std::chrono::seconds(1));
}