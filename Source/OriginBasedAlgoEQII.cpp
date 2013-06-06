#include "OriginBasedAlgoEQII.h"

OriginBasedAlgoEQII::OriginBasedAlgoEQII(OriginSet *originSet, ODMatrix *mat, StarNetwork *net, AddHook *component) : OriginBasedAlgo(originSet, mat, net, component) {

}; 

OriginBasedAlgoEQII::~OriginBasedAlgoEQII() {

}; 

void OriginBasedAlgoEQII::mainLoop(OriginBush *bush, bool wasImproved, int nbIter) {
  //bool wasImpCopy = wasImproved;
	while (true) { // for EQII
		//wasImpCopy = mainLoop(bush, wasImpCopy, nbIter);
		//std::cout << "Equilibration" << std::endl;
		bool canMoveFlow = bush->equilibrate(wasImproved, nbIter);
	
		//std::cout << "Removing unused links" << std::endl;
		bush->removeUnusedLinks();
	
		// for equilibration II
		if (!canMoveFlow) break;
		bush->updateSet();
		
		if (!bush->improve()) break; // for EQII
	}; // for EQII
	//return true;
}; 

