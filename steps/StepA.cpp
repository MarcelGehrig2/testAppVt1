#include "StepA.hpp"
#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>

using namespace testappsequencer;

StepA::StepA(Sequencer& S, Sequence* caller)
: Step(S, caller)
{
	
}

int StepA::action()
{
	log.info() << "StepA::action()";
	std::this_thread::sleep_for(std::chrono::seconds(3));

}
