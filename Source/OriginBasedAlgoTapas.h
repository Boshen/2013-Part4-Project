#ifndef ORIGIN_BASED_ALGO_TAPAS
#define ORIGIN_BASED_ALGO_TAPAS

#include "OriginBasedAlgo.h"
#include "PASManager.h"

class OriginBasedAlgoTapas : public OriginBasedAlgo {
	public:
		explicit OriginBasedAlgoTapas(OriginSet *originSet, ODMatrix *mat, StarNetwork *net, PASManager& pasSet, AddHook *component);
		~OriginBasedAlgoTapas();
	
		void doSmthAfterOrigins(int iter);		
		
	private:
		PASManager& pasSet_;
};

#endif
