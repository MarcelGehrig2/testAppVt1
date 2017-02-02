#include "MainSequence.hpp"
#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/BaseSequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>
#include "../control/TestAppCS.hpp"

using namespace testappsequencer;
using namespace eeros;
using namespace eeros::sequencer;
// using namespace eeros::safety;
// using namespace eeros::math;


MainSequence::MainSequence(Sequencer& S, TestAppCS* CS, std::__cxx11::string name):
// Sequence(S, name), CS(CS),
// Sequence(static_cast<Sequencer&>(S), name),
// MainSequence::MainSequence(Sequencer& S, std::__cxx11::string name):
Sequence(S, name), CS(CS),

seqA1(S, CS, this, "seqA1"),
seqB1(S, CS, this, "seqB1"),
seqB2(S, CS, this, "seqB2"),
seqB3(S, CS, this, "seqB3"),
seqEA1(S, CS, this, "seqEA1")
{
// 	CS.probe
	setIsNonBlocking();
	seqA1.setTimeoutTime(2);
	seqA1.setTimeoutExceptionSequence(&seqEA1);
// 	seqA1.BaseSequence::setTimeoutTime(2);
// 	seqA1.setTimeoutTime(2);
// 	seqA1.setTimeoutTime(2);
// 	seqB3.se
// 	SeqB1.setM
// 	seqB3 = new SequenceB(S, this, "seqB3");
}

int MainSequence::action()
{
// 	seqB3 = new SequenceB(S, this, "seqB3");
// 	CS->stepA.
	BaseSequence::log.info() << "MainSequence started";
// 	seqA1.start();
	std::this_thread::sleep_for(std::chrono::seconds(1));
// 	log.info() << "MainSequence started 2";
	seqB1();
	seqB2();
	seqA1();
// 	std::cout << seqB3 << std::endl;
	seqB3();
// 	seqB3();
	seqA1.join();
	seqB1.join();
	seqB2.join();
	seqB3.join();
	
// 	delete seqB3;
	log.info() << "MainSequence ended";
}

// TestAppCS* MainSequence::getCS() const
// {
// 	return CS;
// }


