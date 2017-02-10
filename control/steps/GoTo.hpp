#include <eeros/sequencer/Step.hpp>

namespace testappsequencer {
	
	using namespace eeros::sequencer;
	
	class  TestAppCS;
	
	class GoTo : public Step {
	public:
		GoTo(Sequencer& S, TestAppCS* CS, BaseSequence* caller);
		
		int operator()(int x, int y);
		int action();
		bool checkExitCondition();
		
		int pos;
		TestAppCS* CS;
	};
};