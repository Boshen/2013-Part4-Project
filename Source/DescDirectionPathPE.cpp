#include "DescDirectionPathPE.h"

#include <stdlib.h>
#include <iostream>
#include <cassert>

 DescDirectionPathPE::DescDirectionPathPE(FPType delta) : DescDirectionPath(delta){
 
 };
 
 DescDirectionPathPE::~DescDirectionPathPE(){
  
 };
  
 PathAndDirection** DescDirectionPathPE::createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated){
  	isEquilibrated = false;
  	size = 2;
  	PathAndDirection **returnSet = new PathAndDirection*[size];
  	for (int i = 0; i < size; i++) {
  		returnSet[i] = new PathAndDirection();
  	}
  	// find sh path and longest path
  	Path *minPath = findMinPath(paths);
  	FPType minDist = minPath->getCurrCost();
  	Path *maxPath = findMaxPath(paths, minPath);
  	FPType maxDist = maxPath->getCurrCost();
  	
  	assert((minPath != NULL) && (maxPath != NULL) && (minPath != maxPath));
  	// calculate direction
  	FPType dir = minDist - maxDist;
  	if (-dir <= _delta) {
  		isEquilibrated = true;
  		for (int i = 0; i < size; i++) {
			delete returnSet[i];
		}
		delete[] returnSet;
		size = 0;
		return NULL;
  	}
  	(returnSet[0])->setPath(maxPath);
  	(returnSet[0])->setDirection(dir);
  	(returnSet[1])->setPath(minPath);
  	(returnSet[1])->setDirection(-dir);
  	return returnSet;
 };
