#ifndef _PATH_BASED_ALGO_
#define _PATH_BASED_ALGO_

#include "EqAlgo.h"
#include "EquilibrationType.h"
#include "PathSet.h"

class PathBasedAlgo : public EqAlgo {//, public EquilibrationType {
	
	public:
		PathBasedAlgo(PathSet *pathSet, bool useEqI, AddHook *component, ConvMeasure *conv); //, StarNetwork *net, ODMatrix *mat);
		virtual ~PathBasedAlgo();
		int execute();
		bool mainLoop(ODSet *odSet);
		
		void print();
		
	private:
		PathSet *_pathSet;
		EquilibrationType *_eq;
		ConvMeasure *_conv;
		//StarNetwork *net_;
		//ODMatrix *mat_;
};

#endif
