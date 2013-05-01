#include "PathAlgoCreator.h"
#include "Error.h"
#include "DescDirectionPathScaled.h"
#include "DescDirectionPathPE.h"
#include "DescDirectionPathGP.h"
#include "DescDirectionPathPG.h"
#include "DescDirectionPathISP.h"

#include <cassert>

PathAlgoCreator::PathAlgoCreator(PathAlgoType algo, PathApp app, int nbLinks, FPType delta, FPType slope, FPType scaleFact){
	assert(delta > 0.0);
	assert(slope > 0.0);
	assert(scaleFact > 0.0);
	_algo = algo;
	_app = app;
	_nbLinks = nbLinks;
	_delta = delta;
	_slope = slope;
	_scaleFact = scaleFact;
};

PathAlgoCreator::~PathAlgoCreator(){

};

DescDirectionPath* PathAlgoCreator::allocateDescDirectionPath(){
	if (_app == APP3) {
		if (_algo == PE) {
			return new DescDirectionPathScaled(new DescDirectionPathPE(_delta), _nbLinks, _delta);
		} else if (_algo == GP){
			return new DescDirectionPathScaled(new DescDirectionPathGP(_delta), _nbLinks, _delta);
		} else {
			throw Error("Approach 3 is not defined for this algorithm type");
		}
	} else if (_app == APP2){
		if (_algo == GP) {
			return new DescDirectionPathScaled(new DescDirectionPathGP(_delta), _nbLinks, _delta);
		} else if (_algo == PE) {
			return new DescDirectionPathScaled(new DescDirectionPathPE(_delta), _nbLinks, _delta);
		} else {
			throw Error("Approach 2 is not defined for this algorithm type");
		}
	} else if (_app == APP1) {
		if (_algo == PE) {
			return new DescDirectionPathPE(_delta);
		} else if (_algo == GP) {
			return new DescDirectionPathGP(_delta);
		} else if (_algo == PG) {
			return new DescDirectionPathPG(_delta);
		} else if (_algo == ISP) {
			return new DescDirectionPathISP(_slope, _scaleFact, _delta);
		} else {
			throw Error("Path-based algorithm is not defined");
		}
	}
	return NULL;
};
