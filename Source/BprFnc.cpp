#include "BprFnc.h"

#include <cassert>
#include <stdio.h>
#include <math.h>
#include <iostream>

BprFnc::BprFnc(FPType freeFlow, FPType B, FPType capacity, FPType power) : _freeFlow(freeFlow), _B(B), _capacity(capacity), _power(power){

};

BprFnc::~BprFnc(){

};

FPType BprFnc::evaluate(FPType linkFlow) const {
	return _freeFlow * (1 + _B * pow(linkFlow / _capacity, _power));
};

FPType  BprFnc::evaluateDerivative(FPType linkFlow) const {
	//TODO think again - starts to loop for Barcelona instance!!!
	if ((fabs(_power) <= 1e-25) || (fabs(_B) <= 1e-70)) return 0.0; //in order to avoid problems with floating point arithmatic
	return _freeFlow * _B * _power * pow(linkFlow, _power - 1) / pow(_capacity, _power);
};

void BprFnc::print() const{
	std::cout << "freeFlow = " << _freeFlow << " B = " << _B << " capacity = " << _capacity << " _power = " << _power << std::endl;
};

FPType BprFnc::evaluateSecondDerivative(FPType linkFlow) const {
	if (_power - 1e-7 < 2) return 0.0;  // TODO: not sure about this!!! //in order to avoid problems with floating point arithmatic
	return _freeFlow * _B * _power / pow(_capacity, _power) * (_power - 1) * pow(linkFlow, _power - 2);
};
