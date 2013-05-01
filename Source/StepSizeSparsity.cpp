#include "StepSizeSparsity.h"
#include <stdlib.h>
#include <iostream>

StepSizeSparsity::StepSizeSparsity(StepSize *component) {
	_component = component;
};

StepSizeSparsity::~StepSizeSparsity(){
	//std::cout << "destructor of StepSizeSparsity" << std::endl;
	delete _component;
};

FPType StepSizeSparsity::getStepSize(){;
	_component->fillIndexes();
	return _component->getStepSize();
}
