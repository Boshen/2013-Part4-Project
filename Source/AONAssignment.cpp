#include "AONAssignment.h"

#include <stdlib.h>
#include <iostream>
#include <limits>

AONAssignment::AONAssignment(ODMatrix *mat, ShortestPath *shPath) : _mat(mat), _shPath(shPath){

};

AONAssignment::~AONAssignment(){

};

FPType AONAssignment::execute(InitialiseSolution *solution){
	FPType minTravelTime = 0.0;
	int originIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()){
		originIndex = origin->getIndex();
		_shPath->calculate(originIndex);
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()){
			solution->initialiseSolution(dest, _shPath, originIndex);
			minTravelTime += dest->getDemand() * _shPath->getCost(dest->getIndex()); 
		}
	}
	
	return minTravelTime;
};

void AONAssignment::executeForOriginBasedAlgo(InitialiseSolution *solution, StarNetwork *net){
	FPType dist = 0.0;
	//PairOD fakeDest(-1, -1, 0.0);
	//fakeDest.setIndex(-1);
	//fakeDest.setODIndex(-1);
	int nbNodes = net->getNbNodes();
	int nodes[nbNodes];
	for (int i = 0; i < nbNodes; i++){
		nodes[i] = -1;
	}
	int originIndex = -1;
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()){
		//std::cout << "origin = " << origin->getIndex() << std::endl;
		originIndex = origin->getIndex();
		_shPath->calculate(originIndex);
		for (int i = 0; i < nbNodes; i++){
			nodes[i] = -1;
		}
		nodes[originIndex] = 1; 
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()){
			//dest->print();
			solution->initialiseSolution(dest, _shPath, originIndex);
			nodes[dest->getIndex()] = 1; 
		}
		// iterate other nodes that are not destinations
		//std::cout << "fake node" << std::endl;
		for (int i = 0; i < nbNodes; i++){
			if (nodes[i] == -1){
				
				dist = _shPath->getCost(i);
				if (dist != std::numeric_limits<FPType>::max()) { // otherwise it is another origin node
					PairOD fakeDest(i, 0.0);
					//fakeDest.setOriginIndex(origin->getIndex());
					//fakeDest.setIndex(i);
					solution->initialiseSolution(&fakeDest, _shPath, originIndex);
					nodes[i] = 1;
				}
			}
		}
	}
};
