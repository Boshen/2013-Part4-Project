#ifndef ORIGIN_SET_TAPAS
#define ORIGIN_SET_TAPAS

#include "OriginSet.h"

class OriginSetTapas : public OriginSet {
	public:
		OriginSetTapas(ODMatrix *mat, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType zeroFlow, FPType dirTol, PASManager *pasManager);
		~OriginSetTapas();
		
		bool isConverged();
	private:
		PASManager *pasManager_;
};

#endif
