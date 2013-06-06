#include "OriginBasedAlgoTapas.h"

OriginBasedAlgoTapas::OriginBasedAlgoTapas(OriginSet *originSet, ODMatrix *mat, StarNetwork *net, PASManager& pasSet, AddHook *component) : OriginBasedAlgo(originSet, mat, net, component), pasSet_(pasSet) {

}; 

OriginBasedAlgoTapas::~OriginBasedAlgoTapas() {

}; 

void OriginBasedAlgoTapas::doSmthAfterOrigins(int iter) {
	// loop over each PAS
	for (PAS *pas = pasSet_.beginPAS(); pas != NULL; pas = pasSet_.getNextPAS()){
		if (pas->isUnused(iter)) {
			pasSet_.deletePAS(pas->getIndex());
		} else {
			pas->moveFlow(iter);
		}
	}
}; 

