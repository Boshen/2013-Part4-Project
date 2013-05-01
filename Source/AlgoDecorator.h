#ifndef _ALGO_DECOR_
#define _ALGO_DECOR_

#include "DecoratedEqAlgo.h"

class AlgoDecorator : public DecoratedEqAlgo {
	public:
		AlgoDecorator(DecoratedEqAlgo *algo);
		~AlgoDecorator();
		
		int execute();
		
	private:
		DecoratedEqAlgo *_component;
};

#endif
