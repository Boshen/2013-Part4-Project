#ifndef LINK_FCN
#define LINK_FCN

#include "UsedTypes.h"

#include <stdlib.h>
#include <iostream>
/** Abstract class used to represent time link function. Any concrete time link 
 *  function class MUST inherit this class and implement the only virtual method.
 */
class LinkFnc {
	
	public:
	
		virtual ~LinkFnc(){};
	
		virtual FPType evaluate(FPType linkFlow) const =0;
		virtual FPType evaluateDerivative(FPType linkFlow) const =0;
		virtual FPType evaluateSecondDerivative(FPType linkFlow) const { return 0.0; };

		// for marginal cost function
		virtual FPType getSOCost(FPType linkFlow) const {return 0.0;};
	
		virtual void print() const =0;
		
		virtual LinkFnc * clone() const =0;
	
	protected:
		LinkFnc(){};
};

#endif
