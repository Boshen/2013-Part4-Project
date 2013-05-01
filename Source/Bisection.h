#ifndef NEW_BISECTION_
#define NEW_BISECTION_

#include "LineSearch.h"
#include "Derivative.h"

class Bisection : public LineSearch {
	
	public:
	
		Bisection(FPType precision, Derivative *der);
		~Bisection();
	
		FPType execute(FPType a, FPType b);
		FPType getPrecision();
	
	private:
		FPType _precision;
		Derivative *_der;
};

#endif

