#include "SpiessFncComb.h"
#include "Error.h"

SpiessFncComb::SpiessFncComb(SpiessFnc* fnc1, SpiessFnc* fnc2) : fnc1_(fnc1), fnc2_(fnc2){
	if (fnc1 == NULL || fnc2 == NULL) {
		delete fnc1_;
		delete fnc2_;
		throw Error("Both link cost functions must be non-NULL.");	
	}
};

SpiessFncComb::~SpiessFncComb(){
	delete fnc1_;
	delete fnc2_;
};
		
FPType SpiessFncComb::evaluate(FPType linkFlow) const {
	return fnc1_->evaluate(linkFlow) + fnc2_->evaluate(linkFlow);
};

FPType SpiessFncComb::evaluateDerivative(FPType linkFlow) const {
	return fnc1_->evaluateDerivative(linkFlow) + fnc2_->evaluateDerivative(linkFlow);
};

void SpiessFncComb::print() const {
	fnc1_->print();
	fnc2_->print();
};
