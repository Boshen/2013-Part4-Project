#include "OriginBushLUCE.h"
#include "DAGraphLUCE.h"

OriginBushLUCE::OriginBushLUCE(int index, StarNetwork *net) : 
				OriginBush(index, net), dag_(NULL) {
	std::cout << "OriginBushLUCE is created" << std::endl;
}; 

OriginBushLUCE::~OriginBushLUCE() {

}; 

void OriginBushLUCE::updateSet() {
	//recalculate link costs for all links + derivatives + flow portions
	dag_->update();
	OriginBush::updateSet();
}; 

void OriginBushLUCE::allocateDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol){
	std::cout << "LUCE allocateDAG" << std::endl;
	dag_ = new DAGraphLUCE(net, mat, zeroFlow, dirTol, index); // it is deallocated in parent destructor
	//return dag_;
};

