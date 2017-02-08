#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>



namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class TestAppCS;
	
	class SequenceB : public Sequence {
	public:
		SequenceB(Sequencer& S, TestAppCS* CS, BaseSequence* caller, std::__cxx11::string name);

		int operator()();
		int action();
		
		void say(std::string stuff);
// 		std::string hi();
		std::string myStuff;
		
		TestAppCS* CS;
	};

	
	
};