#include "StepB.hpp"
#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>

using namespace testappsequencer;

StepB::StepB(Sequencer& S, TestAppCS* CS, BaseSequence* caller)
: Step(S, caller), CS(CS)
{
	
}

int StepB::action()
{
	log.info() << "StepB::action()";

}
