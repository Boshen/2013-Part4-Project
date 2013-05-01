#include "QuadApp.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <math.h>

QuadApp::QuadApp(Derivative *der){
	_der = der;
};

QuadApp::~QuadApp(){

};

FPType QuadApp::execute(FPType a, FPType b){
	FPType sum1 = 0.0;
	FPType sum2 = 0.0;
	LinkFnc* link = NULL;
	Derivative &der = *_der;
	int size = der.getSize(); 
	FPType x = 0.0;
	FPType y = 0.0;
	for (int i = 0; i < size; i++) {
		link = der.getLinkFnc(i); 
		x = der.getX(i); 
		y = der.getY(i);
		
		sum1 += link->evaluate(x) * y;
		sum2 += link->evaluateDerivative(x) * y * y;
	}
	if (fabs(sum1) <= 1e-15) {
		return 0.0;
	}
	if (sum1 >= 0.0) { 
		return 0.0;
	} 
	FPType returnVal = -sum1 / sum2;
	if (returnVal > b) returnVal = b;
	return returnVal;
};

