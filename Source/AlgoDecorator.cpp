#include "AlgoDecorator.h"

AlgoDecorator::AlgoDecorator(DecoratedEqAlgo *algo, AddHookStoreOut *hook, const std::string& fileName, Timer &timer) : 
					component_(algo), hook_(hook), fileName_(fileName), timer_(timer){

};

AlgoDecorator::~AlgoDecorator(){
	delete component_;
};

int AlgoDecorator::execute(){
	int nbIter = component_->execute();
	timer_.stop();
	hook_->printToFile(fileName_);
	return nbIter;
};
