#ifndef _ORIGIN_BASED_ALGO_
#define _ORIGIN_BASED_ALGO_

#include "EqAlgo.h"
#include "OriginSet.h"

class OriginBasedAlgo : public EqAlgo {
	public:
		OriginBasedAlgo(OriginSet *originSet);
		~OriginBasedAlgo();
		
		int execute();
		
		bool mainLoop(OriginBush *bush, bool wasImproved);
		
	private:
		OriginSet *originSet_;
};

#endif
