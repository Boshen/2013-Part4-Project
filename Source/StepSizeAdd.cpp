#include "StepSizeAdd.h"
#include <stdlib.h>
#include <iostream>
StepSizeAdd::StepSizeAdd(DescDirection *algo, int nbLinks, const FPType precision, LineSearch *lineSearch, Derivative *der) : 
			StepSize(algo, nbLinks, precision, lineSearch), _der(der){

};

StepSizeAdd::~StepSizeAdd(){

};

void StepSizeAdd::initialiseDerivative(){
	_der->setDataPointers(_size, _algo->getLinkFlows(), _algo->getProjectedDirection(), _indexes);
};
