#include "GoTo.hpp"
#include "../control/TestAppCS.hpp"
#include <eeros/sequencer/Sequencer.hpp>

using namespace testappsequencer;


GoTo::GoTo(Sequencer& S, TestAppCS* CS, BaseSequence* caller)
: Step(S, caller), CS(CS)
{
	
}


int GoTo::operator()(int x, int y)
{
	this->x = x;
	this->y = y;
	return Step::start();	//this code is mandatory for every derived Step- and Sequence-Class
}


int GoTo::action()
{	
 	CS->pathPlaner.setTarget(x, y);
}


bool GoTo::checkExitCondition()
{
	int actPos = CS->pathPlaner.getActPos;
	if ( abs(actPos - pos) > 10 ) return false;	//target position not yet reached
	
	SequenceB* seqB1 = (SequenceB*)(S.getSeqenceByName("seqB1"));
	seqB1->setLastReachedPosition(actPos);
	
	return true;
}