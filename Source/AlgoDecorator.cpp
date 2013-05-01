#include "AlgoDecorator.h"

AlgoDecorator::AlgoDecorator(DecoratedEqAlgo *algo){
	_component = algo;
};

AlgoDecorator::~AlgoDecorator(){
	delete _component;
};

int AlgoDecorator::execute(){
	return _component->execute();
};
