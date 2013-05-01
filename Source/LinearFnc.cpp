#include "LinearFnc.h"
#include <stdlib.h>
#include <iostream>

LinearFnc::LinearFnc(FPType a, FPType b) : _param1(a), _param2(b){

};

LinearFnc::~LinearFnc(){

};

FPType LinearFnc::evaluate(FPType arcFlow){
	return _param1*arcFlow + _param2;
};

FPType  LinearFnc::evaluateDerivative(FPType arcFlow){
	return _param1;
};

void LinearFnc::print() const{
	std::cout << "a = " << _param1 << " b = " << _param2 << std::endl;
};
