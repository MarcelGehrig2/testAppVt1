#include "MainSequence.hpp"
// #include <eeros/sequencer/Sequence.hpp>
// #include <eeros/sequencer/Sequencer.hpp>

using namespace testappsequencer;
using namespace eeros;
using namespace eeros::sequencer;
// using namespace eeros::safety;
// using namespace eeros::math;


MainSequence::MainSequence(Sequencer& S, std::__cxx11::string name):
Sequence(S, this, name), seqA1(S, this, "seqA1"), seqB1(S, this, "seqB1")
{
// 	seqA1 = SequenceA(S, "seqA1");
// 	seqA2->join();
// 	seqB1->join();
}

void MainSequence::action()
{
	log.info() << "MainSequence started";
	
	std::this_thread::sleep_for(std::chrono::seconds(1));
	log.info() << "MainSequence started 2";
	seqA1.start();
	seqB1.start();
// 	seqA1.cv.notify_one();
// 	seqB1.run();
// 	seqA1.action();
// 	seqA1.run();
// 	seqA1.join();
	seqA1.join();
	
	log.info() << "MainSequence ended";
}


// void MainSequence::start()
// {
// // 	Sequence::start();
// 	cv.notify_one();
// }
