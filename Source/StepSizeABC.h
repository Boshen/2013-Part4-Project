#ifndef _STEP_SIZE_ABC_
#define _STEP_SIZE_ABC_

#include "UsedTypes.h"

#include <stdlib.h>
#include <iostream>

class StepSizeABC {
	public:
		virtual ~StepSizeABC(){};
		virtual FPType getStepSize() = 0;
		
	protected:
		StepSizeABC(){};
	
};

#endif
