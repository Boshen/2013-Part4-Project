#include "ConstFnc.h"

#include <stdlib.h>
#include <iostream>

ConstFnc::ConstFnc(FPType param) : param_(param){

};

ConstFnc::~ConstFnc(){

};
		
FPType ConstFnc::evaluate(FPType linkFlow){
	return param_;
};

FPType ConstFnc::evaluateDerivative(FPType linkFlow){
	return 0.0;
};

void ConstFnc::print() const{
	std::cout << "param = " << param_ << std::endl;
};
