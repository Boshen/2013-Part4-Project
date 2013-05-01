#ifndef _DESC_DIRECTION_PATH_
#define _DESC_DIRECTION_PATH_

#include "PathAndDirection.h"

#include <stdlib.h>
#include <iostream>
#include <list>
#include <limits>
#include <cassert>

class DescDirectionPath {
	friend class DescDirectionPathScaled;
	public:
		virtual ~DescDirectionPath(){
			for (int i = 0; i < _size; i++) {
				delete _pathDirection[i];
			}
			delete[] _pathDirection;
		};
		PathAndDirection** calculatePathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated){
			for (int i = 0; i < _size; i++) {
				delete _pathDirection[i];
			}
			delete[] _pathDirection;
			_pathDirection = NULL;
			_pathDirection = createPathDirection(_size, paths, isEquilibrated);
			size = _size;
			return _pathDirection;
		};
		
	protected:
		
		FPType _delta;
		DescDirectionPath(FPType delta) :  _delta(delta), _pathDirection(NULL), _size(0) {};
		
		Path* findMinPath(const std::list<Path*> &paths) const{
			FPType minDist = std::numeric_limits<FPType>::max( );
		  	Path *minPath = NULL;
		  	FPType cost = 0.0;
		  	for (std::list<Path*>::const_iterator it = paths.begin(); it != paths.end(); it++) {
		  		cost = (*it)->getCurrCost();
		  		if (cost < minDist) {
		  			minDist = cost;
		  			minPath = *it;
		  		}
		  	}
		  	assert(minPath != NULL);
		  	return minPath;
		};
		
		Path* findMaxPath(const std::list<Path*> &paths, Path *minPath) const{
			//std::cout << "Inside findMaxPath *********************" << std::endl;
			Path *maxPath = NULL;
		  	FPType maxDist = 0.0;
		  	FPType cost = 0.0;
		  	
		  	for (std::list<Path*>::const_iterator it = paths.begin(); it != paths.end(); it++) {
		  		
		  		if (*it != minPath) {
		  			cost = (*it)->getCurrCost();
		  			//(*it)->print();
		  			//std::cout << "cost = " << cost << std::endl;
		  			if (cost > maxDist) {
			  			maxDist = cost;
			  			maxPath = *it;
			  			//std::cout << "maxPath = " << maxPath << std::endl;
			  			//maxPath->print();
		  			}
		  		}
		  	}
		  	//std::cout << "maxPath = " << maxPath << std::endl;
		  	//if (maxPath == NULL) std::cout << "WTF" << std::endl;
		  	assert(maxPath != NULL);
		  	return maxPath;
		};
		
		virtual PathAndDirection** createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated) = 0;
		
	private:
		PathAndDirection** _pathDirection;
		int _size;
};

#endif
