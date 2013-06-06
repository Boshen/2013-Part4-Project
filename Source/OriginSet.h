#ifndef _ORIGIN_SET_
#define _ORIGIN_SET_

#include "OriginBush.h"
#include "ODMatrix.h"
#include "StarNetwork.h"
#include "InitialiseSolution.h"
#include "AONAssignment.h"
#include "ShortestPath.h"
#include "ConvMeasure.h"

class OriginSet : public InitialiseSolution {
	
	public:
		OriginSet(ODMatrix *mat, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType zeroFlow, FPType dirTol, bool useLUCE, bool useMultiStep);
		~OriginSet();
		
		// for OriginBasedAlgo
		void initialise();
		bool isConverged();
		FPType getGapVal() const;
		
		// for iterating
		OriginBush* beginSet();
		OriginBush* getNextSet();
		
		// fot InitialiseSolution
		void initialiseItself(StarLink* link, PairOD *dest);
		
		void loadOriginFlows();
		
		void print();
		void printNet();
		void printTotalOriginFlows();
		
	private:
		StarNetwork *net_;
		int nbOrigins_;
		OriginBush **bushes_;
		int *indexes_;
		int nbLinks_;
		
		AONAssignment *aon_;
		ConvMeasure *conv_;
		
		// for iterating
		int currBushIndex_;
		
};

#endif
