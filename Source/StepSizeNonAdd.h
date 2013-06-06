#ifndef _STEP_SIZE_NON_ADDITIVE_ 
#define _STEP_SIZE_NON_ADDITIVE_

#include "StepSize.h"
#include "Derivative.h"

class StepSizeNonAdd : public StepSize {
	public:
		StepSizeNonAdd(DescDirection *algo, LineSearch *lineSearch);
		~StepSizeNonAdd();
		
		void initialiseDerivative();
	private:
		//Derivative *_der;
};

#endif
