#ifndef LINE_SEARCH
#define LINE_SEARCH

#include "UsedTypes.h"

class LineSearch {
	
	public:
	
		virtual ~LineSearch(){};
		virtual FPType execute(FPType a, FPType b)=0;
		
	protected:
		LineSearch(){};
	
};

#endif
