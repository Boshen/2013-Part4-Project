#include "PathBasedFlowMoveWithStep.h"

#include <stdlib.h>
#include <iostream>

//StepSize* PathBasedFlowMoveWithStep::_stepSize = NULL;

PathBasedFlowMoveWithStep::PathBasedFlowMoveWithStep(StepSize *stepSize, DescDirectionPath* pathDirectionAlgo, FPType zeroFlow) : PathBasedFlowMove(pathDirectionAlgo), stepSize_(stepSize), zeroFlow_(zeroFlow), dir_(NULL){

};

PathBasedFlowMoveWithStep::~PathBasedFlowMoveWithStep(){

};

bool PathBasedFlowMoveWithStep::executeFlowMove(){
	assert(dir_ != NULL);
	FPType alpha = stepSize_->getStepSize(dir_);
	//std::cout << "alpha = " << alpha << std::endl;
	if (alpha == 0.0) return true;
	Path* path = NULL;
	FPType tmp = 0.0;
	for(PathAndDirection *it = beginPathDirection(); it != NULL; it = getNextPathDirection()){
		path = it->getPath();
		tmp = path->getFlow() + alpha * it->getDirectionValue();
		if (tmp < zeroFlow_) tmp = 0.0;
		path->setFlow(tmp);
	}
	return false;
};

void PathBasedFlowMoveWithStep::setDescDirection(DescDirection* dir){
	dir_ = dir;
};
