#include "DAGraphTapas.h"

DAGraphTapas::DAGraphTapas(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex, ShortestPath &shPath, PASManager &pasManager) : DAGraph(net, mat, zeroFlow, dirTol, originIndex), shPath_(shPath), pasManager_(pasManager) {

}; 

DAGraphTapas::~DAGraphTapas() {

}; 

// TODO: 
bool DAGraphTapas::moveFlow(int iter) {
  shPath_.calculate(getOriginIndex()); // test
  // find links that are used by the origin, but are not part of min cost tree
  std::list<StarLink*> inLinks;
  StarLink* link = NULL;
  StarLink* shPathLink = NULL;
  for (int i = beginDescPass(); i != -1; i = getNextDescPass()) {//loop over all links that belong to this bush
    getInLinks(i, inLinks);
    shPathLink = shPath_.getInComeLink(i); 
    for (std::list<StarLink*>::iterator it = inLinks.begin(); it != inLinks.end(); ++it){
      link = *it;
      // check if current link does not belong to the min-cost tree
      if (getOriginFlow(link->getIndex()) > getZeroFlow() && link != shPathLink){
	pasManager_.createNewPAS(*this, i);
      }
    }
  }
  // TODO: choose random subset of PAS and shift flow 
  return false; // always returns false since it does not support EQII
}; 


