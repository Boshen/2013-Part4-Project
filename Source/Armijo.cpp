#include "Armijo.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <math.h>

Armijo::Armijo(FPType decriment, Derivative *der){
	assert(decriment > 0.0 && der != NULL);
	_decriment = decriment;
	_der = der;
};

Armijo::~Armijo(){

};

FPType Armijo::execute(FPType a, FPType b){
	
	FPType alpha = b;
	if (_der->calculate(0.0) > 0.0) return 0.0; // patological case when derivative is positive in 0.0
	FPType der = 0.0;
	while (true) {
		der = _der->calculate(alpha);
		if (der > 0.0) {
			alpha /= _decriment; 
		} else {
			return alpha;
		}
		
	}
	return alpha;
};

FPType Armijo::getDecriment(){
	return _decriment;
};
