#include "OriginBushB.h"

bool OriginBushB::useMultiStep_ = false;

OriginBushB::OriginBushB(int index, StarNetwork *net, bool useMultiStep) : OriginBush(index, net), dag_(NULL) {
	useMultiStep_ = useMultiStep;
};

OriginBushB::~OriginBushB(){

};
		
DAGraph* OriginBushB::createNewDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol){
	//std::cout << "in B" << std::endl;
	dag_ = new DAGraphB(net, mat, zeroFlow, dirTol, index, useMultiStep_); 
	return dag_;
};
