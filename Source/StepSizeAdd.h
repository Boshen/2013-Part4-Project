#ifndef _STEP_SIZE_ADDITIVE_ 
#define _STEP_SIZE_ADDITIVE_

#include "StepSize.h"
#include "Derivative.h"

class StepSizeAdd : public StepSize {
	public:
		StepSizeAdd(DescDirection *algo, LineSearch *lineSearch, Derivative *der);
		~StepSizeAdd();
		
		void initialiseDerivative();
	private:
		Derivative *_der;
};

#endif
