#ifndef PLUS_LINEAR_FNC
#define PLUS_LINEAR_FNC

#include "LinkFnc.h"

class PlusLinearFnc : public LinkFnc {
	public:
		explicit PlusLinearFnc(LinkFnc *fnc, FPType multiply, FPType add);
		~PlusLinearFnc();
		
		FPType evaluate(FPType linkFlow) const;
		FPType evaluateDerivative(FPType linkFlow) const;
		void print() const;
		
		LinkFnc * clone() const {return new PlusLinearFnc(*this);}
		
	private:
		LinkFnc *fnc_;
		const FPType multiply_;
		const FPType add_;
};

#endif
