#include "StepSizeNonAdd.h"

StepSizeNonAdd::StepSizeNonAdd(DescDirection *algo, LineSearch *lineSearch) : 
				StepSize(algo, lineSearch){

};

StepSizeNonAdd::~StepSizeNonAdd(){

};

// TODO
void StepSizeNonAdd::initialiseDerivative(){
	//_der->setDataPointers(_size, _algo->getLinkFlows(), _algo->getProjectedDirection(), _indexes);
};
