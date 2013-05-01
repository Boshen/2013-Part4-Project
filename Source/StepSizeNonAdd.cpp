#include "StepSizeNonAdd.h"

StepSizeNonAdd::StepSizeNonAdd(DescDirection *algo, int nbLinks, const FPType precision, LineSearch *lineSearch, Derivative *der) : 
				StepSize(algo, nbLinks, precision, lineSearch), _der(der){

};

StepSizeNonAdd::~StepSizeNonAdd(){

};

// TODO
void StepSizeNonAdd::initialiseDerivative(){
	//_der->setDataPointers(_size, _algo->getLinkFlows(), _algo->getProjectedDirection(), _indexes);
};
