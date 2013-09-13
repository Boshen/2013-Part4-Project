#include "PathSet.h"
#include "AONAssignment.h"
#include "ODSetWithStep.h"
#include "ODSetGPApp3.h"

#include <cassert>

void PathSet::initialiseObject(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost){
	_mat = mat;
	_shPath = shPath;
	//_conv = conv;
	_size = mat->getNbODPairs();
	_pathCost = pathCost;
	_nbLinks = net->getNbLinks();
	_linkFlows = new FPType[_nbLinks];
	//_linkFlowsAux = new FPType[_nbLinks];
	for (int i = 0; i < _nbLinks; i++) {
		_linkFlows[i] = 0.0;
		//_linkFlowsAux[i] = 0.0;
	}//*/
	//std::cout << "allocated size = " << _size << std::endl;
	_odSetList = new ODSet*[_size];
	
	_currPath = NULL;
	_currSetIndex = 0;
	
	_net = net;
};

PathSet::PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost, FPType zeroFlow, PathBasedFlowMove* flowMove) {
	initialiseObject(net, mat, shPath, pathCost);
	
	int odIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()) {
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			odIndex = dest->getODIndex();
			_odSetList[odIndex] = new ODSet(odIndex, dest->getIndex(), origin->getIndex(), _pathCost, net, shPath, zeroFlow, _linkFlows, flowMove);
		}
	}
	
};

PathSet::PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost, FPType zeroFlow, PathBasedFlowMoveWithStep* flowMove) {
	initialiseObject(net, mat, shPath, pathCost);
	
	int odIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()) {
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			odIndex = dest->getODIndex();
			_odSetList[odIndex] = new ODSetWithStep(odIndex, dest->getIndex(), origin->getIndex(), _pathCost, net, shPath, zeroFlow, _linkFlows, flowMove);
		}
	}
	
};

PathSet::PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost, FPType zeroFlow, PathBasedFlowMoveGP* flowMove) {
	initialiseObject(net, mat, shPath, pathCost);
	
	int odIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()) {
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			odIndex = dest->getODIndex();
			_odSetList[odIndex] = new ODSetGPApp3(odIndex, dest->getIndex(), origin->getIndex(), _pathCost, net, shPath, zeroFlow, _linkFlows, flowMove, mat);
		}
	}
	
};



/*PathSet::PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost, FPType zeroFlow, FPType alpha, DescDirectionPath* descDirPath){
	initialiseObject(net, mat, shPath, pathCost);
	
	int odIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()) {
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			odIndex = dest->getODIndex();
			_odSetList[odIndex] = new ODSet(odIndex, dest->getIndex(), origin->getIndex(), _pathCost, net, shPath, _linkFlows, zeroFlow, alpha, dest->getDemand(), descDirPath);
		}
	}
};*/

PathSet::~PathSet(){
	for (int i = 0; i < _size; i++) {
		delete _odSetList[i];
	}
	delete[] _odSetList;
	delete[] _linkFlows;
	//delete[] _linkFlowsAux;
};

//void PathSet::updateLinkCosts(){
//	_net->calculateLinkCosts();
//};

long int PathSet::getNbPath(){
	long int nbPaths = 0;
	for (ODSet *set = beginSet(); set != NULL; set = getNextSet()) {
		nbPaths += set->getNbPaths();
	}
	return nbPaths;
};

void PathSet::initialise(){
	//std::cout << "Updating link costs..." << std::endl;
	
	_net->calculateLinkCosts();
	//std::cout << "AFTER updating network. Flow is set to zero everywhere" << std::endl;
	AONAssignment aon(_mat, _shPath);
	std::cout << "AON" << std::endl;
	aon.execute(this);
	
	for (ODSet *odSet = beginSet(); odSet != NULL; odSet = getNextSet()){
		odSet->projectPathFlowOnLinks();
	}
	_net->calculateLinkCosts();
};

void PathSet::initialiseItself(StarLink* link, PairOD *dest, int originIndex){
	// check if a new path has to be created
	int odIndex = dest->getODIndex();
	
	if (link->getNodeToIndex() == (_odSetList[odIndex])->getDestIndex()) { // == dest->getIndex()
		//std::cout << "Adding path to odIndex = " << odIndex << std::endl;
		_currPath = new Path();
		_currPath->setFlow(dest->getDemand());
		(_odSetList[odIndex])->addPath(_currPath);
	}
	// add link to existing path
	_currPath->addLinkToPath(link);
	
};

void PathSet::printNet(){
	_net->print();
};

/*FPType PathSet::getMaxDiff(){
	FPType max = 0.0;
	FPType tmp = 0.0;
	int nbSets = 0;
	int index = -1;
	for (ODSet *odSet = beginSet(); odSet != NULL; odSet = getNextSet()){
		tmp = odSet->getFirstDirVal();
		nbSets++;
		if (tmp > max) {
			max = tmp;
			index = odSet->getIndex();
		}
	}
	std::cout << " index = " << index << " maxDiff = " << max << std::endl;
	return max;
};*/

ODSet* PathSet::beginSet(){
	_currSetIndex = 0;
	//std::cout << "first path set _size = " << _size  << " _odSetList[_currSetIndex] = " << _odSetList[_currSetIndex] << std::endl; 
	if (_currSetIndex < _size) return _odSetList[_currSetIndex];
	return NULL;
};

ODSet* PathSet::getNextSet(){
	++_currSetIndex;
	//std::cout << "_currSetIndex = " << _currSetIndex << " size = " << _size << " _odSetList[_currSetIndex] = " << _odSetList[_currSetIndex] << std::endl;
	if (_currSetIndex < _size) return _odSetList[_currSetIndex];
	return NULL;
};

/*bool PathSet::isConverged() const{
	//bool tmp = _conv->isConverged();
	//std::cout << "rgap = " << _conv->getGap() << std::endl;
	return _conv->isConverged();
};*/

/*FPType PathSet::getGap() const{
	return _conv->getGap();
};*/

void PathSet::print(){
	for (ODSet *odSet = beginSet(); odSet != NULL; odSet = getNextSet()) {
		odSet->print();
	}
};
