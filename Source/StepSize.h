#ifndef _STEP_SIZE_ 
#define _STEP_SIZE_

//#include "StepSizeABC.h"
#include "LineSearch.h"
#include "DescDirection.h"

class StepSize {//: public StepSizeABC {
	public:
		
		virtual ~StepSize();
		
		FPType getStepSize(DescDirection *algo);
		//void fillIndexes();
		
	protected:
		
		StepSize(LineSearch *lineSearch);
		LineSearch *_lineSearch;
		//DescDirection *_algo;
		//FPType _precision;
		//int _size;
		//int _nbLinks;
		//int *_indexes;
		
		virtual void initialiseDerivative(DescDirection *algo) = 0;
};

#endif
