#include "Derivative.h"

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cassert>

Derivative::Derivative(FPType zeroFlow, LinkFncContainer *fnc) : _size(0), _x(NULL), _y(NULL),  _indexes(NULL),
								_zeroFlow(zeroFlow), _fnc(fnc){
};

Derivative::~Derivative(){

};

FPType Derivative::calculate(FPType alpha) const {
	FPType sum = 0.0;
	FPType inputFlow = 0.0;
	LinkFnc *link = NULL;
	int index = -1;
	
	for (int i = 0; i < _size; i++){	
		index = _indexes[i];
		assert(index != -1);
		inputFlow = _x[index] + alpha * _y[index];
		if (fabs(inputFlow) <= _zeroFlow) inputFlow = 0.0;
		link = _fnc->getLinkFnc(index);
		sum += _y[index] * link->evaluate(inputFlow);
	}
	return sum;//*/
};

void Derivative::setDataPointers(int size, FPType *x, FPType *y, int *indexes){
	_size = size;
	_x = x;
	_y = y;
	_indexes = indexes;
};

int Derivative::getSize() const{
	return _size;
};

FPType Derivative::getX(int index) const{
	assert((index >= 0) && (index < _size));
	return _x[_indexes[index]];
};
		
FPType Derivative::getY(int index) const{
	assert((index >= 0) && (index < _size));
	return _y[_indexes[index]];
};

LinkFnc* Derivative::getLinkFnc(int index) const{
	assert((index >= 0) && (index < _size));
	return  _fnc->getLinkFnc(_indexes[index]);
};

FPType Derivative::getZeroFlow() const{
	return _zeroFlow;
};
