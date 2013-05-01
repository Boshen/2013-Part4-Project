#include "OriginBasedAlgo.h"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

#define PRINT false

OriginBasedAlgo::OriginBasedAlgo(OriginSet *originSet) : originSet_(originSet) {

};

OriginBasedAlgo::~OriginBasedAlgo(){

};
		
int OriginBasedAlgo::execute(){
	//initialisation
	std::cout << "Initialisation" << std::endl;
	originSet_->initialise();
	
	//main loop
	int nbIter = 0; 
	clock_t start, end;
	double timePassed = 0.0;
	while (true) {
		start = clock();
		nbIter++;
		
		// global convergence check
		if (originSet_->isConverged()){
			break;
		}
		if (nbIter == 1) {
			originSet_->loadOriginFlows();
		}
		//std::cout << "nbIter = " << nbIter << std::endl;
		//if (nbIter == 3) return -1;
		
		// decomposition by origins
		int count = 0;
		for (OriginBush *bush = originSet_->beginSet(); bush != NULL; bush = originSet_->getNextSet()){
			//std::cout << "Origin = " << bush->getOriginIndex() << std::endl;
			bush->updateSet();
	
			//std::cout << "Improving set " << std::endl;
			bool wasImproved = bush->improve();
			
			//while (true) { // for EQII
				wasImproved = mainLoop(bush, wasImproved);
			//	if (!wasImproved) break; // for EQII
			//}; // for EQII
			count++;
		}
		OriginBush::updateLinkCosts();
		end = clock();
		timePassed += ((FPType)(end-start))/ (CLOCKS_PER_SEC);
		printf ("%4.5f \n", timePassed); 
		
	}
	std::cout << "FINISH!!!! nbIter = " << nbIter << std::endl;
	return nbIter;
};

bool OriginBasedAlgo::mainLoop(OriginBush *bush, bool wasImproved){
	
	//bool canMoveFlow = bush->equilibrate(wasImproved);
	bush->equilibrate(wasImproved);
	
	bush->removeUnusedLinks();
	
	return true;
	
	// for equilibration II
	/*if (!canMoveFlow) return false;
	bush->updateSet();
	return bush->improve();//*/
	
};
