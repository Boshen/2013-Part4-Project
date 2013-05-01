#ifndef _NON_ADDITIVE_PATH_COST_
#define _NON_ADDITIVE_PATH_COST_

#include "PathCost.h"

class NonAdditivePC : public PathCost {
	public:
		NonAdditivePC();
		~NonAdditivePC();
		FPType calculate(Path *path) const;
};

#endif
