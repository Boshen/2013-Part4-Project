#include "PathAlgoCreator.h"
#include "Error.h"
#include "DescDirectionPathScaled.h"
#include "DescDirectionPathPE.h"
#include "DescDirectionPathGP.h"
#include "DescDirectionPathPG.h"
#include "DescDirectionPathISP.h"

#include <cassert>

PathAlgoCreator::PathAlgoCreator(){
	/*assert(delta > 0.0);
	assert(slope > 0.0);
	assert(scaleFact > 0.0);
	_algo = algo;
	_app = app;
	_nbLinks = nbLinks;
	_delta = delta;
	_slope = slope;
	_scaleFact = scaleFact;*/
};

PathAlgoCreator::~PathAlgoCreator(){

};

DescDirectionPath* PathAlgoCreator::allocateDescDirectionPath(PathAlgoType algo, PathApp app, int nbLinks, FPType delta, FPType slope, FPType scaleFact){
	assert(delta > 0.0);
	assert(slope > 0.0);
	assert(scaleFact > 0.0);
	if (app == APP3) {
		if (algo == PE) {
			return new DescDirectionPathScaled(new DescDirectionPathPE(delta), nbLinks, delta);
		} else if (algo == GP){
			return new DescDirectionPathScaled(new DescDirectionPathGP(delta), nbLinks, delta);
		} else {
			throw Error("Approach 3 is not defined for this algorithm type");
		}
	} else if (app == APP2){
		if (algo == GP) {
			return new DescDirectionPathScaled(new DescDirectionPathGP(delta), nbLinks, delta);
		} else if (algo == PE) {
			return new DescDirectionPathScaled(new DescDirectionPathPE(delta), nbLinks, delta);
		} else {
			throw Error("Approach 2 is not defined for this algorithm type");
		}
	} else if (app == APP1) {
		if (algo == PE) {
			return new DescDirectionPathPE(delta);
		} else if (algo == GP) {
			return new DescDirectionPathGP(delta);
		} else if (algo == PG) {
			//std::cout << "Creating descDirectionPG" << std::endl;
			return new DescDirectionPathPG(delta);
			//std::cout << "descDir created" << std::endl;
		} else if (algo == ISP) {
			return new DescDirectionPathISP(slope, scaleFact, delta);
		} else {
			throw Error("Path-based algorithm is not defined");
		}
	}
	return NULL;
};
