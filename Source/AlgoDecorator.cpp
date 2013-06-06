#include "AlgoDecorator.h"

AlgoDecorator::AlgoDecorator(DecoratedEqAlgo *algo, AddHookStoreOut *hook, const std::string& fileName, Timer &timer) : 
					_component(algo), _hook(hook), _fileName(fileName), timer_(timer){

};

AlgoDecorator::~AlgoDecorator(){
	delete _component;
};

int AlgoDecorator::execute(){
	int nbIter = _component->execute();
	timer_.stop();
	_hook->printToFile(_fileName);
	return nbIter;
};
