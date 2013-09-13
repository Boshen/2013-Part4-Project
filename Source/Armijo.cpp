#include "Armijo.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <math.h>

Armijo::Armijo(FPType decriment, Derivative *der) : decriment_(decriment), der_(der){
	assert(decriment > 0.0 && der != NULL);
};

Armijo::~Armijo(){

};

FPType Armijo::execute(FPType a, FPType b){
	
	FPType alpha = b;
	if (der_->calculate(0.0) > 0.0) return 0.0; // patological case when derivative is positive in 0.0
	FPType der = 0.0;
	while (true) {
		der = der_->calculate(alpha);
		if (der > 0.0) {
			alpha /= decriment_; 
		} else {
			return alpha;
		}
		if (alpha < 1e-25) return alpha; // to prevent looping if derivative is still positive, when it is close to zero
		
	}
	return alpha;
};

FPType Armijo::getDecriment(){
	return decriment_;
};
