#include "StepSizeNonAdd.h"

StepSizeNonAdd::StepSizeNonAdd(LineSearch *lineSearch) : 
				StepSize(lineSearch){

};

StepSizeNonAdd::~StepSizeNonAdd(){

};

// TODO
void StepSizeNonAdd::initialiseDerivative(DescDirection *algo){
	//_der->setDataPointers(_size, _algo->getLinkFlows(), _algo->getProjectedDirection(), _indexes);
};
