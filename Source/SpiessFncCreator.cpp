#include "SpiessFncCreator.h"
#include "ConstFnc.h"
#include "SpiessFncComb.h"
#include "PlusLinearFnc.h"
#include "Error.h"

#include <stdlib.h>
#include <iostream>

SpiessFncCreator::SpiessFncCreator() : isConst_(false), isComb_(false), isPlusLinear_(false), isDefault_(false), freeFlow_(0.0), capacity_(0.0), alpha_(0.0), 
					beta_(0.0), betaSq_(0.0), freeFlow2_(0.0), capacity2_(0.0), alpha2_(0.0), beta2_(0.0), betaSq2_(0.0), add_(0.0), multiply_(0.0) {

};

SpiessFncCreator::~SpiessFncCreator(){

};

void SpiessFncCreator::setParams(FPType freeFlow){
	isConst_ = true;
	freeFlow_ = freeFlow;
};

void SpiessFncCreator::setParams(FPType freeFlow, FPType capacity, FPType alpha, FPType beta, FPType betaSq){
	isDefault_ = true;
	freeFlow_ = freeFlow;
	capacity_ = capacity;
	alpha_ = alpha;
	beta_ = beta;
	betaSq_ = betaSq;
};

void SpiessFncCreator::setParams(const SpiessFncCreator &spCreator1, const SpiessFncCreator &spCreator2){
	isComb_ = true;
	
	freeFlow_ = spCreator1.freeFlow_;
	capacity_ = spCreator1.capacity_;
	alpha_ =  spCreator1.alpha_;
	beta_ =  spCreator1.beta_;
	betaSq_ =  spCreator1.betaSq_;
	
	freeFlow2_ = spCreator2.freeFlow_;
	capacity2_ = spCreator2.capacity_;
	alpha2_ =  spCreator2.alpha_;
	beta2_ =  spCreator2.beta_;
	betaSq2_ =  spCreator2.betaSq_;
};

void SpiessFncCreator::setParamsLinear(FPType add, FPType multiply){
	isPlusLinear_ = true;
	add_ = add;
	multiply_ = multiply;
};

LinkFnc* SpiessFncCreator::create(FPType length, int lanes){
	LinkFnc *fnc = NULL;
	if (isConst_) {
		fnc = new ConstFnc(freeFlow_);
	} else if (isComb_){
		SpiessFnc *fnc1 = new SpiessFnc(freeFlow_ * length, capacity_ * lanes, alpha_, beta_, betaSq_);
		SpiessFnc *fnc2 = new SpiessFnc(freeFlow2_ * length, capacity2_ * (lanes + 1), alpha2_, beta2_, betaSq2_);
		fnc = new SpiessFncComb(fnc1, fnc2);
	} else if (isDefault_) {
		fnc = new SpiessFnc(freeFlow_ * length, capacity_ * lanes, alpha_, beta_, betaSq_);
	} else {
		throw Error("SetParams() must be called before link function creation.");
	}
	if (isPlusLinear_) {
		return new PlusLinearFnc(fnc, add_, multiply_ / lanes);
	} 
	return fnc;
};

void SpiessFncCreator::print() const{
	std::cout << "freeFlow = " << freeFlow_ << " capacity = " << capacity_ << " alpha = " << alpha_ << " beta = " << beta_ << " betaSq = " << betaSq_ << std::endl;
};
