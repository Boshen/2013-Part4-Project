#ifndef _EQUILIBRATION_II_
#define _EQUILIBRATION_II_

//#include "DecoratedEqAlgo.h"
#include "EquilibrationType.h"
#include "PathBasedAlgo.h"

class EquilibrationII : public EquilibrationType {
	public:
		EquilibrationII(PathBasedAlgo *algo);
		~EquilibrationII();
		
		void executeMainLoop(ODSet *odSet);
		
	private:
		PathBasedAlgo *_algo;
};

#endif
