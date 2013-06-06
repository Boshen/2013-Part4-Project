#include "ODSetWithStep.h"
#include "StepSizeAdd.h"
#include "PathBasedFlowMoveWithStep.h"
#include "Utils.h"

#include <vector>

ODSetWithStep::ODSetWithStep(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, Derivative *der, FPType *linkFlows, LineSearch *lineSearch, PathAlgoCreator *algoCreator) : ODSet(index, destIndex, originIndex, pathCost, net, shPath, conv, der->getZeroFlow(), linkFlows, algoCreator), _size(0) {
	_stepSize = new StepSizeAdd(this, lineSearch, der); 
	_flowMove = new PathBasedFlowMoveWithStep(_stepSize, algoCreator->allocateDescDirectionPath()); // is deallocated in ODSet
	_projDir = new FPType[_nbLinks];
	_indexes = new int[_nbLinks];
	for (int i = 0; i < _nbLinks; ++i) {	
		_projDir[i] = 0.0;
		_indexes[i] = -1;
	}
}; 

ODSetWithStep::~ODSetWithStep() {
	delete _stepSize;
	delete[] _projDir;
	delete[] _indexes;
}; 

FPType* ODSetWithStep::getProjectedDirection() {
	 return _projDir;
}; 

FPType ODSetWithStep::getUpperBound() {
	FPType ub = std::numeric_limits<FPType>::max();
	FPType dir = 0.0;
	FPType ubTmp = 0.0;
	for (PathAndDirection *pathDir = _flowMove->beginPathDirection(); pathDir != NULL; pathDir = _flowMove->getNextPathDirection()) {
		dir = pathDir->getDirectionValue();
		if (dir < 0.0) {
			ubTmp = -(pathDir->getPath()->getFlow()) / dir;
			if (ubTmp < ub) {
				ub = ubTmp;
			}	
		}
	}
	return ub;
}; 

FPType* ODSetWithStep::getLinkFlows() {
	 return _linkFlows;
}; 

int ODSetWithStep::getSize(){
	return _size;
};

int* ODSetWithStep::getIndexes(){
	return _indexes;
};

void ODSetWithStep::calculateProjectedDirection() {
	// assign zero
	for (int i = 0; i < _nbLinks; ++i) {
		_projDir[i] = 0.0;
		_indexes[i] = -1;
	}
	
	// project path-based direction on links
	Path *path = NULL;
	for (PathAndDirection *pathDir = _flowMove->beginPathDirection(); pathDir != NULL; pathDir = _flowMove->getNextPathDirection()) {
		path = pathDir->getPath();
		
		for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
			_projDir[link->getIndex()] += pathDir->getDirectionValue();
		}
	}
	
	_commonLinks.clear();
	Utils::getCommonLinks(_flowMove, _commonLinks, _nbLinks);
	for (std::list<StarLink*>::iterator it = _commonLinks.begin(); it != _commonLinks.end(); ++it) {
		_projDir[(*it)->getIndex()] = 0.0;
	}
	
	int count = 0;
	for (int i = 0; i < _nbLinks; ++i) {
		if (_projDir[i] != 0.0) {
			_indexes[count] = i;
			++count;
		}
	}
	_size = count;
}; 

