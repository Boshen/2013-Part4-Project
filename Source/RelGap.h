#ifndef _REL_GAP_
#define _REL_GAP_

#include "ConvMeasure.h"
#include "StarNetwork.h"
#include "ODMatrix.h"
#include "ShortestPath.h"

class RelGap : public ConvMeasure {
	public:
		RelGap(FPType precision, StarNetwork *net, ODMatrix *mat, ShortestPath *shPath);
		~RelGap();
		
		bool isConverged();
		bool isConverged(FPType minTravelTime);
		
	private:
		
		StarNetwork *_net;
		ODMatrix *_mat;
		ShortestPath *_shPath;
		//FPType _totalDemand;
		
		FPType getMinTravelTime();
		FPType getTotalTravelTime();
		bool checkConvergence(FPType minTravelTime, FPType totalTravelTime);
		
};

#endif
