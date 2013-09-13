#ifndef _STEP_SIZE_ADDITIVE_ 
#define _STEP_SIZE_ADDITIVE_

#include "StepSize.h"
#include "Derivative.h"

class StepSizeAdd : public StepSize {
	public:
		StepSizeAdd(LineSearch *lineSearch, Derivative *der);
		~StepSizeAdd();
		
		void initialiseDerivative(DescDirection *algo);
	private:
		Derivative *_der;
};

#endif
