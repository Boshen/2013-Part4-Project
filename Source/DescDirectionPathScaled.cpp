#include "DescDirectionPathScaled.h"
//#include "PathDerivative.h"
#include "Utils.h"

#include <stdlib.h>
#include <iostream>

DescDirectionPathScaled::DescDirectionPathScaled(DescDirectionPath *pathDir, int nbLinks, FPType delta) : DescDirectionPath(delta), _pathDir(pathDir), _nbLinks(nbLinks){

};

DescDirectionPathScaled::~DescDirectionPathScaled(){
	delete _pathDir;
};

PathAndDirection** DescDirectionPathScaled::createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated){
	PathAndDirection** returnVal = _pathDir->createPathDirection(size, paths, isEquilibrated);
	if (isEquilibrated) {
		return NULL;
	}
	// do the magic...
	// It is assumed that positive value of direction is always the last one!!!
	FPType positiveDir = 0.0;
	FPType currDirection = 0.0;
	//PathDerivative der(_nbLinks);
	FPType currDer = 0.0;
	Path *minPath = (returnVal[size-1])->getPath();
	for (int i = 0; i < size-1; i++) {
		currDer = Utils::calculate((returnVal[i])->getPath(), minPath, _nbLinks);
		currDirection = (returnVal[i])->getDirectionValue() / currDer;
		(returnVal[i])->setDirection(currDirection);
		positiveDir -= currDirection;
	}
	if (size > 0) (returnVal[size-1])->setDirection(positiveDir);//*/
	return returnVal;
};
