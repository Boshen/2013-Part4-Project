#include "ODMatrix.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>

ODMatrix::ODMatrix(int nbNodes){
	assert(nbNodes > 0);
	_nbNodes = nbNodes;
	_odMatrix = new Origin*[nbNodes];
	_curOrigin = -1;
	_size = 0;
	_nbODPairs = 0;
	_demandByIndex = new FPType*[_nbNodes];
	for (int i = 0; i < _nbNodes; i++) {
		_odMatrix[i] = NULL;
		_demandByIndex[i] = new FPType[_nbNodes];
		for(int j = 0; j < _nbNodes; j++){
			_demandByIndex[i][j] = 0.0;
		}
	}
};

ODMatrix::~ODMatrix(){
	for (int i = 0; i < _size; i++) {
		delete _odMatrix[i];
	}
	for (int i = 0; i < _nbNodes; i++) {
		delete[] _demandByIndex[i];
	}
	delete[] _odMatrix;
	delete[] _demandByIndex;
};

int ODMatrix::getNbOrigins() const{
	return _size;
};

void ODMatrix::addOrigin(Origin *origin){
	assert(_size < _nbNodes);
	_odMatrix[_size] = origin;
	_size++;
};

Origin* ODMatrix::beginOrigin(){
	_curOrigin = 0;
	return _odMatrix[0];
};

Origin* ODMatrix::getNextOrigin(){
	_curOrigin++;
	if (_curOrigin == _size) return NULL;
	return _odMatrix[_curOrigin];
};

void ODMatrix::print(){
	//std::cout << "nb pairs = " << _nbODPairs << std::endl;
	/*for (Origin *origin = beginOrigin(); origin != NULL; origin = getNextOrigin()){
		std::cout << "Origin: " << origin->getID() << std::endl;
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			dest->print();
		}
	};*/
};

// IMPORTANT : this method must be called ONCE after object creation!!!!
void ODMatrix::setIndexes(StarNetwork *net){
	int count = 0;
	int originIndex = -1;
	
	for (Origin *origin = beginOrigin(); origin != NULL; origin = getNextOrigin()){
		originIndex = net->getNodeIndex(origin->getID());
		origin->setIndex(originIndex);
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			dest->setIndex(net->getNodeIndex(dest->getID()));
			dest->setODIndex(count);
			dest->setOriginIndex(originIndex);
			_demandByIndex[originIndex][dest->getIndex()] = dest->getDemand();
			count++;
		}
	}
	_nbODPairs = count;
	//std::cout << "nbODPairs = " << _nbODPairs << std::endl;	
};

FPType ODMatrix::getDemandByIndex(int originIndex, int destIndex) const{
	return _demandByIndex[originIndex][destIndex];
};

int ODMatrix::getNbODPairs() const{
	return _nbODPairs;
};
