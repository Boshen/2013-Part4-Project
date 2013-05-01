#ifndef BPR_FNC_
#define BPR_FNC_

#include "LinkFnc.h"

/** This class implements BPR time link function t(x) = freeFlow*(1 + B*(x/capacity)^power).
 */
class BprFnc : public LinkFnc {
	
	public:
	
	BprFnc(FPType freeFlow, FPType B, FPType capacity, FPType power);
	~BprFnc();
	
	FPType evaluate(FPType linkFlow);
	FPType evaluateDerivative(FPType linkFlow);
	FPType evaluateSecondDerivative(FPType linkFlow);
	
	void print() const;
	
	LinkFnc * clone() const {return new BprFnc(*this);}
	private:
	
	FPType _freeFlow;
	FPType _B;
	FPType _capacity;
	FPType _power;

};

#endif
