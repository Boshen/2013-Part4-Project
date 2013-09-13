#include "ODSetGPApp3.h"

ODMatrix* ODSetGPApp3::mat_ = NULL;
PathBasedFlowMoveGP* ODSetGPApp3::flowMoveGP_ = NULL;

ODSetGPApp3::ODSetGPApp3(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType zeroFlow, FPType *linkFlows, PathBasedFlowMoveGP* flowMove, ODMatrix *mat) : ODSet(index, destIndex, originIndex, pathCost, net, shPath, zeroFlow, linkFlows, flowMove) {
	mat_ = mat;
	flowMoveGP_ = flowMove;
}; 

ODSetGPApp3::~ODSetGPApp3() {

}; 

void ODSetGPApp3::calculateProjectedDirection() {
	FPType demand = mat_->getDemandByIndex(_originIndex, _destIndex);
	assert(demand > 0.0);
	flowMoveGP_->setDemand(demand);
}; 

void ODSetGPApp3::deallocProjectedDirection() {
	flowMoveGP_->setDemand(0.0);
}; 

