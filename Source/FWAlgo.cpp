#include "FWAlgo.h"
#include "Timer.h"

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cassert>

FWAlgo::FWAlgo(LinkFlows *linkFlows, AddHook *component) : EqAlgo(component), _linkFlows(linkFlows){ //, _net(net){

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
	//clock_t start, end;
	Timer timer;
	double timePassed = 0.0;
	//FPType pr[5] = {1e-1, 1e-2, 1e-3, 1e-4, 1e-5};
	//std::string names[5] = {"ChRegional_1.flow", "ChRegional_2.flow", "ChRegional_3.flow", "ChRegional_4.flow", "ChRegional_5.flow"};
	//int count = 0;
	while (true) { 
		
		//start = clock();
		timer.start();
		nbIter++;
		
		// convergence check
		//std::cout << "************** precision = " << _linkFlows->getGapValue() << " pr = " << pr[count] << " " << (_linkFlows->getGapValue() <= pr[count]) << std::endl;
		
		if (_linkFlows->isConverged()) {
			//assert(count < 6);
			//std::cout << "************** precision = " << _linkFlows->getGapValue() << " is less than " << pr[count] << " is written to file: " << names[count] << std::endl;
			//_net->printToFile(names[count]);
			break;
		}
		/*if (_linkFlows->getGapValue() <= pr[count]) {
			assert(count < 6);
			std::cout << "************** precision = " << _linkFlows->getGapValue() << " is less than " << pr[count] << " is written to file: " << names[count] << std::endl;
			_net->printToFile(names[count]);
			++count;
			
		};*/
		
		// Update
		_linkFlows->updateLinkFlows();
		
		// Direction finding 
		_linkFlows->equilibrate(); //line search and flow shift
		
		//end = clock();
		timer.stop(); 
		timePassed += timer.getTimePassed(); //((FPType)(end-start))/ (CLOCKS_PER_SEC);
		//if ((nbIter % 20) == 0) {
			//printf ("%4.10f %4.10f \n", timePassed, _linkFlows->getGapValue());
			doSmthAfterLoop(timePassed, _linkFlows->getGapValue());
		//}
		
		if (timePassed > 28800) break;
		
	};
	//printf ("%4.10f %4.10f \n", timePassed, _linkFlows->getGapValue());
	doSmthAfterLoop(timePassed, _linkFlows->getGapValue());
	std::cout << "FINISH!!!! nbIter = " << nbIter << " gap = " << _linkFlows->getGapValue() << std::endl;
	return nbIter;
};

