#ifndef LINEAR_FNC
#define LINEAR_FNC

#include "LinkFnc.h"

/** This class implements linear time link function t(x) = a*x + b.
 */
class LinearFnc : public LinkFnc {
	
	public:
	
		LinearFnc(FPType a, FPType b);
		~LinearFnc();
	
		FPType evaluate(FPType arcFlow) const;
		FPType evaluateDerivative(FPType arcFlow) const;

		void print() const;
	
	private:
	
		const FPType _param1;
		const FPType _param2;
};

#endif
