#include "SpiessFncCreator.h"
#include "ConstFnc.h"
#include "SpiessFncComb.h"

#include <stdlib.h>
#include <iostream>

SpiessFncCreator::SpiessFncCreator() : isConst_(false), isComb_(false), freeFlow_(0.0), capacity_(0.0), alpha_(0.0), beta_(0.0), betaSq_(0.0), 
					freeFlow2_(0.0), capacity2_(0.0), alpha2_(0.0), beta2_(0.0), betaSq2_(0.0) {

};

SpiessFncCreator::~SpiessFncCreator(){

};

void SpiessFncCreator::setParams(FPType freeFlow){
	isConst_ = true;
	freeFlow_ = freeFlow;
};

void SpiessFncCreator::setParams(FPType freeFlow, FPType capacity, FPType alpha, FPType beta, FPType betaSq){
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

LinkFnc* SpiessFncCreator::create(FPType length, int lanes){
	if (isConst_) {
		return new ConstFnc(freeFlow_);
	} else if (isComb_){
		SpiessFnc *fnc1 = new SpiessFnc(freeFlow_ * length, capacity_ * lanes, alpha_, beta_, betaSq_);
		SpiessFnc *fnc2 = new SpiessFnc(freeFlow2_ * length, capacity2_ * (lanes + 1), alpha2_, beta2_, betaSq2_);
		return new SpiessFncComb(fnc1, fnc2);
	} 
	return new SpiessFnc(freeFlow_ * length, capacity_ * lanes, alpha_, beta_, betaSq_);
};

void SpiessFncCreator::print() const{
	std::cout << "freeFlow = " << freeFlow_ << " capacity = " << capacity_ << " alpha = " << alpha_ << " beta = " << beta_ << " betaSq = " << betaSq_ << std::endl;
};
