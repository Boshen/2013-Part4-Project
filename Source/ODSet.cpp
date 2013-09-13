#include "ODSet.h"
#include "DescDirectionPathPE.h"
#include "DescDirectionPathGP.h"
#include "DescDirectionPathPG.h"

#include "Error.h"
#include "Utils.h"
#include "PathBasedFlowMovePE.h"
#include "PathBasedFlowMoveGP.h"

#include <stdlib.h>
#include <iostream>
#include <limits>
#include <math.h>

StarNetwork *ODSet::_net = NULL;
ShortestPath *ODSet::_shPath = NULL;
FPType ODSet::_zeroFlow = 0.0;
PathCost *ODSet::_pathCost = NULL;
PathBasedFlowMove *ODSet::_flowMove = NULL;
		
/*void ODSet::initialiseObject(PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType zeroFlow, FPType *linkFlows) { 
	_net = net;
	_shPath = shPath;
	
	_pathCost = pathCost;
	_zeroFlow = zeroFlow;
	_it = _allPaths.begin();
	_minDist = std::numeric_limits<FPType>::max( );
	
	_size = 0; // number of paths
	//_linkFlows = linkFlows; // is allocated and deallocated in pathSet
	
};*/

ODSet::ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType zeroFlow, FPType *linkFlows, PathBasedFlowMove* flowMove) : _linkFlows(linkFlows), _nbLinks(net->getNbLinks()), _destIndex(destIndex), _originIndex(originIndex), _index(index), _size(0) {
	//initialiseObject(pathCost, net, shPath, zeroFlow, linkFlows);
	_net = net;
	_shPath = shPath;
	
	_pathCost = pathCost;
	_zeroFlow = zeroFlow;
	
	_it = _allPaths.begin();
	_minDist = std::numeric_limits<FPType>::max( );
	
	_flowMove = flowMove;
	
};

/*ODSet::ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType *linkFlows, FPType zeroFlow, DescDirectionPath* descDirPath) : _linkFlows(linkFlows), _nbLinks(net->getNbLinks()), _index(index), _destIndex(destIndex), _originIndex(originIndex) {
	initialiseObject(pathCost, net, shPath, zeroFlow, linkFlows);
	_flowMove = new PathBasedFlowMovePE(descDirPath);
};

ODSet::ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType *linkFlows,  FPType zeroFlow, FPType alpha, FPType demand, DescDirectionPath* descDirPath) : _linkFlows(linkFlows), _nbLinks(net->getNbLinks()), _index(index), _destIndex(destIndex), _originIndex(originIndex){
	initialiseObject(pathCost, net, shPath, zeroFlow, linkFlows);
	_flowMove = new PathBasedFlowMoveGP(alpha, demand, descDirPath);
};*/

ODSet::~ODSet(){
	for (std::list<Path*>::iterator it = _allPaths.begin(); it != _allPaths.end(); ++it) {
		delete *it;
	}
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
Path* ODSet::beginPath() const{
	_it = _allPaths.begin();
	if (_it != _allPaths.end()) return *_it;
	return NULL; 
};

Path* ODSet::getNextPath() const{
	_it++;
	if (_it != _allPaths.end()) return *_it;
	return NULL; 
};

void ODSet::print() const{
	std::cout << "OD pair# " << getIndex() << " origin = " << getOriginIndex() << " dest = " << getDestIndex() << std::endl;
	for (Path* path = beginPath(); path != NULL; path = getNextPath()) {
		path->print();
	}
};

// go through every path and recalculate its cost. Link flows are NOT updated
void ODSet::updateSet(){
	
	FPType dist = 0.0;
	_minDist = std::numeric_limits<FPType>::max( );
	//_maxDist = 0.0;
	for (Path *path = beginPath(); path != NULL; path = getNextPath()) {
		dist = _pathCost->calculate(path);
		path->setCurrCost(dist);
		if (dist < _minDist) _minDist = dist;
		//if (dist > _maxDist) _maxDist = dist;
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
	for (Path *path = beginPath(); path != NULL; path = getNextPath()) {
		path->setPrevFlow(path->getFlow());
	}
	
	//FPType diff = _maxDist - _minDist;
	bool isEquilibrated = false;
	isEquilibrated = _flowMove->calculatePathDirection(_allPaths);
	if (isEquilibrated) {
		return true;
	}
	
	calculateProjectedDirection();

	isEquilibrated = _flowMove->executeFlowMove(); 
	deallocProjectedDirection();
	if (isEquilibrated) {
		return true;
	}
	return false;
};

/*FPType ODSet::getFirstDirVal(){
	//FPType val = 0.0;
	updateSet();
	return _maxDist - _minDist;
};*/

int ODSet::getNbPaths() const{
	return _size;
};
		
void ODSet::removeUnusedPaths(){
	for (std::list<Path*>::iterator it = _allPaths.begin(); it != _allPaths.end(); ++it) {
		if (fabs((*it)->getFlow()) <= _zeroFlow) {
			delete *it;
			it = _allPaths.erase(it);
			--it;
			--_size;
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
	for (Path *path = beginPath(); path != NULL; path = getNextPath()) {
		for (StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()) {
			flow = link->getFlow() - path->getPrevFlow();
			if (flow <= _zeroFlow) flow = 0.0;
			link->setFlow(flow);
			_linkFlows[link->getIndex()] = flow;
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
};

