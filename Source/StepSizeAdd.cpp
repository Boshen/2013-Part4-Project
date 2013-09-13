#include "StepSizeAdd.h"
#include <stdlib.h>
#include <iostream>
StepSizeAdd::StepSizeAdd(LineSearch *lineSearch, Derivative *der) : 
			StepSize(lineSearch), _der(der){

};

StepSizeAdd::~StepSizeAdd(){

};

void StepSizeAdd::initialiseDerivative(DescDirection *algo){
	//std::cout << "Setting data pointers" << std::endl;
	_der->setDataPointers(algo->getSize(), algo->getLinkFlows(), algo->getProjectedDirection(), algo->getIndexes());
};
