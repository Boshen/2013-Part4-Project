#ifndef SPIESS_FNC_COMB
#define SPIESS_FNC_COMB

#include "SpiessFnc.h"

class SpiessFncComb : public LinkFnc {
	public:
		SpiessFncComb(SpiessFnc* fnc1, SpiessFnc* fnc2); // responsible for memory deallocation of these functions
		~SpiessFncComb();
		
		FPType evaluate(FPType linkFlow);
		FPType evaluateDerivative(FPType linkFlow);
		void print() const;
		
		LinkFnc * clone() const {return new SpiessFncComb(*this);}
	private:
		SpiessFnc *fnc1_;
		SpiessFnc *fnc2_;
};

#endif
