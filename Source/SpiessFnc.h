#ifndef SPIESS_FNC_
#define SPIESS_FNC_

#include "LinkFnc.h"

/** This class implements BPR time link function t(x) = freeFlow*(1 + B*(x/capacity)^power).
 */
class SpiessFnc : public LinkFnc {
	
	public:
		explicit SpiessFnc(FPType freeFlow, FPType capacity, FPType alpha, FPType beta, FPType betaSq);
		//explicit SpiessFnc(FPType freeFlow, FPType alpha, FPType capacity, FPType toll);
		//explicit SpiessFnc(FPType freeFlow, FPType alpha, FPType beta, FPType capacity, FPType toll);
		~SpiessFnc();
		
		FPType evaluate(FPType linkFlow) const;
		FPType evaluateDerivative(FPType linkFlow) const;
		void print() const;
		
		LinkFnc * clone() const {return new SpiessFnc(*this);};
	
	private:
	
		const FPType freeFlow_;
		const FPType capacity_;
		const FPType alpha_;
		const FPType beta_;
		const FPType betaSq_;
		
};

#endif
