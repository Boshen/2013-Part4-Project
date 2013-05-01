#include "AlgorithmB.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <limits>

#define PRINT false
//originIndex_ == 70 && index == 10
//originIndex_ == 94 && index == 104
//originIndex_ == ORIGIN

FPType AlgorithmB::zeroFlow_ = 0.0;
FPType AlgorithmB::dirTol_ = 0.0;

AlgorithmB::AlgorithmB(FPType *originFlows, int originIndex, FPType zeroFlow, FPType dirTol, DAGraphNode * const * const nodes) : nodes_(nodes), originFlows_(originFlows), originIndex_(originIndex) {
	zeroFlow_ = zeroFlow;
	dirTol_ = dirTol;
};

AlgorithmB::~AlgorithmB(){

};

/*void AlgorithmB::calcMinData(int index, StarLink* link){
	nodes_[index]->setMinLink(link);
};

void AlgorithmB::calcMaxData(int index, StarLink* link){
	nodes_[index]->setMaxLink(link);
};*/

void AlgorithmB::print() const{
	std::cout << "test" << std::endl;
};

/*void AlgorithmB::performFlowMove(int index, int origin){
	if (PRINT) std::cout << "index = " << index << " origin = " << origin << std::endl;
	if (nodes_[index]->getMaxDist() - nodes_[index]->getMinDist()  < dirTol_) {
		if (PRINT) std::cout << "DIFF = " << nodes_[index]->getMaxDist() - nodes_[index]->getMinDist() << std::endl;
		return;
	}
	
	StarLink* minLink = nodes_[index]->getMinLink();
	StarLink* maxLink = nodes_[index]->getMaxLink();
	if (minLink == NULL || maxLink == NULL) {
		return;
	}
	
	if (minLink != maxLink && maxLink->getFlow() > 0.0) {
		if (PRINT) std::cout << "we can move flow" << std::endl;
		std::list<Path*> paths;
		Path *minPath = new Path();
		Path *maxPath = new Path();
		paths.push_back(minPath); 
		paths.push_back(maxPath); 
	
		FPType minDist = nodes_[index]->getMinDist();
		FPType maxDist = nodes_[index]->getMaxDist();
		//std::cout << "index = " << index << " minDist = " << minDist << " maxDist = " << maxDist << " diff = " << maxDist - minDist << std::endl;
	
		int minNode = minLink->getNodeFromIndex();
		int maxNode = maxLink->getNodeFromIndex();
	
		minPath->addLinkToPath(minLink);
		maxPath->addLinkToPath(maxLink);
		//std::cout << "Added minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << " maxLink: [" << maxLink->getNodeFromIndex() << ", " << maxLink->getNodeToIndex() << "]" << std::endl; //
	
		//std::cout << "minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << " maxLink: [" << maxLink->getNodeFromIndex() << ", " << maxLink->getNodeToIndex() << "]" << std::endl;
		//int count = 0;
		while (minNode != maxNode) {
			//count++;
			
			if (nodes_[minNode]->getPost() < nodes_[maxNode]->getPost()) { // minNode is upper in top order
				// we have to move minNode
				minLink = nodes_[minNode]->getMinLink();
				if (minLink != NULL) {
					minNode = minLink->getNodeFromIndex();
					minPath->addLinkToPath(minLink);
					//std::cout << "minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << std::endl;
				}
			} else {
				maxLink = nodes_[maxNode]->getMaxLink();
				if (maxLink != NULL) {
					maxNode = maxLink->getNodeFromIndex();
					maxPath->addLinkToPath(maxLink);
					//std::cout << "maxLink: [" << maxLink->getNodeFromIndex() << ", " << maxLink->getNodeToIndex() << "]" << std::endl;
				}
			}
			//if (count < 15) std::cout << "minNode = " << minNode << " maxNode = " << maxNode << std::endl;
		
		}
	
		
		FPType dx = 0.0;
		FPType minDx = 0.0; 
		FPType minDistSub = nodes_[minNode]->getMinDist();
		FPType maxDistSub = nodes_[minNode]->getMaxDist();	
			//if (true) std::cout << "dx = " << dx << std::endl;
		minPath->setCurrCost(minDist - minDistSub); 
		maxPath->setCurrCost(maxDist - maxDistSub);
		if (PRINT) {
			std::cout << "---------------------------***********************" << " min = " << minDist << " max = " << maxDist << std::endl;
			minPath->print();
			printMinPathOFlows(index);
			maxPath->print();
			printMaxPathOFlows(index);
		}
		//FPType minAdd = calcDistGap(minPath, minDist);
		//FPType maxAdd = calcDistGap(maxPath, maxDist);
			
			//std::cout << "minDx = " << minDx << " demand = " << nodes_[index]->getDemand() << std::endl;
		while (true) {
			
			//minDx = calculateMinFlowMove(index, nodes_[index]->getDemand());
			//minDx = nodes_[index]->getFlowMoved();
			dx = calcFlowStep(minPath, maxPath,  0.0);	
		
			if (PRINT) {
				std::cout << "*************************dx = " << dx << std::endl;
				std::cout << "index = " << index << " origin = " << origin << std::endl;
			}
			if (dx <= zeroFlow_) break;
			
			//nodes_[index]->setFlowMoved(minDx - dx);
			minDist = -minDistSub; //minAdd;
			//item = 0;
			for(StarLink *link = minPath->beginLink(); link != NULL; link = minPath->getNextLink()){
				//minCopy[item] = link->getFlow();
				//minCopyOrigin[item] = originFlows_[link->getIndex()];
				//++item;
				addFlow(link, dx);
				minDist += link->getTime();
			}
			
			maxDist = -maxDistSub; //maxAdd;
			//item = 0;
			for(StarLink *link = maxPath->beginLink(); link != NULL; link = maxPath->getNextLink()){
				//maxCopy[item] = link->getFlow();
				//maxCopyOrigin[item] = originFlows_[link->getIndex()];
				//++item;
				addFlow(link, -dx);
				maxDist += link->getTime();
			}
		
			if (PRINT) {
				minPath->print();
				printMinPathOFlows(index);
				maxPath->print();
				printMaxPathOFlows(index);
			}
		
			if (maxDist < minDist) {
				restoreFlows(minPath, minCopy);
				restoreFlowsOrigin(minPath, minCopyOrigin);
				restoreFlows(maxPath, maxCopy);
				restoreFlowsOrigin(maxPath, maxCopyOrigin);*/
				//if (dx > 0.0) std::cout << "dx = " << dx << std::endl; 
				/*if (PRINT) std::cout << "minDist = " << minDist << " maxDist = " << maxDist << " diff = " << maxDist - minDist << " origin = " << origin << " dest = " << index << std::endl;
				break;
			}
			minPath->setCurrCost(minDist); 
			maxPath->setCurrCost(maxDist); 
			break;
		
		}
		if (PRINT) std::cout << "min = " << minPath->getCurrCost() << " max = " << maxPath->getCurrCost() << "---------------------------" << std::endl;
		
		delete minPath;
		delete maxPath;
	}	
	
};//*/

// previously working copy. Let's try to make it better without kiling it

bool AlgorithmB::performFlowMove(int index, int origin){
	if (PRINT) std::cout << "index = " << index << " origin = " << origin << std::endl;
	if (nodes_[index]->getMaxDist() - nodes_[index]->getMinDist()  < dirTol_) {
		if (PRINT) std::cout << "DIFF = " << nodes_[index]->getMaxDist() - nodes_[index]->getMinDist() << std::endl;
		return false;
	}
	
	StarLink* minLink = nodes_[index]->getMinLink();
	StarLink* maxLink = nodes_[index]->getMaxLink();
	if (minLink == NULL || maxLink == NULL) {
		return false;
	}
	
	std::list<Path*> paths;
	Path *minPath = new Path();
	Path *maxPath = new Path();
	paths.push_back(minPath); 
	paths.push_back(maxPath); 
	
	FPType minDist = nodes_[index]->getMinDist();
	FPType maxDist = nodes_[index]->getMaxDist();
	//std::cout << "index = " << index << " minDist = " << minDist << " maxDist = " << maxDist << " diff = " << maxDist - minDist << std::endl;
	
	int minNode = minLink->getNodeFromIndex();
	int maxNode = maxLink->getNodeFromIndex();
	if (minNode != maxNode) {
		minPath->addLinkToPath(minLink);
		maxPath->addLinkToPath(maxLink);
		//std::cout << "Added minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << " maxLink: [" << maxLink->getNodeFromIndex() << ", " << maxLink->getNodeToIndex() << "]" << std::endl; //
	} else if (minLink != maxLink) {
		minPath->addLinkToPath(minLink);
		maxPath->addLinkToPath(maxLink);
		//std::cout << "Added minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << " maxLink: [" << maxLink->getNodeFromIndex() << ", " << maxLink->getNodeToIndex() << "]" << std::endl; //
	}
	//std::cout << "minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << " maxLink: [" << maxLink->getNodeFromIndex() << ", " << maxLink->getNodeToIndex() << "]" << std::endl;
	//int count = 0;
	while (true) {
		//count++;
		if (minNode == maxNode) {
			if (minNode == origin) {
				break;
			} else {
				// skip this link
				minLink = nodes_[minNode]->getMinLink();
				 
				if (minLink != NULL) {
					minNode = minLink->getNodeFromIndex();
					//std::cout << "new minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << std::endl;
				}
				maxLink = nodes_[maxNode]->getMaxLink();
				
				if (maxLink != NULL) {
					maxNode = maxLink->getNodeFromIndex();
					//std::cout << "new maxLink: [" << maxLink->getNodeFromIndex() << ", " << maxLink->getNodeToIndex() << "]" << std::endl; 
				}
				if (minNode != maxNode) {
					minPath->addLinkToPath(minLink);
					maxPath->addLinkToPath(maxLink);
					//if (PRINT) std::cout << "Both added" << std::endl;
				}
			}
		} else {
		
			if (nodes_[minNode]->getPost() < nodes_[maxNode]->getPost()) { // minNode is upper in top order
				// we have to move minNode
				minLink = nodes_[minNode]->getMinLink();
				if (minLink != NULL) {
					minNode = minLink->getNodeFromIndex();
					minPath->addLinkToPath(minLink);
					//std::cout << "minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << std::endl;
				}
			
			} else {
				maxLink = nodes_[maxNode]->getMaxLink();
				if (maxLink != NULL) {
					maxNode = maxLink->getNodeFromIndex();
					maxPath->addLinkToPath(maxLink);
					//std::cout << "maxLink: [" << maxLink->getNodeFromIndex() << ", " << maxLink->getNodeToIndex() << "]" << std::endl;
				}
			
			}
		}
		//if (count < 15) std::cout << "minNode = " << minNode << " maxNode = " << maxNode << std::endl;
		
	}
	
	//std::cout << "********" << std::endl;
	bool canMoveFlow = false;
	if ( !minPath->isEmpty() && !maxPath->isEmpty() ) {
		assert(minNode == maxNode && minNode == origin);
		
		FPType dx = 0.0;	
		minPath->setCurrCost(minDist); 
		maxPath->setCurrCost(maxDist); 
		//if (true) std::cout << "dx = " << dx << std::endl;
		if (PRINT) {
			std::cout << "---------------------------***********************" << " min = " << minDist << " max = " << maxDist << std::endl;
			minPath->print();
			//printMinPathOFlows(index);
			maxPath->print();
			//printMaxPathOFlows(index);
		}
		FPType minAdd = calcDistGap(minPath, minDist);
		FPType maxAdd = calcDistGap(maxPath, maxDist);
		/*int minSize = minPath->size();
		int maxSize = maxPath->size();
		FPType minCopy[minSize];
		FPType maxCopy[maxSize];
		FPType minCopyOrigin[minSize];
		FPType maxCopyOrigin[maxSize];
		int item = -1;*/
		//FPType minDx = 0.0; 
		//std::cout << "minDx = " << minDx << " demand = " << nodes_[index]->getDemand() << std::endl;
		while (true) {
			
			
			//minDx = calculateMinFlowMove(index, nodes_[index]->getDemand());
			//minDx = nodes_[index]->getFlowMoved();
			dx = calcFlowStep(minPath, maxPath,  0.0);	
			
			if (PRINT) {
				std::cout << "*************************dx = " << dx << std::endl;
				std::cout << "index = " << index << " origin = " << origin << std::endl;
			}
			if (dx <= zeroFlow_) {
				break;
			} else {
				canMoveFlow = true;
			}
			
			//nodes_[index]->setFlowMoved(minDx - dx);
			minDist = minAdd;
			//item = 0;
			for(StarLink *link = minPath->beginLink(); link != NULL; link = minPath->getNextLink()){
				//minCopy[item] = link->getFlow();
				//minCopyOrigin[item] = originFlows_[link->getIndex()];
				//++item;
				addFlow(link, dx);
				minDist += link->getTime();
			}
			
			maxDist = maxAdd;
			//item = 0;
			for(StarLink *link = maxPath->beginLink(); link != NULL; link = maxPath->getNextLink()){
				//maxCopy[item] = link->getFlow();
				//maxCopyOrigin[item] = originFlows_[link->getIndex()];
				//++item;
				addFlow(link, -dx);
				maxDist += link->getTime();
			}
			
			if (PRINT) {
				minPath->print();
				//printMinPathOFlows(index);
				maxPath->print();
				//printMaxPathOFlows(index);
			}
		
			if (maxDist < minDist) {
				/*restoreFlows(minPath, minCopy);
				restoreFlowsOrigin(minPath, minCopyOrigin);
				restoreFlows(maxPath, maxCopy);
				restoreFlowsOrigin(maxPath, maxCopyOrigin);*/
				//if (dx > 0.0) std::cout << "dx = " << dx << std::endl; 
				if (PRINT) std::cout << "minDist = " << minDist << " maxDist = " << maxDist << " diff = " << maxDist - minDist << " origin = " << origin << " dest = " << index << std::endl;
				break;
			}
			
			minPath->setCurrCost(minDist); 
			maxPath->setCurrCost(maxDist); 
			//break;
			
		}
		if (PRINT) std::cout << "-----------------------------min = " << minPath->getCurrCost() << " max = " << maxPath->getCurrCost() << "---------------------------" << std::endl;
	}
		
	delete minPath;
	delete maxPath;
	return canMoveFlow;
};//*/

void AlgorithmB::printMinPathOFlows(int index) const{
	StarLink *link = nodes_[index]->getMinLink();
	std::cout << "MIN PATH origin flows" << std::endl;
	while (link != NULL){
		std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] " << originFlows_[link->getIndex()] << " ";
		link = nodes_[link->getNodeFromIndex()]->getMinLink();
	}
	std::cout << std::endl;
};

void AlgorithmB::printMaxPathOFlows(int index) const{
	StarLink *link = nodes_[index]->getMaxLink();
	std::cout << "MAX PATH origin flows" << std::endl;
	while (link != NULL){
		std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] " << originFlows_[link->getIndex()] << " ";
		link = nodes_[link->getNodeFromIndex()]->getMaxLink();
	}
	std::cout << std::endl;	
};

FPType AlgorithmB::calculateMinFlowMove(int index, FPType demand) const{
	StarLink *link = nodes_[index]->getMaxLink();
	FPType minDx = demand;
	while (link != NULL){
		if (originFlows_[link->getIndex()] < minDx) minDx = originFlows_[link->getIndex()];
		link = nodes_[link->getNodeFromIndex()]->getMaxLink();
	}
	return minDx;
};

void AlgorithmB::restoreFlows(Path *path, FPType *flowCopy){
	int i = 0;
	for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
		link->setFlow(flowCopy[i]);
		link->updateTime();
		++i;
	}
};

void AlgorithmB::restoreFlowsOrigin(Path *path, FPType *flowCopy){
	int i = 0;
	for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
		originFlows_[link->getIndex()] = flowCopy[i];
		++i;
	}
};

FPType AlgorithmB::calcDistGap(Path *path, FPType dist){
	FPType newDist = 0.0;
	for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
		newDist += link->getTime();
	}
	assert(newDist <= dist);
	return dist - newDist;
};

void AlgorithmB::addFlow(StarLink *link, FPType dFlow){
	link->addFlow(dFlow);
	originFlows_[link->getIndex()] += dFlow;
	if (fabs(link->getFlow()) <= zeroFlow_) {
		link->setFlow(0.0);
		originFlows_[link->getIndex()] = 0.0;
	}
	//FPType prevTime = link->getTime();
	//std::cout << "new o-flow on link [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] is " << originFlows_[link->getIndex()] << std::endl;
	link->updateTime();
	//std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] prevTime = " << prevTime << " newTime = " << link->getTime() << std::endl;
};

FPType AlgorithmB::calcFlowStep(Path* minPath, Path* maxPath, FPType minDx) const{
	FPType g = maxPath->getCurrCost() - minPath->getCurrCost();
	if (g != g) {
		std::cout << "g = " << g << std::endl;
		std::cout << "max = " << maxPath->getCurrCost() << " min = " << minPath->getCurrCost() << std::endl;
	}
	assert(g >= 0.0);
	if (g < dirTol_) return 0.0;
	FPType h = 0.0;
	FPType flow = 0.0;
	
	LinkFnc* fnc = NULL;
	for (StarLink *link = minPath->beginLink(); link != NULL; link = minPath->getNextLink()) {
		fnc = link->getLinkFnc();
		flow = link->getFlow();
		h += fnc->evaluateDerivative(flow);
		//std::cout << "flow = " << flow << " h = " << h << std::endl;
	}
	FPType minMove = std::numeric_limits<double>::max( ); //minDx;
	for(StarLink *link = maxPath->beginLink(); link != NULL; link = maxPath->getNextLink()){
		fnc = link->getLinkFnc();
		flow = link->getFlow();
		h += fnc->evaluateDerivative(flow);
		//if (originIndex_ == 38) std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] originFlow = " << originFlows_[link->getIndex()] << " ";
		if (originFlows_[link->getIndex()] < minMove) minMove = originFlows_[link->getIndex()];
		//if (link->getFlow() < minMove) minMove = link->getFlow();
	}
	//if (originIndex_ == 38)  std::cout << std::endl;
	assert(h >= 0.0);
	FPType dx = g / h;
	if (PRINT)  std::cout << "g = " << g << " h = " << h << " dx = " << dx << " minDx = " << minDx  << " minMove = " << minMove << std::endl; //if (PRINT) 
	if (dx > minMove) return minMove;
	return dx;
};

/*DAGraphNode* AlgorithmB::createDagNode(int index, FPType demand){
	//std::cout << "index = " << index << std::endl;
	return new DAGraphNodeAlgoB(index, demand);
};

DAGraphNode** AlgorithmB::allocateNodesArray(int size){
	assert(size > 0);
	nodes_ = new DAGraphNodeAlgoB*[size];
	return (DAGraphNode**)nodes_;
};*/
