#include "MainSequence.hpp"
// #include <eeros/sequencer/Sequence.hpp>
// #include <eeros/sequencer/Sequencer.hpp>

using namespace testappsequencer;
using namespace eeros;
using namespace eeros::sequencer;
// using namespace eeros::safety;
// using namespace eeros::math;


MainSequence::MainSequence(Sequencer& S, std::__cxx11::string name):
Sequence(S, this, name),

seqA1(S, this, "seqA1"),
seqB1(S, this, "seqB1"),
seqB2(S, this, "seqB2"),
seqB3(S, this, "seqB3")
{
	setIsNonBlocking();
// 	seqB3 = new SequenceB(S, this, "seqB3");
}

int MainSequence::action()
{
// 	seqB3 = new SequenceB(S, this, "seqB3");
	
	
	log.info() << "MainSequence started";
// 	seqA1.start();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	seqB1();
	seqB2();
	seqA1();
// 	std::cout << seqB3 << std::endl;
	seqB3();
// 	seqB3();
// 	seqA1.join();
	seqB3.join();
	
// 	delete seqB3;
	log.info() << "MainSequence ended";
}


