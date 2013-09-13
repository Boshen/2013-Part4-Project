#include "OriginBasedAlgo.h"
#include "Utils.h"
#include "Timer.h"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

//#define PRINT false

OriginBasedAlgo::OriginBasedAlgo(OriginSet *originSet, ODMatrix *mat, StarNetwork *net, AddHook *component) : EqAlgo(component), originSet_(originSet), mat_(mat), net_(net) {

};

OriginBasedAlgo::~OriginBasedAlgo(){

};
		
int OriginBasedAlgo::execute(){
	//initialisation
	std::cout << "Initialisation" << std::endl;
	originSet_->initialise();
	
	std::cout << "Initialisation done" << std::endl;
	
	//main loop
	int nbIter = 0; 
	Timer timer;
	double timePassed = 0.0;
	while (true) {
		timer.start();
		nbIter++;
		
		// global convergence check
		if (originSet_->isConverged()){
			break;
		}
		//std::cout << "nbIter = " << nbIter << std::endl;
		//if (nbIter == 2) break;
		
		// decomposition by origins
		int count = 0;
		//std::cout << "*****************************************ITER = " << nbIter << std::endl;
		for (OriginBush *bush = originSet_->beginSet(); bush != NULL; bush = originSet_->getNextSet()){
			//std::cout << "---------------------------------------------Origin = " << bush->getOriginIndex() << std::endl;
			//bush->print();
			bush->updateSet();
			//std::cout << "Improving set " << std::endl;
			bool wasImproved = bush->improve();
			
			//while (true) { // for EQII
				mainLoop(bush, wasImproved, nbIter);
				//	if (!wasImproved) break; // for EQII
				//}; // for EQII
			count++;
			//if (count == 1) break;
			//std::cout << "MAX = " << Utils::checkFeasibility(net_, mat_) << std::endl;//*/
			//break;
			//if (bush->getOriginIndex() == 1) return 0;
		}
		/*FPType linkFlows[net_->getNbLinks()];
		for (int k = 0; k < net_->getNbLinks(); ++k) linkFlows[k] = 0.0;
		for (OriginBush *bush = originSet_->beginSet(); bush != NULL; bush = originSet_->getNextSet()){
			for (int k = 0; k < net_->getNbLinks(); ++k) {
				linkFlows[k] += bush->getOriginFlow(k);
			}
		}
		for (StarLink *link = net_->beginOnlyLink(); link != NULL; link = net_->getNextOnlyLink()) {
			std::cout << "link = " << link->getIndex() << " diff = " << fabs(linkFlows[link->getIndex()] - link->getFlow()) << std::endl;
		}*/
		/*for (OriginBush *bush = originSet_->beginSet(); bush != NULL; bush = originSet_->getNextSet()){
			std::cout << "Origin = " << bush->getOriginIndex() << " MAX = " << bush->checkOFlowsFeasibility() << std::endl;
		}//*/
		//return 0;
		//std::cout << "Here we should go inside of OriginBasedAlgoTapas" << std::endl;
		doSmthAfterOrigins(nbIter); // hook method - does nothing by default
		timer.stop(); 
		timePassed += timer.getTimePassed(); //((FPType)(end-start))/ (CLOCKS_PER_SEC);
		doSmthAfterLoop(timePassed, originSet_->getGapVal());
		//std::cout << timePassed << " " << originSet_->getGapVal() << " MAX = " << Utils::checkFeasibility(net_, mat_) << std::endl; 
		//originSet_->printTotalOriginFlows();
		//if (nbIter == 15) break;
		
	}
	doSmthAfterLoop(timePassed, originSet_->getGapVal());
	//net_->print();
	std::cout << "FINISH!!!! nbIter = " << nbIter << std::endl;
	return nbIter;
};

bool OriginBasedAlgo::mainLoop(OriginBush *bush, bool wasImproved, int nbIter){
	
	//if (bush->getOriginIndex() == 9) {
		//std::cout << "current bush:" << std::endl;
		//bush->print();
		//std::cout << " MAX = " << Utils::checkFeasibility(net_, mat_) << std::endl; 
	//}
	//std::cout << "current net:" << std::endl;
	//net_->print();
	
	//std::cout << "Equilibration" << std::endl;
	bool canMoveFlow = bush->equilibrate(wasImproved, nbIter); //bool canMoveFlow = 

	//if (bush->getOriginIndex() == 9){
		//std::cout << "bush after equilibration:" << std::endl;
		//bush->print();
	//}
		
	//std::cout << "current net:" << std::endl;
	//net_->print();
	
	//std::cout << "Removing unused links" << std::endl;
	bush->removeUnusedLinks();
	return canMoveFlow;
	
	//return true;
	
	// for equilibration II
	/*if (!canMoveFlow) return false;
	bush->updateSet();
	return bush->improve();//*/
	
};
