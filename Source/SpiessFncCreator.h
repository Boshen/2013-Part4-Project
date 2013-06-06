#ifndef SPIESS_FNC_CREATOR
#define SPIESS_FNC_CREATOR

#include "LinkFnc.h"

class SpiessFncCreator {
	public:
		SpiessFncCreator();
		~SpiessFncCreator();
		
		void setParams(FPType freeFlow); // for const
		void setParams(FPType freeFlow, FPType capacity, FPType alpha, FPType beta, FPType betaSq); // for usual
		void setParams(const SpiessFncCreator &spCreator1, const SpiessFncCreator &spCreator2); // for comb
		void setParamsLinear(FPType add, FPType multiply);
		
		LinkFnc* create(FPType length, int lanes);
		void print() const;
		
	private:
		int id;
		bool isConst_;
		bool isComb_;
		bool isPlusLinear_;
		bool isDefault_;
		
		FPType freeFlow_;
		FPType capacity_;
		FPType alpha_;
		FPType beta_;
		FPType betaSq_;
		FPType freeFlow2_;
		FPType capacity2_;
		FPType alpha2_;
		FPType beta2_;
		FPType betaSq2_;
		FPType add_;
		FPType multiply_;
};

#endif
