#include "SequenceErrorA.hpp"

using namespace testappsequencer;


SequenceErrorA::SequenceErrorA(Sequencer& S, TestAppCS* CS, BaseSequence* caller, std::__cxx11::string name)
: Sequence(S, caller, name), CS(CS)
{
	setIsBlocking();
}

int SequenceErrorA::operator()()
{
	return Sequence::start();
}

int SequenceErrorA::action()
{
	
	log.info() << "Timeout Error";
}