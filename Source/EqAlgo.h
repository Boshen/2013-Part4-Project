#ifndef _EQ_ALGO_
#define _EQ_ALGO_

#include "DecoratedEqAlgo.h"

class EqAlgo : public DecoratedEqAlgo {
	
	public: 
		virtual ~EqAlgo() {};
		virtual int execute() = 0;
		
	protected:
		EqAlgo(){};
		
};

#endif
