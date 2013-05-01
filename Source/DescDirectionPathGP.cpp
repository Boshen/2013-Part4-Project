#include "DescDirectionPathGP.h"

#include <cassert>

DescDirectionPathGP::DescDirectionPathGP(FPType delta) : DescDirectionPath(delta) {

};

DescDirectionPathGP::~DescDirectionPathGP(){

};

PathAndDirection** DescDirectionPathGP::createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated){
	isEquilibrated = false;
	size = paths.size();
	PathAndDirection **returnSet = new PathAndDirection*[size];
  	for (int i = 0; i < size; i++) {
  		returnSet[i] = new PathAndDirection();
  	}
  	
  	// find min dist first
  	Path *minPath = findMinPath(paths);
  	FPType minDist = minPath->getCurrCost();
  	
  	int i = 0;
  	FPType minDir = 0.0;
  	FPType dir = 0.0;
  	FPType maxDir = 0.0;
  	for (std::list<Path*>::const_iterator it = paths.begin(); it != paths.end(); it++) {
  		if (*it != minPath) {
  			(returnSet[i])->setPath(*it);
  			dir = minDist - (*it)->getCurrCost();
  			assert(dir <= 0.0);
  			if (-dir > maxDir) maxDir = -dir;
  			(returnSet[i])->setDirection(dir);
  			minDir -= dir;
  			i++;
  		}
  	}
  	if (maxDir <= _delta){
  		isEquilibrated = true;
  		for (int i = 0; i < size; i++) {
	  		delete returnSet[i];
	  	}
	  	delete[] returnSet;
  		size = 0;
  		return NULL;
  	}
  	(returnSet[i])->setPath(minPath);
  	(returnSet[i])->setDirection(minDir);
  	return returnSet;
};
