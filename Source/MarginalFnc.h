#ifndef MARGINAL_COST
#define MARGINAL_COST

#include "LinkFnc.h"

class MarginalFnc : public LinkFnc {
	
	public:
		MarginalFnc(LinkFnc *linkFncPointer);
		~MarginalFnc();
	
		FPType evaluate(FPType arcFlow);
		FPType evaluateDerivative(FPType arcFlow);
	
		void print() const;

		FPType getSOCost(FPType arcFlow) const;
	
	private:
		LinkFnc *_linkFncPointer;
	
};

#endif
