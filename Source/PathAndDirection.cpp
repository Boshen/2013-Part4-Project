#include "PathAndDirection.h"

#include <stdlib.h>

PathAndDirection::PathAndDirection(){
	_path = NULL;
	_directionVal = 0.0;
};

PathAndDirection::~PathAndDirection(){

};

Path* PathAndDirection::getPath() const{
	return _path;
};

FPType PathAndDirection::getDirectionValue() const{
	return _directionVal;
};
		
void PathAndDirection::setPath(Path *path){
	_path = path;
};

void PathAndDirection::setDirection(FPType direction){
	_directionVal = direction;
};
