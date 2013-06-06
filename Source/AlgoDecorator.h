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
		
		int execute();
		
	private:
		DecoratedEqAlgo *_component;
		AddHookStoreOut *_hook;
		std::string _fileName;
		Timer &timer_;
};

#endif
