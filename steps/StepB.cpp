#include "StepB.hpp"
#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>

using namespace testappsequencer;

StepB::StepB(Sequencer& S, Sequence* caller)
: Step(S, caller)
{
	
}

int StepB::action()
{
	log.info() << "StepB::action()";

}
