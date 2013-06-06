#include "StepSize.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

StepSize::StepSize(DescDirection *algo, LineSearch *lineSearch) : _lineSearch(lineSearch), _algo(algo) {
	/*_lineSearch = lineSearch;
	_algo = algo;
	_precision = precision;
	_size = nbLinks;
	_nbLinks = nbLinks;
	_indexes = new int[nbLinks];
	for (int i = 0; i < nbLinks; i++) {
		_indexes[i] = i;
	}*/
};

StepSize::~StepSize(){
	//std::cout << "destructor of StepSize" << std::endl;
	//delete[] _indexes;
};

FPType StepSize::getStepSize(){
	initialiseDerivative();
	return  _lineSearch->execute(0.0, _algo->getUpperBound());
};

/*void StepSize::fillIndexes() {
	int indSize = 0;
	FPType *y = _algo->getProjectedDirection();
	for (int k = 0; k < _nbLinks; k++) {
		if (fabs(y[k]) > _precision) {
			_indexes[indSize] = k;
			indSize++;
		}
	}
	_size = indSize;
};*/

