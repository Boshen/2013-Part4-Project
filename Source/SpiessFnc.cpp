#include "SpiessFnc.h"
#include "Constants.h"

#include <cassert>
#include <stdio.h>
#include <math.h>
#include <iostream>

// beta is acctually 2 - beta
SpiessFnc::SpiessFnc(FPType freeFlow, FPType capacity, FPType alpha, FPType beta, FPType betaSq) : freeFlow_(freeFlow), capacity_(capacity), alpha_(alpha),
									beta_(beta), betaSq_(betaSq) {
	assert(betaSq >= 0.0);
};

SpiessFnc::~SpiessFnc(){
	//std::cout << "SpiessFnc destructor" << std::endl;
};

FPType SpiessFnc::evaluate(FPType linkFlow){
	FPType input = alpha_ * (1.0 - linkFlow / capacity_);
	return freeFlow_ * ( beta_ - input + sqrt(input * input + betaSq_));
};

FPType  SpiessFnc::evaluateDerivative(FPType linkFlow){
	FPType input = 1.0 - linkFlow / capacity_;
	FPType alCap = alpha_ / capacity_;
	return freeFlow_ * (alCap - (alCap * alpha_ * input) / sqrt(alpha_ * alpha_ * input * input + betaSq_) );
};

void SpiessFnc::print() const{
	std::cout << "freeFlow = " << freeFlow_ << " alpha = " << alpha_ << " capacity = " << capacity_ << " beta = " << beta_ << std::endl;
};
