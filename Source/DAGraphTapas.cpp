#include "DAGraphTapas.h"
#include "Utils.h" 
#include "Error.h"

#include <cassert>
#include <math.h>

ShortestPath* DAGraphTapas::shPath_ = NULL;
PASManager* DAGraphTapas::pasManager_ = NULL;

DAGraphTapas::DAGraphTapas(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex, ShortestPath *shPath, PASManager *pasManager) : DAGraph(net, mat, zeroFlow, originIndex), minShift_(0.0), exploredLinks_() {
	 shPath_ = shPath;
	 pasManager_ = pasManager;
}; 

DAGraphTapas::~DAGraphTapas() {

}; 

bool DAGraphTapas::checkPositiveFlow(int linkIndex){
	return (getOriginFlow(linkIndex) > getZeroFlow());
};
// 
bool DAGraphTapas::moveFlow(int iter) {
  //std::cout << "Move Flow in TAPAS" << std::endl;
  //std::cout << "**********************ORIGIN = " << getOriginIndex() << "****************" << std::endl;
  shPath_->calculate(getOriginIndex()); // test
  // find links that are used by the origin, but are not part of min cost tree
  std::list<StarLink*> inLinks;
  StarLink* link = NULL;
  StarLink* shPathLink = NULL;
  int i = -1;
  //for (int i = beginDescPass(); i != -1; i = getNextDescPass()) {//loop over all links that belong to this bush
  for (int j = 0; j < nodeSize_; ++j) {
    i = nodeIndexes_[j];
    getInLinks(i, inLinks);
    shPathLink = shPath_->getInComeLink(i); 
    //std::cout << "node = " << i << " shPath = " << shPath_->getCost(i) << std::endl;
    //shPath_->printPath(i);
    
    if (shPathLink != NULL) {
	    for (std::list<StarLink*>::iterator it = inLinks.begin(); it != inLinks.end(); ++it){
	      link = *it;
	      // check if current link does not belong to the min-cost tree
	      if (getOriginFlow(link->getIndex()) > getZeroFlow() && link != shPathLink){
	      	//std::cout << "expLink == " << link->getIndex() << " [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex()  << "] shPathLink = " << shPathLink->getIndex() << " [" << shPathLink->getNodeFromIndex() << ", " << shPathLink->getNodeToIndex()  << "] shPathCost = " << shPath_->getCost(i) << std::endl;
		//std::cout << "link: " << link->getIndex() << " [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] oFlow = " << getOriginFlow(link->getIndex()) << std::endl;
		pasManager_->createNewPAS(this, link, i, iter);
	      }
	}
    }
  }
  //std::cout << "PASs created" << std::endl;
  //pasManager_->print();
  //removeCyclicFlows();
  
  // TODO: choose random subset of PAS and shift flow 
  // at the moment we just go through all active PAS
  //std::cout << "Moving flow within PAS" << std::endl;
 for (PAS *pas = pasManager_->beginPAS(); pas != NULL; pas = pasManager_->getNextPAS()){
  //int maxTries = 20; //0.8 * pasManager_->getNbPAS();
  //for (int i = 0; i < maxTries; ++i) {
  	//PAS* pas = pasManager_->getRandomPAS();
	//if (getOriginIndex() == 9 && pas->originIsIncluded(this)) std::cout << "Origin is relevant to PAS: " << pas->getIndex() << std::endl;
		//std::cout << "Moving flow of the PAS >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
		//pas->print();
		
	pas->moveFlow(iter);
	//std::cout << "Origin = " << getOriginIndex() << " MAX = " << checkOFlowsFeasibility() << std::endl;
	
	//std::cout << " MAX = " << Utils::checkFeasibility(net_, mat_) << std::endl; 
  }
  
  //std::cout << "PAS after flow move====================================================" << std::endl;
  //pasManager_->print();

  return false; // always returns false since it does not support EQII
}; 

void DAGraphTapas::setMinShift(FPType value){
	//std::cout << "value = " << value << std::endl; 
	assert(value >= 0.0);
	minShift_ = value;
};

FPType DAGraphTapas::getMinShift(){
	return minShift_;
};

// 
void DAGraphTapas::removeCyclicFlows(){
	//int i = 1;
	//std::cout << "removing back edges" << std::endl;
	while (true) {
		//std::cout << "Top sorting number " << i << std::endl;
		//++i;
		exploredLinks_.clear();
		bool tmp = topologicalSort();
		//std::cout << "One top sort done tmp = " << tmp << std::endl;
		//if (tmp == true) {
		//	tmp = topologicalSort();
		//	std::cout << "One top sort done tmp = " << tmp << std::endl;
		//	assert(1 == 0);
		//}
		if (tmp == false) break;
	};
};


// always returns true 
bool DAGraphTapas::handleBackEdge(StarLink* link){
	
	int linkInd = link->getIndex();
	//std::cout << "TAPAS: Back egde detected in DAG Link = " <<  linkInd << " oflow = " << getOriginFlow(linkInd) << " [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "]" << std::endl;
	
	// detect cycle;
	//std::cout << "Explored links: " << std::endl;
	int nextNode = link->getNodeFromIndex();
	int termNode = link->getNodeToIndex();
	StarLink* nextLink = NULL;
	std::list<StarLink*> cycle;
	cycle.push_back(link);
	for (std::list<StarLink*>::const_reverse_iterator it = exploredLinks_.rbegin(); it != exploredLinks_.rend(); ++it) {
		//std::cout << (*it)->toString() << " ";
		nextLink = *it;
		if (nextLink->getNodeToIndex() == nextNode){
			cycle.push_back(nextLink);
			nextNode = nextLink->getNodeFromIndex();
			if (nextNode == termNode) break;
		}
	}
	//std::cout << std::endl;
	//print();
	//std::cout << "Detected cycle: " << std::endl;
	FPType minFlow = getOriginFlow(linkInd);
	for(std::list<StarLink*>::iterator it = cycle.begin(); it != cycle.end(); ++it) {
		//std::cout << (*it)->toString() << " ";
		FPType flow = getOriginFlow((*it)->getIndex());
		if (flow < minFlow) minFlow = flow;
	}
	//std::cout << std::endl;
	
	// reduce flow on cycle by getOriginFlow(linkInd)
	StarLink *linkTmp = NULL;
	for(std::list<StarLink*>::iterator it = cycle.begin(); it != cycle.end(); ++it) {
		linkTmp = *it;
		if (fabs(getOriginFlow(linkTmp->getIndex()) - minFlow) < getZeroFlow()) {
			setOriginFlowToZero(linkTmp->getIndex());
		} else {
			addOriginFlow(linkTmp->getIndex(), -minFlow);
		}
		if (fabs(linkTmp->getFlow() - minFlow) < getZeroFlow()) {
			linkTmp->setFlowToZero();
		} else {
			linkTmp->addFlow(-minFlow);
		}
		linkTmp->updateTime();
	}
	//print();	
	//throw Error("Back edge is HERE");
	return true;	
};

void DAGraphTapas::handleExploredLink(StarLink* link){
	exploredLinks_.push_back(link);
};

