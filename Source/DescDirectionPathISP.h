#ifndef _DESC_DIRECTION_PATH_ISP_
#define _DESC_DIRECTION_PATH_ISP_

#include "DescDirectionPath.h"
#include "OnePathDerivative.h"

class DescDirectionPathISP : public DescDirectionPath {
	public:
		DescDirectionPathISP(FPType slope, FPType scaleFact, FPType delta);
		~DescDirectionPathISP();
		
		PathAndDirection** createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated);
		
	private:
		FPType _slope;
		FPType _scaleFact;
		OnePathDerivative _pathDir;
		
		FPType calculateThreshold(FPType minDist, FPType maxDist) const;
};

#endif
