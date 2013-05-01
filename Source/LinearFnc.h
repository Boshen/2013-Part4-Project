#ifndef LINEAR_FNC
#define LINEAR_FNC

#include "LinkFnc.h"

/** This class implements linear time link function t(x) = a*x + b.
 */
class LinearFnc : public LinkFnc {
	
	public:
	
		LinearFnc(FPType a, FPType b);
		~LinearFnc();
	
		FPType evaluate(FPType arcFlow);
		FPType evaluateDerivative(FPType arcFlow);

		void print() const;
	
	private:
	
		FPType _param1;
		FPType _param2;
};

#endif
