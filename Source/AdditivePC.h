#ifndef _ADDITIVE_PATH_COST_
#define _ADDITIVE_PATH_COST_

#include "PathCost.h"

class AdditivePC : public PathCost {
	public:
		AdditivePC();
		~AdditivePC();
		FPType calculate(Path *path) const;
};

#endif
