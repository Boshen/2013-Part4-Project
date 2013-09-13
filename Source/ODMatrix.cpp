#include "ODMatrix.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <sstream>

ODMatrix::ODMatrix(int nbNodes) : _nbNodes(nbNodes), _nbODPairs(0), _odMatrix(), _demandByIndex() {
	assert(nbNodes > 0);
	
	//_odMatrix = new Origin*[nbNodes];
	_curOrigin = _odMatrix.begin(); //-1;
	//_size = 0;
	//_nbODPairs = 0;
	//_demandByIndex = new std::vector<FPType>*[nbNodes]; /*new FPType*[_nbNodes];
	/*for (int i = 0; i < _nbNodes; ++i) {
		//_odMatrix[i] = NULL;
		_demandByIndex[i] = new FPType[_nbNodes];
		for(int j = 0; j < _nbNodes; ++j){
			_demandByIndex[i][j] = 0.0;
		}
	}//*/
};

ODMatrix::~ODMatrix(){
	//for (int i = 0; i < _size; ++i) {
	//	delete _odMatrix[i];
	//}
	
	//for (int i = 0; i < _nbNodes; ++i) {
	//	delete _demandByIndex[i];
	//}
	//delete[] _odMatrix;
	//delete[] _demandByIndex;
	
	for (std::list<Origin*>::iterator it = _odMatrix.begin(); it != _odMatrix.end(); ++it){
		delete *it;
	}
};

int ODMatrix::getNbOrigins() const{
	return _odMatrix.size(); //_size;
};

void ODMatrix::addOrigin(Origin *origin){
	assert(getNbOrigins() < _nbNodes);
	//_odMatrix[_size] = origin;
	//++_size;
	_odMatrix.push_back(origin);
};

Origin* ODMatrix::beginOrigin(){
	_curOrigin = _odMatrix.begin();
	if (_curOrigin == _odMatrix.end()) return NULL;
	return *_curOrigin;
};

Origin* ODMatrix::getNextOrigin(){
	++_curOrigin;
	if (_curOrigin == _odMatrix.end()) return NULL;
	return *_curOrigin; //_odMatrix[_curOrigin];
};

void ODMatrix::print(){
	std::cout << "nb pairs = " << _nbODPairs << std::endl;
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
	//
	for (Origin *origin = beginOrigin(); origin != NULL; origin = getNextOrigin()){
		originIndex = origin->getIndex(); //net->getNodeIndex(origin->getID());
		//origin->setIndex(originIndex);
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			//dest->setIndex(net->getNodeIndex(dest->getID()));
			dest->setODIndex(count);
			//dest->setOriginIndex(originIndex);
			//(_demandByIndex[originIndex])->at(dest->getIndex()) = dest->getDemand();
			std::stringstream key;
			key << originIndex << "_" << dest->getIndex();
			_demandByIndex.insert(std::make_pair<std::string, FPType>(key.str(), dest->getDemand()));
			++count;
		}
	}
	_nbODPairs = count;
	std::cout << "nbODPairs = " << _nbODPairs << std::endl;	
};

FPType ODMatrix::getDemandByIndex(int originIndex, int destIndex) const{
	std::stringstream key;
	key << originIndex << "_" << destIndex;
	std::tr1::unordered_map<std::string, FPType>::const_iterator got = _demandByIndex.find(key.str());
	if (got == _demandByIndex.end()) return 0.0;
	return got->second; //(_demandByIndex[originIndex])->at(destIndex);
};

int ODMatrix::getNbODPairs() const{
	return _nbODPairs;
};

