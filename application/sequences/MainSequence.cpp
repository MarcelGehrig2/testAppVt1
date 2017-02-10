#include "MainSequence.hpp"

using namespace testappsequencer;
using namespace eeros;
using namespace eeros::sequencer;


MainSequence::MainSequence(Sequencer& S, TestAppCS* CS, std::__cxx11::string name):
Sequence(S, name), CS(CS),

seqA1(S, CS, this, "seqA1"),
seqB1(S, CS, this, "seqB1"),
seqB2(S, CS, this, "seqB2"),
seqB3(S, CS, this, "seqB3"),
seqEA1(S, CS, this, "seqEA1")
{
	setIsNonBlocking();
	seqA1.setTimeoutTime(55);
	seqA1.setTimeoutExceptionSequence(&seqEA1);
	seqA1.setTimeoutBehavior(restartOwner);
}

int MainSequence::action()
{
	BaseSequence::log.info() << "MainSequence started";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	
	seqB1();
	seqB2();
	seqA1();
	seqB3();
	
	seqB1.join();
	seqB2.join();
	seqB3.join();
	
// 	delete seqB3;
	log.info() << "MainSequence ended";
}

