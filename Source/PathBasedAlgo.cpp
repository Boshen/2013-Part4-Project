#include "PathBasedAlgo.h"
#include "EquilibrationI.h"
#include "EquilibrationII.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

PathBasedAlgo::PathBasedAlgo(PathSet *pathSet, bool useEqI) : _pathSet(pathSet){ //: EquilibrationType(this), _pathSet(pathSet){
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
	std::cout << "Initialisation started" << std::endl;
    clock_t start, end;
    double timePassed = 0.0;
    start = clock();
    _pathSet->initialise();
    end = clock();
    timePassed += ((double)(end-start))/ (CLOCKS_PER_SEC);
    std::cout << "Init Time: " << timePassed << " s." << std::endl;

    std::cout << "Initialisation finished" << std::endl;

    // main loop
    int nbIter = 0; 
    while (true) {
        nbIter++;

        // global convergence check
        if (_pathSet->isConverged()){
            break;
        }
        /*if (nbIter == 1) {
          for (ODSet *odSet = _pathSet->beginSet(); odSet != NULL; odSet = _pathSet->getNextSet()){
          odSet->projectPathFlowOnLinks();
          }
          _pathSet->updateLinkCosts();
          };*/

        // decomposition by O-D pairs
        //std::cout << "--------------------------------ITER = " << nbIter << std::endl;
        for (ODSet *odSet = _pathSet->beginSet(); odSet != NULL; odSet = _pathSet->getNextSet()){
            //std::cout << "od = " << odSet->getIndex() << std::endl;

            //odSet->updateSet();
            //if (odSet->getOriginIndex() == 70) odSet->print();	
            // try to improve path set (2) 
            //bool wasImproved = odSet->improveSet();
            //if (wasImproved || (odSet->getNbPaths() > 1)) {
            //std::cout << "wasImproved = " << wasImproved << " nbPaths = " << odSet->getNbPaths() << std::endl;
            _eq->executeMainLoop(odSet);
            //}
        }

    }
    //std::cout << "nbIter = " << nbIter << std::endl;

    return nbIter;
};

bool PathBasedAlgo::mainLoop(ODSet *odSet){
    // update path set 
    odSet->updateSet();

    // try to improve path set (2) 
    bool wasImproved = odSet->improveSet();
    // if (2) was successful or solution is not equilibrated yet, equilibrate: flow move + deleting paths with zero flow
    if (wasImproved || (odSet->getNbPaths() > 1)) {
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
        //odSet->updateSet();
        //odSet->print();
        //if (odSet->getNbPaths() <= 1) return true;
    } else { 
        return true;
    }
    return false;

};
