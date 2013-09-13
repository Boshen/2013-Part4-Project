#ifndef _DESC_DIRECTION_PATH_ISP_
#define _DESC_DIRECTION_PATH_ISP_

#include "DescDirectionPath.h"

class DescDirectionPathISP : public DescDirectionPath {
	public:
		DescDirectionPathISP(FPType slope, FPType scaleFact, FPType delta);
		~DescDirectionPathISP();
		
		PathAndDirection** createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated);
		
	private:
		const FPType _slope;
		const FPType _scaleFact;
		
		FPType calculateThreshold(FPType minDist, FPType maxDist) const;
		FPType calculateDerivative(Path* path) const;
};

#endif
