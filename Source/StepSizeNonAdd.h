#ifndef _STEP_SIZE_NON_ADDITIVE_ 
#define _STEP_SIZE_NON_ADDITIVE_

#include "StepSize.h"
#include "Derivative.h"

class StepSizeNonAdd : public StepSize {
	public:
		StepSizeNonAdd(LineSearch *lineSearch);
		~StepSizeNonAdd();
		
		void initialiseDerivative(DescDirection *algo);
	private:
		//Derivative *_der;
};

#endif
