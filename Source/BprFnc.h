#ifndef BPR_FNC_
#define BPR_FNC_

#include "LinkFnc.h"

/** This class implements BPR time link function t(x) = freeFlow*(1 + B*(x/capacity)^power).
 */
class BprFnc : public LinkFnc {
	
	public:
	
		BprFnc(FPType freeFlow, FPType B, FPType capacity, FPType power);
		~BprFnc();
	
		FPType evaluate(FPType linkFlow) const;
		FPType evaluateDerivative(FPType linkFlow) const;
		FPType evaluateSecondDerivative(FPType linkFlow) const;
	
		void print() const;
	
		LinkFnc * clone() const {return new BprFnc(*this);}
	
	private:
	
		const FPType _freeFlow;
		const FPType _B;
		const FPType _capacity;
		const FPType _power;

};

#endif
