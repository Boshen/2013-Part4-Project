#include "PathBasedFlowMoveWithStep.h"

#include <stdlib.h>
#include <iostream>

PathBasedFlowMoveWithStep::PathBasedFlowMoveWithStep(StepSize *stepSize, DescDirectionPath* pathDirectionAlgo) : PathBasedFlowMove(pathDirectionAlgo){
	_stepSize = stepSize;
};

PathBasedFlowMoveWithStep::~PathBasedFlowMoveWithStep(){

};

bool PathBasedFlowMoveWithStep::executeFlowMove(){
	FPType alpha = _stepSize->getStepSize();
	if (alpha == 0.0) return true;
	Path* path = NULL;
	for(PathAndDirection *it = beginPathDirection(); it != NULL; it = getNextPathDirection()){
		path = it->getPath();
		path->setFlow(path->getFlow() + alpha * it->getDirectionValue());
	}
	return false;
};
