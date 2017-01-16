#include "SequenceA.hpp"


using namespace testappsequencer;


SequenceA::SequenceA(Sequencer& S, Sequence* caller, std::__cxx11::string name): Sequence(S, caller, name)
{

}

void SequenceA::run()
{
	
	// Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
	cv.wait(lk);
//     cv.wait(lk, []{return ready;});
	
	action();
// 	log.info() << "SequenceA run start";
// 	printName();
// 	std::this_thread::sleep_for(std::chrono::seconds(3));
// 	log.info() << "SequenceA run stop";
}

void SequenceA::action()
{
	log.info() << "SequenceA run start";
// 	printName();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	log.info() << "SequenceA run stop";
}