#include "ODSet.h"
#include "DescDirectionPathPE.h"
#include "DescDirectionPathGP.h"
#include "DescDirectionPathPG.h"
#include "StepSizeAdd.h"
#include "StepSizeSparsity.h"
#include "PathBasedFlowMoveWithStep.h"
#include "Error.h"
#include "Utils.h"
#include "PathBasedFlowMovePE.h"
#include "PathBasedFlowMoveGP.h"

#include <stdlib.h>
#include <iostream>
#include <limits>
#include <math.h>

void ODSet::initialiseObject(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType zeroFlow, FPType *linkFlows, FPType *linkFlowsAux, PathAlgoCreator *algoCreator){
	_net = net;
	_linkFncCont = linkFncCont;
	_shPath = shPath;
	_conv = conv;
	_index = index;
	_destIndex = destIndex;
	_originIndex = originIndex;
	_pathCost = pathCost;
	_zeroFlow = zeroFlow;
	_it = _allPaths.begin();
	_minDist = std::numeric_limits<FPType>::max( );
	
	_size = 0; // number of paths
	_linkFlows = linkFlows; // is allocated and deallocated in pathSet
	_linkFlowsAux = linkFlowsAux; // is allocated and deallocated in pathSet
	_nbLinks = _net->getNbLinks();
	_maxDist = 0.0; // temporary
	_pathDirAlgo = algoCreator->allocateDescDirectionPath();
	
};

ODSet::ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, Derivative *der, FPType *linkFlows, FPType *linkFlowsAux, LineSearch *lineSearch, PathAlgoCreator *algoCreator) {
	initialiseObject(index, destIndex, originIndex, pathCost, linkFncCont, net, shPath, conv, der->getZeroFlow(), linkFlows, linkFlowsAux, algoCreator);
	_stepSize = new StepSizeAdd(this, _nbLinks, 0.0, lineSearch, der); 
	_flowMove = new PathBasedFlowMoveWithStep(_stepSize, _pathDirAlgo);
	
};

ODSet::ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, Derivative *der, FPType *linkFlows, FPType *linkFlowsAux, LineSearch *lineSearch, FPType sparsityPrecision, PathAlgoCreator *algoCreator) {
	initialiseObject(index, destIndex, originIndex, pathCost, linkFncCont, net, shPath, conv, der->getZeroFlow(), linkFlows, linkFlowsAux, algoCreator);
	_stepSize = new StepSizeSparsity(new StepSizeAdd(this, _nbLinks, sparsityPrecision, lineSearch, der));
	_flowMove = new PathBasedFlowMoveWithStep(_stepSize, _pathDirAlgo);
	
};

ODSet::ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType *linkFlows, FPType *linkFlowsAux, FPType zeroFlow, PathAlgoCreator *algoCreator) {
	initialiseObject(index, destIndex, originIndex, pathCost, linkFncCont, net, shPath, conv, zeroFlow, linkFlows, linkFlowsAux, algoCreator);
	_stepSize = NULL;
	_flowMove = new PathBasedFlowMovePE(_pathDirAlgo);
};

ODSet::ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType *linkFlows, FPType *linkFlowsAux, FPType zeroFlow, FPType alpha, FPType demand, PathAlgoCreator *algoCreator) {
	initialiseObject(index, destIndex, originIndex, pathCost, linkFncCont, net, shPath, conv, zeroFlow, linkFlows, linkFlowsAux, algoCreator);
	_stepSize = NULL;
	_flowMove = new PathBasedFlowMoveGP(alpha, demand, _pathDirAlgo);
};

ODSet::~ODSet(){
	for (std::list<Path*>::iterator it = _allPaths.begin(); it != _allPaths.end(); it++) {
		delete *it;
	}
	delete _stepSize;
	delete _flowMove;
	delete _pathDirAlgo;
};

int ODSet::getIndex() const{
	return _index;
};

int ODSet::getDestIndex() const{
	return _destIndex;
};

int ODSet::getOriginIndex() const{
	return _originIndex;
};

void ODSet::addPath(Path *path){
	_allPaths.push_back(path);
	if (path->getCurrCost() < _minDist) _minDist = path->getCurrCost();
	_size++;
};
		
// iterate through paths
Path* ODSet::beginPath(){
	_it = _allPaths.begin();
	if (_it != _allPaths.end()) return *_it;
	return NULL; 
};

Path* ODSet::getNextPath(){
	_it++;
	if (_it != _allPaths.end()) return *_it;
	return NULL; 
};

void ODSet::print(){
	std::cout << "OD pair# " << getIndex() << " origin = " << getOriginIndex() << " dest = " << getDestIndex() << std::endl;
	for (Path* path = beginPath(); path != NULL; path = getNextPath()) {
		path->print();
	}
};

// go through every path and recalculate its cost. Link flows are NOT updated
void ODSet::updateSet(){
	
	FPType dist = 0.0;
	_minDist = std::numeric_limits<FPType>::max( );
	_maxDist = 0.0;
	for (Path *path = beginPath(); path != NULL; path = getNextPath()) {
		dist = _pathCost->calculate(path);
		path->setCurrCost(dist);
		if (dist < _minDist) _minDist = dist;
		if (dist > _maxDist) _maxDist = dist;
	}
};

bool ODSet::improveSet(){
	// calculate shortest path and check if it is shorter than current shortest path
	_shPath->calculate(_originIndex, _destIndex);
	FPType minDist = _shPath->getCost(_destIndex);
	if (minDist < _minDist) {
		Path *path = new Path();
		path->setCurrCost(minDist);
		StarLink *link = _shPath->getInComeLink(_destIndex);
		int nextDest = link->getNodeFromIndex();
		while (link != NULL) {
			path->addLinkToPath(link);
			nextDest = link->getNodeFromIndex();
			link = _shPath->getInComeLink(nextDest);
		}
		addPath(path);
		return true;
	}
	return false;
};

bool ODSet::equilibrate(){
	//save current flow to prev flow
	FPType totalFlow = 0.0;
	for (Path *path = beginPath(); path != NULL; path = getNextPath()) {
		path->setPrevFlow(path->getFlow());
		totalFlow += path->getFlow();
	}
	
	//FPType diff = _maxDist - _minDist;
	bool isEquilibrated = false;
	isEquilibrated = _flowMove->calculatePathDirection(_allPaths);
	if (isEquilibrated) {
		return true;
	}
	
	calculateProjectedDirection();

	isEquilibrated = _flowMove->executeFlowMove(); // calculation of new flow
	if (isEquilibrated) {
		return true;
	}
	return false;
};

void ODSet::calculateProjectedDirection(){
	// assign zero
	for (int i = 0; i < _nbLinks; i++) {
		_linkFlowsAux[i] = 0.0;
	}
	// project path-based direction on links
	Path *path = NULL;
	for (PathAndDirection *pathDir = _flowMove->beginPathDirection(); pathDir != NULL; pathDir = _flowMove->getNextPathDirection()) {
		path = pathDir->getPath();
		
		for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
			_linkFlowsAux[link->getIndex()] += pathDir->getDirectionValue();
		}
	}
	
	_commonLinks.clear();
	Utils::getCommonLinks(_flowMove, _commonLinks, _nbLinks);
	for (std::list<StarLink*>::iterator it = _commonLinks.begin(); it != _commonLinks.end(); it++) {
		_linkFlowsAux[(*it)->getIndex()] = 0.0;
	}
};

FPType ODSet::getFirstDirVal(){
	//FPType val = 0.0;
	updateSet();
	return _maxDist - _minDist;
};

FPType* ODSet::getProjectedDirection(){
	return _linkFlowsAux;
};

FPType ODSet::getUpperBound(){
	FPType ub = std::numeric_limits<FPType>::max();
	FPType dir = 0.0;
	FPType flow = 0.0;
	FPType ubTmp = 0.0;
	for (PathAndDirection *pathDir = _flowMove->beginPathDirection(); pathDir != NULL; pathDir = _flowMove->getNextPathDirection()) {
		dir = pathDir->getDirectionValue();
		if (dir < 0.0) {
			flow = (pathDir->getPath())->getFlow();
			ubTmp = -flow / dir;
			if (ubTmp < ub) {
				ub = ubTmp;
			}	
		}
	}
	return ub;
};

FPType* ODSet::getLinkFlows(){
	return _linkFlows;
};

int ODSet::getNbPaths() const{
	return _size;
};
		
void ODSet::removeUnusedPaths(){
	for (std::list<Path*>::iterator it = _allPaths.begin(); it != _allPaths.end(); it++) {
		if (fabs((*it)->getFlow()) <= _zeroFlow) {
			delete *it;
			it = _allPaths.erase(it);
			_size--;
		}
	}
};

void ODSet::updateLinkCostsOfOD(){
	for (Path *path = beginPath(); path != NULL; path = getNextPath()) {
		for (StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()) {
			link->updateTime();
		}
	}
};

void ODSet::projectPathFlowOnLinks(){
	FPType flow = 0.0;
	FPType prevFlow[_commonLinks.size()];
	int index = -1;
	int tmp = 0;
	
	// saving previous link flow of common links
	for (std::list<StarLink*>::iterator it = _commonLinks.begin(); it != _commonLinks.end(); it++) {
		index = (*it)->getIndex();
		prevFlow[tmp] = _linkFlows[index];
		tmp++;
	}
	
	for (Path *path = beginPath(); path != NULL; path = getNextPath()) {
		for (StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()) {
			flow = link->getFlow() - path->getPrevFlow();
			if (flow <= _zeroFlow) flow = 0.0;
			link->setFlow(flow);
			index = link->getIndex();
			_linkFlows[index] = flow;
		}
	}
	// add flow to links that will change 
	for (Path *path = beginPath(); path != NULL; path = getNextPath()) {
		for (StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()) {
			flow = path->getFlow();
			if (flow <= _zeroFlow) flow = 0.0;
			link->addFlow(flow);
			_linkFlows[link->getIndex()] += flow;
		}
	}
	// assign prev flow to common links
	tmp = 0;
	for (std::list<StarLink*>::iterator it = _commonLinks.begin(); it != _commonLinks.end(); it++) {
		index = (*it)->getIndex();
		flow = prevFlow[tmp];
		tmp++;
		_linkFlows[index] = flow;
		(*it)->setFlow(flow);
	}//*/
};

