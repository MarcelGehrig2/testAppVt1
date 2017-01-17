#include "SequenceB.hpp"

using namespace testappsequencer;


SequenceB::SequenceB(Sequencer& S, Sequence* caller, std::__cxx11::string name): Sequence(S, caller, name)
{

}

int SequenceB::action()
{
	std::this_thread::sleep_for(std::chrono::seconds(5));
}