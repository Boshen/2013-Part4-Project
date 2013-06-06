#ifndef _EQ_ALGO_
#define _EQ_ALGO_

#include "DecoratedEqAlgo.h"
#include "AddHook.h"
#include "UsedTypes.h"

class EqAlgo : public DecoratedEqAlgo {
	
	public: 
		virtual ~EqAlgo() {};
		virtual int execute() = 0;
		
		void doSmthAfterLoop(double timePassed, FPType gap){component_->produceOut(timePassed, gap); };
		
	protected:
		EqAlgo(AddHook *component) : component_(component){};
	private:	
		AddHook *component_;
		
};

#endif
