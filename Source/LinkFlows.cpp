#include "LinkFlows.h"
#include "StepSizeAdd.h"
//#include "StepSizeSparsity.h"

#include <stdlib.h>
#include <iostream>

void LinkFlows::initialiseObject(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv){
	_mat = mat;
	_net = net;
	_linkFncCont = linkFncCont;
	_aon = new AONAssignment(mat, shPath);
	_nbLinks = net->getNbLinks();
	_conv = conv;
	
	_linkFlows = new FPType[_nbLinks];
	_linkFlowsAux = new FPType[_nbLinks];
	_indexes = new int[_nbLinks];
	for (int i = 0; i < _nbLinks; i++) {
		_linkFlows[i] = 0.0;
		_linkFlowsAux[i] = 0.0;
		_indexes[i] = i;
	}
	
	_minTravelTime = 0.0; 
	_stepPrev = 0.0;
	_stepPrevPrev = 0.0;
};

LinkFlows::LinkFlows(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv) {
	initialiseObject(net, mat, linkFncCont, shPath, der, lineSearch, conv);	
	_stepSize = new StepSizeAdd(this, lineSearch, der);
};

/*LinkFlows::LinkFlows(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv, FPType sparsityPrecision){
	initialiseObject(net, mat, linkFncCont, shPath, der, lineSearch, conv);	
	_stepSize = new StepSizeSparsity(new StepSizeAdd(this, _nbLinks, sparsityPrecision, lineSearch, der));	
};*/

LinkFlows::~LinkFlows(){
	delete[] _linkFlows;
	delete[] _linkFlowsAux;
	delete _aon;
	delete _stepSize;
	delete[] _indexes;
};

FPType LinkFlows::getGapValue() const{
	return _conv->getGap();
};

FPType LinkFlows::getMinTravelTime() const{
	return _minTravelTime;
};

void LinkFlows::initialise(){
	updateLinkFlows();
	_minTravelTime = _aon->execute(this);
	for(int i = 0; i < _nbLinks; i++) {
		_linkFlows[i] = _linkFlowsAux[i];
		_linkFlowsAux[i] = 0.0;
	}
};

void LinkFlows::updateLinkFlows(){
	//int linkIndex = -1;
	FPType flow = 0.0;
	for (StarLink *link = _net->beginOnlyLink(); link != NULL; link = _net->getNextOnlyLink()) {
		flow = _linkFlows[link->getIndex()]; 
		link->setFlow(flow);
		link->updateTime();
	}
};

FPType* LinkFlows::getProjectedDirection(){
	return _linkFlowsAux;
};

FPType LinkFlows::getUpperBound(){
	return 1.0;
};

FPType* LinkFlows::getLinkFlows(){
	return _linkFlows;
};

const FPType LinkFlows::getDiraction(int index) const{
	return _linkFlowsAux[index];
};

int LinkFlows::getSize(){
	return _nbLinks;
};

int* LinkFlows::getIndexes(){
	return _indexes;
};

void LinkFlows::calculateFWAux(){
	for(int i = 0; i < _nbLinks; i++) {
		_linkFlowsAux[i] = 0.0;
	}
	_minTravelTime = _aon->execute(this);
};

void LinkFlows::calculateDirection(){
	calculateFWAux();
	for(int i = 0; i < _nbLinks; i++) {
		_linkFlowsAux[i] = _linkFlowsAux[i] - _linkFlows[i];	
	}
};
		
void LinkFlows::equilibrate(){
	
	calculateDirection();
	
	_stepPrevPrev = _stepPrev;
	_stepPrev = _stepSize->getStepSize();
	
	//bool ins = false;
	for(int i = 0; i < _nbLinks; i++) {
		_linkFlows[i] += _stepPrev *  getDiraction(i);
		if (_linkFlows[i] < 0.0) {
			//std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << _linkFlows[i] << " ";
			//ins = true;
			_linkFlows[i] = 0.0;
		}
	}
	//if (ins) std::cout << std::endl;
};

bool LinkFlows::isConverged(){
	return _conv->isConverged(_minTravelTime); // 
};

void LinkFlows::initialiseItself(StarLink* link, PairOD *dest){
	_linkFlowsAux[link->getIndex()] += dest->getDemand();
};
