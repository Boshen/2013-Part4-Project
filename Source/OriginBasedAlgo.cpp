#include "OriginBasedAlgo.h"
#include "Utils.h"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

//#define PRINT false

OriginBasedAlgo::OriginBasedAlgo(OriginSet *originSet, ODMatrix *mat, StarNetwork *net, AddHook *component) : EqAlgo(component), originSet_(originSet), mat_(mat), net_(net) {

};

OriginBasedAlgo::~OriginBasedAlgo(){

};
		
int OriginBasedAlgo::execute(){
	//initialisation
	std::cout << "Initialisation" << std::endl;
	originSet_->initialise();
	
	//std::cout << "Initialisation done" << std::endl;
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
		//if (nbIter == 1) {
			//originSet_->loadOriginFlows(); // now it is in initialise()
			//std::cout << "origin flows after AON " << std::endl;
			//originSet_->print();
			//originSet_->printNet();
		//}
		//std::cout << "nbIter = " << nbIter << std::endl;
		//if (nbIter == 2) break;
		
		// decomposition by origins
		//int count = 0;
		//std::cout << "*****************************************ITER = " << nbIter << std::endl;
		for (OriginBush *bush = originSet_->beginSet(); bush != NULL; bush = originSet_->getNextSet()){
			//std::cout << "Origin = " << bush->getOriginIndex() << std::endl;
			bush->updateSet();
			//std::cout << "Improving set " << std::endl;
			bool wasImproved = bush->improve();
			
			//while (true) { // for EQII
				mainLoop(bush, wasImproved, nbIter);
				//	if (!wasImproved) break; // for EQII
				//}; // for EQII
			//count++;
			//if (count == 1) break;
			//std::cout << "MAX = " << Utils::checkFeasibility(net_, mat_) << std::endl;//*/
		}
		
		doSmthAfterOrigins(nbIter); // hook method - does nothing by default
		
		end = clock();
		timePassed += ((FPType)(end-start))/ (CLOCKS_PER_SEC);
		doSmthAfterLoop(timePassed, originSet_->getGapVal());
		//std::cout << timePassed << " " << originSet_->getGapVal() << std::endl; //" MAX = " << Utils::checkFeasibility(net_, mat_) << std::endl; //printf ("%4.5f %4.5f \n", timePassed, originSet_->getGapVal()); 
		
		//break;
	}
	std::cout << "FINISH!!!! nbIter = " << nbIter << std::endl;
	return nbIter;
};

void OriginBasedAlgo::mainLoop(OriginBush *bush, bool wasImproved, int nbIter){
	
	//std::cout << "Equilibration" << std::endl;
	bush->equilibrate(wasImproved, nbIter); //bool canMoveFlow = 
	
	//std::cout << "Removing unused links" << std::endl;
	bush->removeUnusedLinks();
	
	//return true;
	
	// for equilibration II
	/*if (!canMoveFlow) return false;
	bush->updateSet();
	return bush->improve();//*/
	
};
