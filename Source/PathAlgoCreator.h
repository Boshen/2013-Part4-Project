#ifndef _PATH_ALGO_CREATOR_
#define _PATH_ALGO_CREATOR_

#include "DescDirectionPath.h"
#include "Constants.h"

class PathAlgoCreator {
	public:
		PathAlgoCreator(PathAlgoType algo, PathApp app, int nbLinks, FPType delta, FPType slope, FPType scaleFact);
		~PathAlgoCreator();
		
		DescDirectionPath* allocateDescDirectionPath();
		
	private:
		PathAlgoType _algo;
		PathApp _app;
		int _nbLinks;
		FPType _delta;
		FPType _slope;
		FPType _scaleFact;
		
};

#endif