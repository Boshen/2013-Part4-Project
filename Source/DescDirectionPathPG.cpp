#include "DescDirectionPathPG.h"

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <limits>

DescDirectionPathPG::DescDirectionPathPG(FPType delta) : DescDirectionPath(delta){

};

DescDirectionPathPG::~DescDirectionPathPG(){

};

PathAndDirection** DescDirectionPathPG::createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated){	
	isEquilibrated = false;
	size = paths.size();
	PathAndDirection **returnSet = new PathAndDirection*[size];
  	for (int i = 0; i < size; i++) {
  		returnSet[i] = new PathAndDirection();
  	}
  	
  	// find average dist first
  	FPType avDist = 0.0;
  	FPType minDist = std::numeric_limits<FPType>::max( );
  	FPType cost = 0.0;
  	FPType maxDist = 0.0;
  	for (std::list<Path*>::const_iterator it = paths.begin(); it != paths.end(); it++) {
  		cost = (*it)->getCurrCost();
  		avDist += cost;
  		if (cost < minDist) minDist = cost;
  		if (cost > maxDist) maxDist = cost;
  	}
  	avDist /= (FPType)size;
  	
  	if (maxDist - minDist <= _delta) {
  		isEquilibrated = true;
  		for (int i = 0; i < size; i++) {
			delete returnSet[i];
		}
		delete[] returnSet;
  		size = 0;
  		return NULL;
  	}//*/
  	int i = 0;
  	FPType flow = 0.0;
  	for (std::list<Path*>::const_iterator it = paths.begin(); it != paths.end(); it++) {
  		(returnSet[i])->setPath(*it);
  		flow = avDist - (*it)->getCurrCost();
  		(returnSet[i])->setDirection(flow);
  		i++;
  	}
  	return returnSet;
};
