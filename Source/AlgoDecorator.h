#ifndef _ALGO_DECOR_
#define _ALGO_DECOR_

#include "DecoratedEqAlgo.h"
#include "AddHookStoreOut.h"
#include "Timer.h"

#include <string>

class AlgoDecorator : public DecoratedEqAlgo {
	public:
		AlgoDecorator(DecoratedEqAlgo *algo, AddHookStoreOut *hook, const std::string& fileName, Timer &timer);
		~AlgoDecorator();
		
		virtual int execute();
		
	private:
		DecoratedEqAlgo *component_;
		AddHookStoreOut *hook_;
		std::string fileName_;
		Timer &timer_;
};

#endif
