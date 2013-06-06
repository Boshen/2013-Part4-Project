#ifndef ORIGIN_BASED_ALGO_EQII
#define ORIGIN_BASED_ALGO_EQII

#include "OriginBasedAlgo.h"

class OriginBasedAlgoEQII : public OriginBasedAlgo {
	public:
		OriginBasedAlgoEQII(OriginSet *originSet, ODMatrix *mat, StarNetwork *net, AddHook *component);
		~OriginBasedAlgoEQII();
		
		void mainLoop(OriginBush *bush, bool wasImproved, int nbIter);
};

#endif
