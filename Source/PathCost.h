#ifndef _PATH_COST_
#define _PATH_COST_

#include "Path.h"
#include "UsedTypes.h"

class PathCost {
	public:
		virtual ~PathCost(){};
		virtual FPType calculate(Path *path) const = 0;
	protected:
		PathCost(){};
};

#endif
