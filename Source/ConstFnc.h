#ifndef CONST_FNC
#define CONST_FNC

#include "LinkFnc.h"

class ConstFnc : public LinkFnc {
	public:
		ConstFnc(FPType param);
		~ConstFnc();
		
		FPType evaluate(FPType linkFlow) const;
		FPType evaluateDerivative(FPType linkFlow) const;
		void print() const;
		
		LinkFnc * clone() const {return new ConstFnc(*this);}
	private:
		const FPType param_;
};

#endif
