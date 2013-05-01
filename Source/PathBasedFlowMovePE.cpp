#include "PathBasedFlowMovePE.h"

#include <stdlib.h>
#include <iostream>

PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath* pathDirectionAlgo) : PathBasedFlowMove(pathDirectionAlgo){

};

PathBasedFlowMovePE::~PathBasedFlowMovePE(){

};
		
bool PathBasedFlowMovePE::executeFlowMove(){
	Path *maxPath = (_pathDirection[0])->getPath();
	Path *minPath = (_pathDirection[1])->getPath();
	FPType maxDir = (_pathDirection[0])->getDirectionValue();
	FPType flow = maxPath->getFlow();
	if (flow < -maxDir) {
		maxPath->setFlow(0.0);
		minPath->setFlow(minPath->getFlow() + flow);
	} else {
		maxPath->setFlow(flow + maxDir);
		minPath->setFlow(minPath->getFlow() - maxDir);
	}
	return false;
};
