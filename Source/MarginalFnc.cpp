#include "MarginalFnc.h"

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cassert>

MarginalFnc::MarginalFnc(LinkFnc *linkFncPointer){
	assert(linkFncPointer != NULL);
	_linkFncPointer = linkFncPointer;
};

MarginalFnc::~MarginalFnc(){
	delete  _linkFncPointer;
};

FPType MarginalFnc::evaluate(FPType linkFlow){
	return _linkFncPointer->evaluate(linkFlow) + linkFlow * _linkFncPointer->evaluateDerivative(linkFlow);
};

FPType MarginalFnc::evaluateDerivative(FPType linkFlow){
	return 2 * _linkFncPointer->evaluateDerivative(linkFlow) + linkFlow * _linkFncPointer->evaluateSecondDerivative(linkFlow);
};

void MarginalFnc::print() const{
	//std::cout << "linkFncPointer = " << _linkFncPointer << " toll = " << _linkFncPointer->evaluateToll() << std::endl;_linkFncPointer->
	_linkFncPointer->print();
};

FPType MarginalFnc::getSOCost(FPType linkFlow) const{
	return _linkFncPointer->evaluate(linkFlow);
};
