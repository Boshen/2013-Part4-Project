#include "Bisection.h"
#include "Armijo.h"
#include "QuadApp.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <math.h>

Bisection::Bisection(FPType precision, Derivative *der){
	assert(precision > 0.0 && der != NULL);
	_precision = precision;
	_der = der;
};

Bisection::~Bisection(){

};

FPType Bisection::execute(FPType a, FPType b){
	
	assert(a <= b);
	FPType alpha = 0.0;
	FPType der = _der->calculate(b);
	if (der <= 0.0) return b; 
	if (_der->calculate(0.0) > 0.0) return 0.0;
	
	while (true) {
		alpha = (a + b) / 2.0;
		der = _der->calculate(alpha);
		if (der <= 0.0) {
			a = alpha;
		} else {
			b = alpha;
		};
		if (((b - a) <= 2 * _precision) || (fabs(der) <= 1e-20)){
			break;
		}
	}
	alpha = (a + b) / 2.0;
	return alpha;
};

FPType Bisection::getPrecision(){
	return _precision;
};

