#include "SequenceExceptionA.hpp"

using namespace testappsequencer;


SequenceExceptionA::SequenceExceptionA(Sequencer& S, TestAppCS* CS, BaseSequence* caller, std::__cxx11::string name)
: Sequence(S, caller, name), CS(CS)
{
	setIsBlocking();
}

int SequenceExceptionA::operator()()
{
	return Sequence::start();
}

int SequenceExceptionA::action()
{
	log.info() << "Timeout Error: " << callerSequence->getName();
}