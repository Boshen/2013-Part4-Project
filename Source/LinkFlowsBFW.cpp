#include "LinkFlowsBFW.h"

#include <stdlib.h>
#include <iostream>
#include <math.h>

/*void LinkFlowsBFW::allocateMemory(){
	_linkFlowsBFW = new FPType[_nbLinks];
	for (int i = 0; i < _nbLinks; i++) {
		_linkFlowsBFW[i] = 0.0;
	}
};*/

LinkFlowsBFW::LinkFlowsBFW(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, StepSize* stepSize, ConvMeasure *conv) : LinkFlowsCFW(net, mat, linkFncCont, shPath, stepSize, conv){
	_linkFlowsBFW = new FPType[_nbLinks];
	for (int i = 0; i < _nbLinks; i++) {
		_linkFlowsBFW[i] = 0.0;
	}
};

/*LinkFlowsBFW::LinkFlowsBFW(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv, FPType sparsityPrecision) : LinkFlowsCFW(net, mat, linkFncCont, shPath, der, lineSearch, conv){
	allocateMemory();
};*/

LinkFlowsBFW::~LinkFlowsBFW(){
	delete[] _linkFlowsBFW;
};
		
void LinkFlowsBFW::initialise(){
	updateLinkFlows();
	_minTravelTime = _aon->execute(this);
	for(int i = 0; i < _nbLinks; ++i) {
		_linkFlows[i] = _linkFlowsAux[i];
		_linkFlowsCFW[i] = 0.0;
		_linkFlowsBFW[i] = 0.0;
		_linkFlowsAux[i] = 0.0;
	}
	_tmp = 0;
};
		
void LinkFlowsBFW::calculateDirection(){
	
	calculateFWAux();
	
	FPType beta0 = 0.0;
	FPType beta1 = 0.0;
	FPType beta2 = 0.0;
	 
	if (_tmp > 1) {
		calcCoeff(beta0, beta1, beta2);
	}
	FPType alpha = 0.0;
	if (_tmp == 1) {
		alpha = calculateAlpha();
	}
	FPType promVal = 0.0;
	for (int i = 0; i < _nbLinks; ++i) {
		if (_tmp == 0) {
			_linkFlowsCFW[i] =  _linkFlowsAux[i];
			_linkFlowsBFW[i] = 0.0;
		} else if (_tmp == 1) {
			_linkFlowsBFW[i] = _linkFlowsCFW[i];
			_linkFlowsCFW[i] =  alpha * _linkFlowsCFW[i] + (1.0 - alpha) * _linkFlowsAux[i]; 
		} else {
			promVal = beta0 * _linkFlowsAux[i] + beta1 * _linkFlowsCFW[i] + beta2 * _linkFlowsBFW[i]; //
			_linkFlowsBFW[i] = _linkFlowsCFW[i];
			_linkFlowsCFW[i] = promVal;
		}
		_direction[i] = _linkFlowsCFW[i] - _linkFlows[i];
		
	}
	++_tmp;
	
};

void LinkFlowsBFW::calcCoeff(FPType &beta0, FPType &beta1, FPType &beta2){
	if ((fabs(1.0 - _stepPrev) <= _zeroTol) || (fabs(1.0 - _stepPrevPrev) <= _zeroTol) ) {
		beta0 = 1.0;
		beta1 = 0.0;
		beta2 = 0.0;
	} else {
		FPType nk = 0.0;
		FPType dk = 0.0;
		FPType nnk = 0.0;
		FPType ddk = 0.0;
		FPType der = 0.0;
		FPType dir_fw = 0.0;
		FPType dir_2 = 0.0;
		FPType dir_1 = 0.0;
		LinkFnc* link = NULL;
		for (int i = 0; i < _nbLinks; ++i) {
			link = _linkFncCont->getLinkFnc(i);
			der = link->evaluateDerivative(_linkFlows[i]);
			dir_fw = _linkFlowsAux[i] - _linkFlows[i];
			dir_2 = _stepPrev * _linkFlowsCFW[i] - _linkFlows[i] + (1 - _stepPrev) * _linkFlowsBFW[i];
			dir_1 = _linkFlowsCFW[i] - _linkFlows[i];
			nk += dir_2 * der * dir_fw;
			dk += dir_2 * der * (dir_2 - dir_1) / (1 - _stepPrev);
			nnk += dir_1 * der * dir_fw;
			ddk += dir_1 * dir_1 * der;
		}
		if ((fabs(dk) <= _zeroTol) || (fabs(ddk) <= _zeroTol) ) { //
			beta0 = 1.0;
			beta1 = 0.0;
			beta2 = 0.0;
		} else {
			FPType mu = -nk / dk;
			FPType eta = -nnk / ddk + (mu * _stepPrev) / (1.0 - _stepPrev);
			beta0 = 1.0 / (1.0 + mu + eta);
			if ((beta0 >= 0.0) && (beta0 <= 1.0 - _delta)) {
				beta1 = eta * beta0;
				beta2 = mu * beta0;
				
				if ((beta1 < 0.0) || (beta1 > 1.0 - _delta) || (beta2 < 0.0) || (beta2 > 1.0 - _delta)) {
					beta0 = 1.0;
					beta1 = 0.0;
					beta2 = 0.0;
				}
			} else {
				beta0 = 1.0;
				beta1 = 0.0;
				beta2 = 0.0;
			}
			
		}
	}
};

inline FPType LinkFlowsBFW::changeCoeff(FPType beta){
	if (beta > 1.0 - _delta) return 1.0 - _delta;
	if (beta < 0.0) return 0.0;
	return beta;
};		
