#include "Bisection.h"
#include "Armijo.h"
#include "QuadApp.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <math.h>

Bisection::Bisection(FPType precision, Derivative *der) : precision_(precision), der_(der){
	assert(precision > 0.0 && der != NULL);
};

Bisection::~Bisection(){

};

FPType Bisection::execute(FPType a, FPType b){
	
	//std::cout << "a = " << a  << " b = " << b << std::endl; 
	assert(a <= b);
	FPType alpha = 0.0;
	FPType der = der_->calculate(b);
	if (der <= 0.0) return b; 
	if (der_->calculate(0.0) > 0.0) return 0.0;
	
	while (true) {
		alpha = (a + b) / 2.0;
		if (alpha == a || alpha == b) return alpha; // to prevent looping
		der = der_->calculate(alpha);
		if (der <= 0.0) {
			a = alpha;
		} else {
			b = alpha;
		};
		if (((b - a) <= 2 * precision_) || (fabs(der) <= 1e-25)){
			break;
		}
	}
	alpha = (a + b) / 2.0;
	return alpha;
};

FPType Bisection::getPrecision(){
	return precision_;
};

