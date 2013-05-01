#ifndef _EQUILIBRATION_I_
#define _EQUILIBRATION_I_

#include "EquilibrationType.h"
#include "PathBasedAlgo.h"

class EquilibrationI : public EquilibrationType {
	public:
		EquilibrationI(PathBasedAlgo *algo);
		~EquilibrationI();
		
		void executeMainLoop(ODSet *odSet);
		
	private:
		PathBasedAlgo *_algo;
};

#endif
