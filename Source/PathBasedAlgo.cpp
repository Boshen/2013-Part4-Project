#include "PathBasedAlgo.h"
#include "EquilibrationI.h"
#include "EquilibrationII.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

PathBasedAlgo::PathBasedAlgo(PathSet *pathSet, bool useEqI, AddHook *component) : EqAlgo(component), _pathSet(pathSet){ //: EquilibrationType(this), _pathSet(pathSet){
	if (useEqI) {
		_eq = new EquilibrationI(this);
	} else {
		_eq = new EquilibrationII(this);
	}
};

PathBasedAlgo::~PathBasedAlgo(){
	delete _eq;
};

void PathBasedAlgo::print(){
	std::cout << "I am PathBasedAlgo" << std::endl;
};

int PathBasedAlgo::execute(){
	// initialise
//	std::cout << "Initialisation started" << std::endl;
	_pathSet->initialise();
	
//	std::cout << "Initialisation finished" << std::endl;
	
	// main loop
	int nbIter = 0; 
	clock_t start, end;
	double timePassed = 0.0;
	while (true) {
		start = clock();
		nbIter++;
		
		// global convergence check
		if (_pathSet->isConverged()){
			break;
		}
		//if (nbIter == 2) break; 
		// decomposition by O-D pairs
		//std::cout << "--------------------------------ITER = " << nbIter << std::endl;
		//int count = 0;
		for (ODSet *odSet = _pathSet->beginSet(); odSet != NULL; odSet = _pathSet->getNextSet()){
			
			//odSet->updateSet(); //**
			//bool wasImproved = odSet->improveSet();//**
			//if (wasImproved || (odSet->getNbPaths() > 1)) {//**
				_eq->executeMainLoop(odSet);
				//break;
			//}//**
			//++count;
			//if (count == 8) break;
		}
		end = clock();
		timePassed += ((FPType)(end-start))/ (CLOCKS_PER_SEC);
		//printf ("%4.5f \n", timePassed); 
		//std::cout << timePassed << " " << _pathSet->getGap() << std::endl;
		doSmthAfterLoop(timePassed, _pathSet->getGap());
		
	}
	//std::cout << "FINISH!!!! nbIter = " << nbIter << " " << _pathSet->getGap() << std::endl;
	
	return nbIter;
};

bool PathBasedAlgo::mainLoop(ODSet *odSet){
	// update path set 
    // go through every path and recalculate its cost. Link flows are NOT updated
	odSet->updateSet();//**
	
	// try to improve path set (2) 
	// calculate shortest path and check if it is shorter than current shortest path
    // adds path to paths in odSet if there exist a shorter path
	bool wasImproved = odSet->improveSet();//**
	// if (2) was successful or solution is not equilibrated yet, equilibrate: flow move + deleting paths with zero flow
	if (wasImproved || (odSet->getNbPaths() > 1)) {//**
		//std::cout << "equilibrating" << std::endl;
		if (odSet->equilibrate()) {
			//std::cout << "was equilibrated. removing unused paths" << std::endl;
			odSet->removeUnusedPaths();
			return true;
		}
		//std::cout << "projecting flows on links" << std::endl;
		odSet->projectPathFlowOnLinks();
		//std::cout << "updating link costs" << std::endl;
		odSet->updateLinkCostsOfOD();
		//std::cout << "removing unused paths" << std::endl;
		odSet->removeUnusedPaths();
		//std::cout << "updating set" << std::endl;
		//odSet->updateSet();//**
		//if (odSet->getNbPaths() <= 1) return true;//**
	} else { //**
		return true;//**
	}//**
	return false;
	
};
