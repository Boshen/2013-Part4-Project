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
		
		FPType evaluate(FPType linkFlow);
		FPType evaluateDerivative(FPType linkFlow);
		void print() const;
		
		LinkFnc * clone() const {return new SpiessFnc(*this);}
	
	private:
	
		FPType freeFlow_;
		FPType capacity_;
		FPType alpha_;
		FPType beta_;
		FPType betaSq_;
		
};

#endif
