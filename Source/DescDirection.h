#ifndef _DESC_DIRECTION_
#define _DESC_DIRECTION_

#include "UsedTypes.h"

class DescDirection {
	
	public:
		virtual ~DescDirection(){};
		virtual FPType* getProjectedDirection() = 0;
		virtual FPType getUpperBound() = 0;
		virtual FPType* getLinkFlows() = 0;
		virtual int getSize() = 0;
		virtual int* getIndexes() = 0;
		
	protected:
		DescDirection(){};
};

#endif
