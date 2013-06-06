#include "FWAlgo.h"

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <ctime>

FWAlgo::FWAlgo(LinkFlows *linkFlows, AddHook *component) : EqAlgo(component), _linkFlows(linkFlows){

};

FWAlgo::~FWAlgo(){

};

/** This method executes F-W algorithm as described in Sheffi's book pages 119-120.
 */	
int FWAlgo::execute(){
	// initialisation
	_linkFlows->initialise();
	std::cout << "Initialisation finished" << std::endl;
	int nbIter = 0;
	// main loop
	clock_t start, end;
	double timePassed = 0.0;
	while (true) { 
		
		start = clock();
		nbIter++;
		
		// convergence check
		if (_linkFlows->isConverged()) break;
		
		// Update
		_linkFlows->updateLinkFlows();
		
		// Direction finding 
		_linkFlows->equilibrate(); //line search and flow shift
		
		end = clock();
		timePassed += ((FPType)(end-start))/ (CLOCKS_PER_SEC);
		if ((nbIter % 20) == 0) {
			//printf ("%4.10f %4.10f \n", timePassed, _linkFlows->getGapValue());
			doSmthAfterLoop(timePassed, _linkFlows->getGapValue());
		}
		
	};
	//printf ("%4.10f %4.10f \n", timePassed, _linkFlows->getGapValue());
	std::cout << "FINISH!!!! nbIter = " << nbIter << " gap = " << _linkFlows->getGapValue() << std::endl;
	return nbIter;
};

