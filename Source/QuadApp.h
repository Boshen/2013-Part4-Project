#ifndef _QUADRATIC_APP_
#define _QUADRATIC_APP_

#include "LineSearch.h"
#include "LinkFncContainer.h"
#include "Derivative.h"

class QuadApp : public LineSearch {
	
	public:
	
		QuadApp(Derivative *der);
		~QuadApp();
	
		FPType execute(FPType a, FPType b);
		
	private:
		Derivative *_der;
};

#endif

