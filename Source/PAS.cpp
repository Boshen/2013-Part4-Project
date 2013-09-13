#include "PAS.h"
#include "DAGraphTapas.h"
#include "Utils.h"
//#include "PathDerivative.h"

#include <cassert>
#include <math.h>
#include <limits> 

FPType PAS::zeroFlow_ = 0.0;
FPType PAS::dirTol_ = 0.0;

PAS::PAS(FPType zeroFlow, FPType dirTol) : relevantOrigins_(), lastIterMove_(0), cheapCost_(0.0), expCost_(0.0), totalShift_(0.0), cheapSegm_(0), isUnused_(false) {
	zeroFlow_ = zeroFlow;
	dirTol_ = dirTol;
		
}; 

PAS::~PAS() {

}; 

bool PAS::isUnused(int iter)const  {
	//std::cout << "lastIterMove_ = " << lastIterMove_ << " iter = " << iter << std::endl;
	// if (iter - lastIterMove_ >= 2) { // flow was not moved for more than 2 consecutive iterations
	 	
	 //	return true;
	// } else {
	 	// check if expensive segment does not carry flow
	 	/*StarLink *link = NULL;
	 	//std::cout << "Checking exp segemnt:" << std::endl;
	 	for (std::set<DAGraphTapas*>::iterator it = relevantOrigins_.begin(); it != relevantOrigins_.end(); ++it) {
	 		bool hasZero = false;
			for(std::list<StarLink*>::const_iterator jt = segments_[1 - cheapSegm_].begin(); jt != segments_[1 - cheapSegm_].end(); ++jt){
				link = *jt;
				//std::cout << "link = " << link->getIndex() << " flow = " << link->getFlow() << " ";
				if ((*it)->getOriginFlow(link->getIndex()) <= zeroFlow_) {
					hasZero = true;
					break;
				}
			}
			if (!hasZero) {
				//std::cout << "Origin " << (*it)->getOriginIndex() << " is using this PAS" << std::endl;
				return false;
			}
		}
		//std::cout << "PAS is unused" << std::endl;
		return true;*/
		/*if (fabs(link->getFlow()) <= zeroFlow_) {
			std::cout << std::endl;
			std::cout << "PAS is unused" << std::endl;
			return true;
		}
		
		std::cout << std::endl;
		return false;*/
	// }
	 //return false;
	 return isUnused_;
}; 

//int PAS::getIndex()const  {
//	 return index_;
//}; 

void PAS::pushFrontToCheap(StarLink *link) {
	segments_[cheapSegm_].push_front(link);
	cheapCost_ += link->getTime();
}; 

void PAS::pushFrontToExp(StarLink *link) {
	segments_[1 - cheapSegm_].push_front(link);
	expCost_ += link->getTime();
}; 

void PAS::pushBackToCheap(StarLink *link){
	segments_[cheapSegm_].push_back(link);
	cheapCost_ += link->getTime();
};

void PAS::pushBackToExp(StarLink *link){
	segments_[1 - cheapSegm_].push_back(link);
	expCost_ += link->getTime();
};		
		
StarLink* PAS::getLastCheapLink(){
	if (segments_[cheapSegm_].empty()) return NULL;
	return segments_[cheapSegm_].back();
};

StarLink* PAS::getLastExpLink(){
	if (segments_[1 - cheapSegm_].empty()) return NULL;
	return segments_[1 - cheapSegm_].back();
};
				
bool PAS::addOrigin(DAGraphTapas* dag) {
	assert(dag != NULL);
	return relevantOrigins_.insert(dag).second;
}; 

bool PAS::checkIfEffective(FPType cost, FPType v, int index, DAGraphTapas* dag){
	return checkIfCostEffective(cost) && checkIfFlowEffective(v, index, dag);
};

bool PAS::checkIfFlowEffective(FPType v, int index, DAGraphTapas* dag) const{
	assert(index >= 0);
	FPType minFlow = std::numeric_limits<FPType>::max();
	FPType flow = 0.0;
	for (std::list<StarLink*>::const_iterator it = segments_[1 - cheapSegm_].begin(); it != segments_[1 - cheapSegm_].end(); ++it) {
		flow = dag->getOriginFlow((*it)->getIndex());
		if (flow < minFlow) minFlow = flow; 
	}
	//std::cout << "minFlow = " << minFlow << std::endl;
	return (minFlow >= v * dag->getOriginFlow(index));
};

bool PAS::checkIfCostEffective(FPType cost) const{
	//std::cout << "costDiff = " << expCost_ - cheapCost_ << std::endl;
	return (expCost_ - cheapCost_ >= cost);
};
// 
void PAS::moveFlow(int iter) {
	
	recalcPASCosts();
	//std::cout << "Cost diff = " << expCost_ - cheapCost_ << " PAS: " << std::endl;
	//print();
	//std::cout << "--------------------------------------------" << std::endl;
	if (expCost_ - cheapCost_ >= dirTol_) {
		// flow shift
		isUnused_ = false;
		FPType dFlow = calculateFlowShift(); //calculates appropriate shift and min shifts for each origin
		//std::cout << "dFlow = " << dFlow << std::endl;
		StarLink* link = NULL;
		if (dFlow > 0.0) lastIterMove_ = iter;
		// update origin flows
		//FPType prevFlow = 0.0;
		for (std::set<DAGraphTapas*>::iterator dag = relevantOrigins_.begin(); dag != relevantOrigins_.end(); ++dag) {
			if (totalShift_ > 0.0) {
				FPType flowShift = (*dag)->getMinShift() / totalShift_ * dFlow;
				if (flowShift > zeroFlow_) {
					//print();
					//std::cout << "ORIGIN = " << (*dag)->getOriginIndex() << " flowShift = " << flowShift << std::endl;
					//if ((*dag)->getOriginIndex() == 20) std::cout << "cheap link:" << std::endl;
					for (std::list<StarLink*>::iterator it = segments_[cheapSegm_].begin(); it != segments_[cheapSegm_].end(); ++it) {
						link = *it;
						
						//prevFlow = (*dag)->getOriginFlow(link->getIndex());
						//std::cout << "Cheap Adding flow to link = " << link->toString() << std::endl; 
						(*dag)->addOriginFlow(link, flowShift); // link will be added to the bush if it is not there
						//if ((*dag)->getOriginIndex() == 20) std::cout << link->toString() << " ";
						
					}
					//if ((*dag)->getOriginIndex() == 20) std::cout << std::endl;
					//if ((*dag)->getOriginIndex() == 20) std::cout << "exp link:" << std::endl;
					for (std::list<StarLink*>::iterator it = segments_[1 - cheapSegm_].begin(); it != segments_[1 - cheapSegm_].end(); ++it) {
						link = *it;
						
						//prevFlow = (*dag)->getOriginFlow(link->getIndex());
						if (fabs((*dag)->getOriginFlow(link->getIndex()) - flowShift) < zeroFlow_) {
							//std::cout << "link->getFlow() - flowShift = " << link->getFlow() - flowShift << std::endl;
							(*dag)->setOriginFlowToZero(link->getIndex());
						} else {
							//assert((*dag)->getOriginFlow(link->getIndex()) - flowShift >= 0.0);
						
							//std::cout << "Exp Adding flow to link = " << link->toString() << std::endl;
							(*dag)->addOriginFlow(link, -flowShift); // link will be added to the bush if it is not there
						}
						//if ((*dag)->getOriginIndex() == 20) std::cout << link->toString() << " ";
						
					}
					//if ((*dag)->getOriginIndex() == 20) std::cout << std::endl;
				}
			} else {
				assert(dFlow == 0.0);
			}
			//std::cout << "DAG after flow move:" << std::endl;
			//(*dag)->print();
		}
		
		// update link flows and costs
		//std::cout << "***************************************************" << std::endl;
		if (dFlow > zeroFlow_) {
			//std::cout << "cheap link:" << std::endl;
			for (std::list<StarLink*>::iterator it = segments_[cheapSegm_].begin(); it != segments_[cheapSegm_].end(); ++it) {
				link = *it;
				//prevFlow = link->getFlow();
				link->addFlow(dFlow);
				link->updateTime();
				//std::cout << link->getIndex() << ": [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] flow = " << link->getFlow() << " prevFlow = " << prevFlow << " ";
			}
			//std::cout << std::endl;
			//std::cout << "exp link: " << std::endl;
			for (std::list<StarLink*>::iterator it = segments_[1 - cheapSegm_].begin(); it != segments_[1 - cheapSegm_].end(); ++it) {
				link = *it;
				//prevFlow = link->getFlow();
				if (fabs(link->getFlow() - dFlow) < zeroFlow_) {
					link->setFlowToZero();
				} else {
					link->addFlow(-dFlow);
				}
				link->updateTime();
				//std::cout << link->getIndex() << ": [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] flow = " << link->getFlow() << " prevFlow = " << prevFlow << " ";
			}
			//std::cout << std::endl;
		}
	} else {
		isUnused_ = true; // TODO: think about it
	}
}; 

//
FPType PAS::calculateFlowShift(){
	// calculate maximum feasible shift
	//FPType maxShift = 0.0;
	totalShift_ = 0.0;
	//std::cout << "index_ = " << index_ << std::endl;
	for (std::set<DAGraphTapas*>::iterator dag = relevantOrigins_.begin(); dag != relevantOrigins_.end(); ++dag) {
		FPType minFlowShift = std::numeric_limits<FPType>::max();
		StarLink* link = NULL;
		FPType oFlow = 0.0;
		for (std::list<StarLink*>::iterator it = segments_[1 - cheapSegm_].begin(); it != segments_[1 - cheapSegm_].end(); ++it) {
			link = *it;
			oFlow = (*dag)->getOriginFlow(link->getIndex());
			//std::cout << "oFlow = " << oFlow  << " " << link->getIndex() << " [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "]" << std::endl;
			if (oFlow < minFlowShift) minFlowShift = oFlow;
		}
		(*dag)->setMinShift(minFlowShift);
		totalShift_ += minFlowShift;
	}
	
	//std::cout << "totalShift_ = " << totalShift_ << std::endl;
	//assert(totalShift_ > 0.0);
	
	// I am not sure about this part
	/*FPType segCost = 0.0;
	StarLink *link = NULL;
	for (std::list<StarLink*>::iterator it = segments_[1 - cheapSegm_].begin(); it != segments_[1 - cheapSegm_].end(); ++it) {
		link = *it;
		std::cout << "link->getFlow() - totalShift_ = " << link->getFlow() - totalShift_ << " link->getFlow() = " << link->getFlow() << std::endl;
		assert(link->getFlow() - totalShift_ >= 0.0);
		segCost += link->getLinkFnc()->evaluate(link->getFlow() - totalShift_);
	}
	if (segCost >= cheapCost_) return totalShift_;*/
	
	// Newton step
	//PathDerivative der(0);
	FPType dFlow = (expCost_ - cheapCost_) / Utils::calculateForDisjoint2(segments_[cheapSegm_], segments_[1 - cheapSegm_]);
	//std::cout << "Newton dFlow = " << dFlow << std::endl;
	assert(dFlow >= 0.0 && dFlow == dFlow);
	if (dFlow > totalShift_) {
		dFlow = totalShift_;
		isUnused_ = true; // entire flow was moved
	}
	return dFlow;
};

FPType PAS::calcSegCost(int index){
	assert(index >= 0 && index < 2);
	FPType segCost = 0.0;
	for (std::list<StarLink*>::iterator it = segments_[index].begin(); it != segments_[index].end(); ++it) {
		segCost += (*it)->getTime();
	}
	return segCost;
};

//Recalculate PAS costs and change cheap and exp segments if necessary
void PAS::recalcPASCosts(){
	FPType cost0 = 	calcSegCost(0);
	FPType cost1 = 	calcSegCost(1);
	if (cost0 < cost1) {
		cheapSegm_ = 0;
		cheapCost_ = cost0;
		expCost_ = cost1;
	} else {
		cheapSegm_ = 1;
		cheapCost_ = cost1;
		expCost_ = cost0;
	}
};

bool PAS::originIsIncluded(DAGraphTapas* dag){
	return relevantOrigins_.find(dag) != relevantOrigins_.end();
};


void PAS::addCheapLinksToBush(DAGraphTapas* dag){
	//std::cout << "Adding links to bush ORIGIN = " << dag->getOriginIndex() << std::endl;
	for (std::list<StarLink*>::iterator it = segments_[cheapSegm_].begin(); it != segments_[cheapSegm_].end(); ++it) {
		//std::cout << (*it)->toString() << " ";
		dag->addLink(*it);
	}
	//std::cout << std::endl;
	//std::cout << "Modified bush:::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	//dag->print();
};

void PAS::deleteLinksFromBushes(){
	//StarLink *link = NULL;
	for(std::set<DAGraphTapas*>::iterator jt = relevantOrigins_.begin(); jt != relevantOrigins_.end(); ++jt) {
		for (int i = 0; i <= 1; ++i){ 
			(*jt)->removeUnusedLinks(segments_[i]);
		}	
	}
};

/*bool PAS::hasLink(StarLink *link) const{
	for (int i = 0; i < 2; ++i){
		for (std::list<StarLink*>::const_iterator it = segments_[i].begin(); it != segments_[i].end(); ++it) {
			if (*it == link) return true;
		}
	}
	return false;
};

//Only cheap segment is checked
bool PAS::hasSegment(const std::list<StarLink*> &seg) const{
	std::list<StarLink*>::const_iterator segIt = seg.begin();
	for (std::list<StarLink*>::const_iterator it = segments_[cheapSegm_].begin(); it != segments_[cheapSegm_].end(); ++it){
		if (*segIt == *it) {
			for (; segIt != seg.end(); ++segIt) {
				if (it == segments_[cheapSegm_].end()) break;
				if (*segIt != *it) return false;
				++it;
			}
			if (segIt == seg.end()) {
				return true;
			} else {
				return false;
			}
		}
	}
	return false;
};*/

/*void PAS::deleteCheapLinksFromBush(DAGraphTapas* dag){
	dag->removeUnusedLinks(segments_[cheapSegm_]);
};*/

bool PAS::originSetIsEmpty() const{
	return relevantOrigins_.empty();
};
		
void PAS::deleteOrigin(DAGraphTapas* dag){
	relevantOrigins_.erase(dag);
};

		
void PAS::print()const  {
	StarLink *link = NULL;
	std::cout << "cheap segment cost = " << cheapCost_ << " ";
	for(std::list<StarLink*>::const_iterator it = segments_[cheapSegm_].begin(); it != segments_[cheapSegm_].end(); ++it){
		link = *it;
		std::cout << "link " << link->getIndex() << " [" << link->getNodeFromIndex() << " ," << link->getNodeToIndex() << "] time = " << link->getTime() << " flow = " << link->getFlow() << " ";
	}
	std::cout << std::endl; 
	std::cout << "expensive segment cost = " << expCost_ << " ";
	for(std::list<StarLink*>::const_iterator it = segments_[1 - cheapSegm_].begin(); it != segments_[1 - cheapSegm_].end(); ++it){
		link = *it;
		std::cout << "link " << link->getIndex() << " [" << link->getNodeFromIndex() << " ," << link->getNodeToIndex() << "] time = " << link->getTime() << " flow = " << link->getFlow() << " ";
	}
	std::cout << std::endl;
	std::cout << "Origins: ";
	for(std::set<DAGraphTapas*>::const_iterator it = relevantOrigins_.begin(); it != relevantOrigins_.end(); ++it){
		std::cout << (*it)->getOriginIndex() << " ";
	}
	std::cout << std::endl;
}; 

