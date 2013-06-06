#include "PlusLinearFnc.h"

#include <cassert>

PlusLinearFnc::PlusLinearFnc(LinkFnc *fnc, FPType multiply, FPType add) : fnc_(fnc), multiply_(multiply), add_(add) {
	assert(fnc != NULL);
}; 

PlusLinearFnc::~PlusLinearFnc() {
	delete fnc_;
}; 

FPType PlusLinearFnc::evaluate(FPType linkFlow) {
	 return fnc_->evaluate(linkFlow) + add_ + multiply_ * linkFlow;
}; 

FPType PlusLinearFnc::evaluateDerivative(FPType linkFlow) {
	 return fnc_->evaluateDerivative(linkFlow) + multiply_;
}; 

void PlusLinearFnc::print()const  {
	fnc_->print();
	std::cout << "add = " << add_ << " multiply = " << multiply_ << std::endl;
}; 

