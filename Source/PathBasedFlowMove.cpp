#include "PathBasedFlowMove.h"

#include <stdlib.h>
#include <iostream>
#include <cassert>

PathBasedFlowMove::PathBasedFlowMove(DescDirectionPath* pathDirectionAlgo){
	_size = 0;
	_pathDirection = NULL;
	_pathDirectionAlgo =  pathDirectionAlgo;
	_currDirection = 0;
};

bool PathBasedFlowMove::calculatePathDirection(const std::list<Path*> &paths){
	bool isEquilibrated = false;
	_pathDirection = _pathDirectionAlgo->calculatePathDirection(_size, paths, isEquilibrated);
	return isEquilibrated;
};

PathAndDirection* PathBasedFlowMove::beginPathDirection(){
	_currDirection = 0;
	if (_size == 0) return NULL;
	return _pathDirection[0];
};

PathAndDirection* PathBasedFlowMove::getNextPathDirection(){
	_currDirection++;
	if (_currDirection >= _size) return NULL; 
	return  _pathDirection[_currDirection];
};
