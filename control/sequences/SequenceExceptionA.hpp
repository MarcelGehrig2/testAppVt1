#ifndef TEST_APP_SEQUENCES_EXCEPTION_A_HPP_
#define TEST_APP_SEQUENCES_EXCEPTION_A_HPP_

#include <eeros/sequencer/Sequence.hpp>
// #include <eeros/sequencer/Sequencer.hpp>



namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class TestAppCS;
	
	class SequenceExceptionA : public Sequence {
	public:
		SequenceExceptionA(Sequencer& S, TestAppCS* CS, BaseSequence* caller, std::__cxx11::string name);

		int operator()();
		int action();
		
		TestAppCS* CS;
	};

	
	
};
#endif /* TEST_APP_SEQUENCES_EXCEPTION_A_HPP_ */