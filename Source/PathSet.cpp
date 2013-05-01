#include "PathSet.h"
#include "AONAssignment.h"

#include <cassert>

void PathSet::initialiseObject(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost){
	_mat = mat;
	_shPath = shPath;
	_conv = conv;
	_size = mat->getNbODPairs();
	_pathCost = pathCost;
	_nbLinks = net->getNbLinks();
	_linkFlows = new FPType[_nbLinks];
	_linkFlowsAux = new FPType[_nbLinks];
	for (int i = 0; i < _nbLinks; i++) {
		_linkFlows[i] = 0.0;
		_linkFlowsAux[i] = 0.0;
	}//*/
	_odSetList = new ODSet*[_size];
	
	_currPath = NULL;
	_currSetIndex = 0;
	
	_linkFncCont = linkFncCont;
	_net = net;
};

PathSet::PathSet(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost, Derivative *der, LineSearch *lineSearch, PathAlgoCreator *algoCreator) {
	initialiseObject(net, mat, linkFncCont, shPath, conv, pathCost);
	
	int odIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()) {
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			odIndex = dest->getODIndex();
			_odSetList[odIndex] = new ODSet(odIndex, dest->getIndex(), origin->getIndex(), _pathCost, linkFncCont, net, shPath, conv, der, _linkFlows, _linkFlowsAux, lineSearch, algoCreator);
		}
	}
	
};

PathSet::PathSet(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost, Derivative *der, LineSearch *lineSearch, FPType sparsityPrecision, PathAlgoCreator *algoCreator) {
	initialiseObject(net, mat, linkFncCont, shPath, conv, pathCost);
	
	int odIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()) {
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			odIndex = dest->getODIndex();
			_odSetList[odIndex] = new ODSet(odIndex, dest->getIndex(), origin->getIndex(), _pathCost, linkFncCont, net, shPath, conv, der, _linkFlows, _linkFlowsAux, lineSearch, sparsityPrecision, algoCreator);
		}
	}
	
};

PathSet::PathSet(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost, FPType zeroFlow, PathAlgoCreator *algoCreator){
	initialiseObject(net, mat, linkFncCont, shPath, conv, pathCost);
	
	int odIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()) {
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			odIndex = dest->getODIndex();
			_odSetList[odIndex] = new ODSet(odIndex, dest->getIndex(), origin->getIndex(), _pathCost, linkFncCont, net, shPath, conv, _linkFlows, _linkFlowsAux,  zeroFlow, algoCreator);
		}
	}
};

PathSet::PathSet(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost, FPType zeroFlow, FPType alpha, PathAlgoCreator *algoCreator){
	initialiseObject(net, mat, linkFncCont, shPath, conv, pathCost);
	
	int odIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()) {
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			odIndex = dest->getODIndex();
			_odSetList[odIndex] = new ODSet(odIndex, dest->getIndex(), origin->getIndex(), _pathCost, linkFncCont, net, shPath, conv, _linkFlows, _linkFlowsAux,  zeroFlow, alpha, dest->getDemand(), algoCreator);
		}
	}
};

PathSet::~PathSet(){
	for (int i = 0; i < _size; i++) {
		delete _odSetList[i];
	}
	delete[] _odSetList;
	delete[] _linkFlows;
	delete[] _linkFlowsAux;
};

//void PathSet::updateLinkCosts(){
//	_net->calculateLinkCosts();
//};

void PathSet::initialise(){
	//std::cout << "Updating link costs..." << std::endl;
	
	_net->calculateLinkCosts();
	//std::cout << "AFTER updating network. Flow is set to zero everywhere" << std::endl;
	AONAssignment aon(_mat, _shPath);
	//std::cout << "AON" << std::endl;
	aon.execute(this);

	// Boshen : hack the shpath function to setup astar heuristic
    //_shPath->calculate(-1, _mat->getNbOrigins());

	for (ODSet *odSet = beginSet(); odSet != NULL; odSet = getNextSet()){
		odSet->projectPathFlowOnLinks();
	}
	_net->calculateLinkCosts();
};

void PathSet::initialiseItself(StarLink* link, PairOD *dest){
	// check if a new path has to be created
	int odIndex = dest->getODIndex();
	if (link->getNodeToIndex() == (_odSetList[odIndex])->getDestIndex()) { // == dest->getIndex()
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

FPType PathSet::getMaxDiff(){
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
};

ODSet* PathSet::beginSet(){
	_currSetIndex = 0;
	if (_currSetIndex < _size) return _odSetList[_currSetIndex];
	return NULL;
};

ODSet* PathSet::getNextSet(){
	_currSetIndex++;
	if (_currSetIndex < _size) return _odSetList[_currSetIndex];
	return NULL;
};

bool PathSet::isConverged() const{
	bool tmp = _conv->isConverged();
	//std::cout << "rgap = " << _conv->getGap() << std::endl;
	return tmp;
};

void PathSet::print(){
	for (ODSet *odSet = beginSet(); odSet != NULL; odSet = getNextSet()) {
		odSet->print();
	}
};
