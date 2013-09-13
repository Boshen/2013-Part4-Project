#include "PathBasedAlgo.h"
#include "EquilibrationI.h"
#include "EquilibrationII.h"
#include "Timer.h"
//#include "Utils.h"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

PathBasedAlgo::PathBasedAlgo(PathSet *pathSet, bool useEqI, AddHook *component, ConvMeasure *conv) : EqAlgo(component), _pathSet(pathSet), _conv(conv) { //, net_(net), mat_(mat){ , StarNetwork *net, ODMatrix *mat
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
	_pathSet->initialise();
	
	std::cout << "Initialisation finished" << std::endl;
	
	// main loop
	int nbIter = 0; 
	//clock_t start, end;
	double timePassed = 0.0;
	Timer timer;
	//Timer timerTotal;
	//timerTotal.start();
	//bool stopLoop = false;
	while (true) {
		//start = clock();
		timer.start();
		nbIter++;
		
		// global convergence check
		if (_conv->isConverged()){
			break;
		}
		//if (nbIter == 3) break; 
		// decomposition by O-D pairs
		//std::cout << "--------------------------------ITER = " << nbIter << std::endl;
		//int count = 0;
		for (ODSet *odSet = _pathSet->beginSet(); odSet != NULL; odSet = _pathSet->getNextSet()){
			
			//odSet->updateSet(); //**
			//bool wasImproved = odSet->improveSet();//**
			//if (wasImproved || (odSet->getNbPaths() > 1)) {//**
				//std::cout << "index = " << odSet->getIndex() << " nbPaths = " << odSet->getNbPaths() << std::endl;
				_eq->executeMainLoop(odSet);
				//if (odSet->getNbPaths() > 1) std::cout << "***********************************************nbPaths = " << odSet->getNbPaths() << std::endl;
				/*timerTotal.stopAnyway();
				if (timerTotal.getTimePassed() > 18000) {
					stopLoop = true;
					break;
				}*/
				//break;
			//}//**
			//++count;
			//if (count == 8) break;
		}
		//end = clock();
		//if (stopLoop) _pathSet->isConverged();
		timer.stop();
		timePassed += timer.getTimePassed(); //((FPType)(end-start))/ (CLOCKS_PER_SEC);
		//printf ("%4.5f \n", timePassed); 
		//std::cout << timePassed << " " << _pathSet->getGap() << std::endl;
		//std::cout << "nbPaths = " << _pathSet->getNbPath() << std::endl;
		doSmthAfterLoop(timePassed, _conv->getGap());
		//std::cout << "MAX = " << Utils::checkFeasibility(net_, mat_) << std::endl;
		if (timePassed > 18000) break; // || stopLoop) break;
		
	}
	doSmthAfterLoop(timePassed, _conv->getGap());
	std::cout << "FINISH!!!! nbIter = " << nbIter << " " << _conv->getGap() << std::endl;
	
	return nbIter;
};

bool PathBasedAlgo::mainLoop(ODSet *odSet){
	// update path set 
	//std::cout << "index = " << odSet->getIndex() << " nbPaths = " << odSet->getNbPaths() << std::endl;
	odSet->updateSet();//**
	
	// try to improve path set (2) 
	bool wasImproved = odSet->improveSet();//**
	//if (wasImproved) std::cout << "********Path added: " << odSet->getIndex() << " nbPaths = " << odSet->getNbPaths() << std::endl;
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
