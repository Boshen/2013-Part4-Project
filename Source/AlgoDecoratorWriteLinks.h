#ifndef ALGO_DECOR_WRITE_LINKS
#define ALGO_DECOR_WRITE_LINKS

#include "DecoratedEqAlgo.h"
#include "StarNetwork.h"
#include "Timer.h"

#include <string>

class AlgoDecoratorWriteLinks : public DecoratedEqAlgo {
	public:
		AlgoDecoratorWriteLinks(DecoratedEqAlgo *algo, StarNetwork *net, const std::string &fileName, Timer &timer);
		~AlgoDecoratorWriteLinks();
		
		int execute();
		
	private:
		DecoratedEqAlgo *component_;
		StarNetwork *net_;
		std::string fileName_;
		Timer &timer_;
};

#endif
