#include "ODSetWithStep.h"
#include "Utils.h"

#include <vector>

PathBasedFlowMoveWithStep* ODSetWithStep::flowMoveStep_ = NULL;

ODSetWithStep::ODSetWithStep(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType zeroFlow, FPType *linkFlows, PathBasedFlowMoveWithStep* flowMove) : ODSet(index, destIndex, originIndex, pathCost, net, shPath, zeroFlow, linkFlows, flowMove), _projDir(NULL), _indexes(NULL), _size(0) {
	flowMoveStep_ = flowMove;
}; 

ODSetWithStep::~ODSetWithStep() {

}; 

FPType* ODSetWithStep::getProjectedDirection() {
	 return _projDir;
}; 

FPType ODSetWithStep::getUpperBound() {
	FPType ub = std::numeric_limits<FPType>::max();
	FPType dir = 0.0;
	FPType ubTmp = 0.0;
	for (PathAndDirection *pathDir = flowMoveStep_->beginPathDirection(); pathDir != NULL; pathDir = flowMoveStep_->getNextPathDirection()) {
		dir = pathDir->getDirectionValue();
		if (dir < 0.0) {
			//std::cout << "pathDir->getPath()->getFlow() = " << pathDir->getPath()->getFlow() << std::endl;
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
	_projDir = new FPType[_nbLinks];
	_indexes = new int[_nbLinks];
	for (int i = 0; i < _nbLinks; ++i) {
		_projDir[i] = 0.0;
		_indexes[i] = -1;
	}
	
	// project path-based direction on links
	Path *path = NULL;
	for (PathAndDirection *pathDir = flowMoveStep_->beginPathDirection(); pathDir != NULL; pathDir = flowMoveStep_->getNextPathDirection()) {
		path = pathDir->getPath();
		
		for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
			_projDir[link->getIndex()] += pathDir->getDirectionValue();
		}
	}
	
	/*_commonLinks.clear();
	Utils::getCommonLinks(_flowMove, _commonLinks, _nbLinks);
	for (std::list<StarLink*>::iterator it = _commonLinks.begin(); it != _commonLinks.end(); ++it) {
		_projDir[(*it)->getIndex()] = 0.0;
	}*/
	
	int count = 0;
	for (int i = 0; i < _nbLinks; ++i) {
		if (_projDir[i] != 0.0) {
			_indexes[count] = i;
			++count;
		}
	}
	_size = count;
	flowMoveStep_->setDescDirection(this);
}; 

void ODSetWithStep::deallocProjectedDirection(){
	delete[] _projDir;
	delete[] _indexes;
	_projDir = NULL;
	_indexes = NULL;
	_size = 0;
	flowMoveStep_->setDescDirection(NULL);
};
