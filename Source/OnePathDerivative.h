#ifndef _ONE_PATH_DERIVATIVE_
#define _ONE_PATH_DERIVATIVE_

#include "Path.h"

class OnePathDerivative {
	public:
		OnePathDerivative(FPType slope);
		~OnePathDerivative();
		
		FPType calculate(Path *path);
		
	private:
		const int _slope;
};

#endif
