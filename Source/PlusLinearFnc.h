#ifndef PLUS_LINEAR_FNC
#define PLUS_LINEAR_FNC

#include "LinkFnc.h"

class PlusLinearFnc : public LinkFnc {
	public:
		explicit PlusLinearFnc(LinkFnc *fnc, FPType multiply, FPType add);
		~PlusLinearFnc();
		
		FPType evaluate(FPType linkFlow);
		FPType evaluateDerivative(FPType linkFlow);
		void print() const;
		
		LinkFnc * clone() const {return new PlusLinearFnc(*this);}
		
	private:
		LinkFnc *fnc_;
		FPType multiply_;
		FPType add_;
};

#endif
