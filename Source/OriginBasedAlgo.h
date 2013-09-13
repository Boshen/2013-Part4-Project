#ifndef _ORIGIN_BASED_ALGO_
#define _ORIGIN_BASED_ALGO_

#include "EqAlgo.h"
#include "OriginSet.h"
#include "ODMatrix.h"
#include "StarNetwork.h"

class OriginBasedAlgo : public EqAlgo {
	public:
		OriginBasedAlgo(OriginSet *originSet, ODMatrix *mat, StarNetwork *net, AddHook *component);
		virtual ~OriginBasedAlgo();
		
		int execute();
		
		virtual bool mainLoop(OriginBush *bush, bool wasImproved, int nbIter); // default - EQI
		
	protected:
		virtual void doSmthAfterOrigins(int iter){}; // hook method - does nothing by default
		
	private:
		OriginSet *originSet_;
		ODMatrix *mat_;
		StarNetwork *net_;
};

#endif
