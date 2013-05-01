#ifndef _ARMIJO_
#define _ARMIJO_

#include "LineSearch.h"
#include "Derivative.h"

class Armijo : public LineSearch {
	
	public:
	
		Armijo(FPType decriment, Derivative* der);
		~Armijo();
	
		FPType execute(FPType a, FPType b);
	
		FPType getDecriment();
	
	private:
	
		FPType _decriment;
		Derivative *_der;
	
};

#endif

