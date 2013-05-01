#ifndef _STEP_SIZE_SPARSITY_
#define _STEP_SIZE_SPARSITY_

#include "StepSize.h"

class StepSizeSparsity : public StepSizeABC{
	public:
		StepSizeSparsity(StepSize *component);
		~StepSizeSparsity();
		
		FPType getStepSize();
		
	private:
		StepSize *_component;
};

#endif
