#ifndef _STEP_SIZE_ 
#define _STEP_SIZE_

//#include "StepSizeABC.h"
#include "LineSearch.h"
#include "DescDirection.h"

class StepSize {//: public StepSizeABC {
	public:
		StepSize(DescDirection *algo, LineSearch *lineSearch);
		virtual ~StepSize();
		
		FPType getStepSize();
		//void fillIndexes();
		
	protected:
	
		LineSearch *_lineSearch;
		DescDirection *_algo;
		//FPType _precision;
		//int _size;
		//int _nbLinks;
		//int *_indexes;
		
		virtual void initialiseDerivative() = 0;
};

#endif
