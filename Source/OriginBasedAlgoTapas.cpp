#include "OriginBasedAlgoTapas.h"


OriginBasedAlgoTapas::OriginBasedAlgoTapas(OriginSet *originSet, ODMatrix *mat, StarNetwork *net, PASManager* pasSet, AddHook *component) : OriginBasedAlgo(originSet, mat, net, component), pasSet_(pasSet) {

}; 

OriginBasedAlgoTapas::~OriginBasedAlgoTapas() {

}; 

void OriginBasedAlgoTapas::doSmthAfterOrigins(int iter) {
	// loop over each PAS
	//std::cout << "and here we are!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;	
	pasSet_->deleteUnusedPASAndMoveFlow(iter);
}; 

