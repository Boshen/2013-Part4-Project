#ifndef CONST_FNC
#define CONST_FNC

#include "LinkFnc.h"

class ConstFnc : public LinkFnc {
	public:
		ConstFnc(FPType param);
		~ConstFnc();
		
		FPType evaluate(FPType linkFlow);
		FPType evaluateDerivative(FPType linkFlow);
		void print() const;
		
		LinkFnc * clone() const {return new ConstFnc(*this);}
	private:
		FPType param_;
};

#endif
