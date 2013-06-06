#include "StepSizeAdd.h"
#include <stdlib.h>
#include <iostream>
StepSizeAdd::StepSizeAdd(DescDirection *algo, LineSearch *lineSearch, Derivative *der) : 
			StepSize(algo, lineSearch), _der(der){

};

StepSizeAdd::~StepSizeAdd(){

};

void StepSizeAdd::initialiseDerivative(){
	//std::cout << "Setting data pointers" << std::endl;
	_der->setDataPointers(_algo->getSize(), _algo->getLinkFlows(), _algo->getProjectedDirection(), _algo->getIndexes());
};
