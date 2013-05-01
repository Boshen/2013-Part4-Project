#include "LinkFlowsCFW.h"

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <limits>

void LinkFlowsCFW::allocateMemory(){
	_linkFlowsCFW = new FPType[_nbLinks];
	_direction = new FPType[_nbLinks];
	for (int i = 0; i < _nbLinks; i++) {
		_linkFlowsCFW[i] = 0.0;
		_direction[i] = 0.0;
	}
	_nbCalls = 0;
};

LinkFlowsCFW::LinkFlowsCFW(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv) : LinkFlows(net, mat, linkFncCont, shPath, der, lineSearch, conv){
	allocateMemory();
};

LinkFlowsCFW::LinkFlowsCFW(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv, FPType sparsityPrecision) : LinkFlows(net, mat, linkFncCont, shPath, der, lineSearch, conv, sparsityPrecision){
	allocateMemory();
};

LinkFlowsCFW::~LinkFlowsCFW(){
	delete[] _linkFlowsCFW;
	delete[] _direction;
};

void LinkFlowsCFW::initialise(){
	updateLinkFlows();
	_minTravelTime = _aon->execute(this);
	for(int i = 0; i < _nbLinks; i++) {
		_linkFlows[i] = _linkFlowsAux[i];
		_linkFlowsCFW[i] = _linkFlowsAux[i];
		_linkFlowsAux[i] = 0.0;
	}
};

FPType* LinkFlowsCFW::getProjectedDirection(){
	return _direction;
};
		
const FPType LinkFlowsCFW::getDiraction(int index) const{
	return _direction[index];
};

void LinkFlowsCFW::calculateDirection(){
	
	// direction calculation
	calculateFWAux();
	
	FPType alpha = 0.0;
	if (_nbCalls > 0) {
		alpha = calculateAlpha();
	}
	for (int i = 0; i < _nbLinks; i++) {
		if (_nbCalls == 0) {
			_linkFlowsCFW[i] = _linkFlowsAux[i];
			_direction[i] = _linkFlowsCFW[i] - _linkFlows[i];
		} else {
			_linkFlowsCFW[i] = alpha * _linkFlowsCFW[i] + (1.0 - alpha) * _linkFlowsAux[i];
			_direction[i] = _linkFlowsCFW[i] - _linkFlows[i];
		}
		
		
	}
	_nbCalls++;
};

FPType LinkFlowsCFW::calculateAlpha(){
	FPType nk = 0.0;
	FPType tmp = 0.0;
	FPType dk_tmp = 0.0;
	LinkFnc* link = NULL;
	FPType tmp2 = 0.0;
	for (int i = 0; i < _nbLinks; i++) {
		link = _linkFncCont->getLinkFnc(i);
		tmp2 = _linkFlowsAux[i] - _linkFlows[i];
		tmp =  tmp2 * link->evaluateDerivative(_linkFlows[i]);
		nk +=  (_linkFlowsCFW[i] - _linkFlows[i]) * tmp;
		dk_tmp += tmp2 * tmp;
	}
	dk_tmp = nk - dk_tmp;
	FPType val = nk / dk_tmp;
	if (fabs(dk_tmp) <= _zeroTol) return 0.0;
	if (val > 1.0 - _delta) return 1.0 - _delta;
	if (val >= 0.0) return val; 
	return 0.0;//*/
	
};

