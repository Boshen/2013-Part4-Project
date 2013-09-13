#include "PathBasedFlowMoveGP.h"

#include <cassert>

PathBasedFlowMoveGP::PathBasedFlowMoveGP(FPType alpha, DescDirectionPath* pathDirectionAlgo) : PathBasedFlowMove(pathDirectionAlgo), _alpha(alpha), _demand(0.0) {

};

PathBasedFlowMoveGP::~PathBasedFlowMoveGP(){

};

void PathBasedFlowMoveGP::setDemand(FPType demand){
	//std::cout << "demand = " << demand << std::endl;
	//assert(demand > 0.0);
	_demand = demand;
};

bool PathBasedFlowMoveGP::executeFlowMove(){
	
	FPType totalFlowToMove = 0.0;
	Path *currPath = NULL;
	FPType currDir = 0.0;
	FPType flow = 0.0;
	for (int i = 0; i < _size-1; i++) {
		currPath = (_pathDirection[i])->getPath();
		currDir = (_pathDirection[i])->getDirectionValue();
		if (currPath->getFlow() < -_alpha * currDir) {
			currPath->setFlow(0.0);
		} else {
			flow = currPath->getFlow() + _alpha * currDir;
			currPath->setFlow(flow);
			totalFlowToMove += flow;
		}
	}
	Path *minPath = (_pathDirection[_size - 1])->getPath();
	minPath->setFlow(_demand - totalFlowToMove);
	return false;
};
