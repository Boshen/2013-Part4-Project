#include "DAGraphB.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <limits>

//#define PRINT false
//originIndex_ == 70 && index == 10
//originIndex_ == 94 && index == 104
//originIndex_ == ORIGIN

FPType DAGraphB::zeroFlow_ = 0.0;
FPType DAGraphB::dirTol_ = 0.0;

DAGraphB::DAGraphB(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex, bool useMultiStep) : DAGraph(net, mat, zeroFlow, dirTol, originIndex), useMultiStep_(useMultiStep), originIndex_(originIndex) {
	zeroFlow_ = zeroFlow;
	dirTol_ = dirTol;
};

DAGraphB::~DAGraphB(){

};

void DAGraphB::print() const{
	std::cout << "test" << std::endl;
};

bool DAGraphB::moveFlow(int iter){
	//int count = 0;
	bool canMove = false;
	bool canMoveTmp = false;
	for (int i = beginDescPass(); i != -1; i = getNextDescPass()){
		if (getDemand(i) > 0.0) { 
			//if (originIndex_ == 27) std::cout << "node = " << i << " demand = " << nodes_[i]->getDemand() << std::endl;
			//printShPath(i);
			//printMaxShPath(i);
			canMoveTmp = performFlowMove(i, originIndex_); 
			if (canMoveTmp) {
				canMove = true;
				buildMinMaxTrees(i);
			}
		}
		//++count;
		//if (count == 3) return;
	}
	return canMove;
}; 

bool DAGraphB::performFlowMove(int index, int origin){
	//if (PRINT) std::cout << "index = " << index << " origin = " << origin << std::endl;
	DAGraphNode * const node = getNode(index);
	if (node->getMaxDist() - node->getMinDist()  < dirTol_) {
		//if (PRINT) std::cout << "DIFF = " << node->getMaxDist() - node->getMinDist() << std::endl;
		return false;
	}
	
	StarLink* minLink = node->getMinLink();
	StarLink* maxLink = node->getMaxLink();
	if (minLink == NULL || maxLink == NULL) {
		return false;
	}
	
	std::list<Path*> paths;
	Path *minPath = new Path();
	Path *maxPath = new Path();
	paths.push_back(minPath); 
	paths.push_back(maxPath); 
	
	FPType minDist = node->getMinDist();
	FPType maxDist = node->getMaxDist();
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
				minLink = getNode(minNode)->getMinLink(); //nodes_[minNode]->getMinLink();
				 
				if (minLink != NULL) {
					minNode = minLink->getNodeFromIndex();
					//std::cout << "new minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << std::endl;
				}
				maxLink = getNode(maxNode)->getMaxLink();; //nodes_[maxNode]->getMaxLink();
				
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
			DAGraphNode * const nodeMin = getNode(minNode);
			DAGraphNode * const nodeMax = getNode(maxNode);
			if (nodeMin->getPost() < nodeMax->getPost()) { // minNode is upper in top order
				// we have to move minNode
				minLink = nodeMin->getMinLink();
				if (minLink != NULL) {
					minNode = minLink->getNodeFromIndex();
					minPath->addLinkToPath(minLink);
					//std::cout << "minLink: [" << minLink->getNodeFromIndex() << ", " << minLink->getNodeToIndex() << "]" << std::endl;
				}
			
			} else {
				maxLink = nodeMax->getMaxLink();
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
		/*if (PRINT) {
			std::cout << "---------------------------***********************" << " min = " << minDist << " max = " << maxDist << std::endl;
			minPath->print();
			//printMinPathOFlows(index);
			maxPath->print();
			//printMaxPathOFlows(index);
		}*/
		FPType minAdd = calcDistGap(minPath, minDist);
		FPType maxAdd = calcDistGap(maxPath, maxDist);
		/*int minSize = minPath->size();
		int maxSize = maxPath->size();
		FPType minCopy[minSize];
		FPType maxCopy[maxSize];
		FPType minCopyOrigin[minSize];
		FPType maxCopyOrigin[maxSize];
		int item = -1;//*/
		//FPType minDx = 0.0; 
		//std::cout << "minDx = " << minDx << " demand = " << nodes_[index]->getDemand() << std::endl;
		while (true) {
			
			
			//minDx = calculateMinFlowMove(index, nodes_[index]->getDemand());
			//minDx = nodes_[index]->getFlowMoved();
			dx = calcFlowStep(minPath, maxPath,  0.0);	
			
			/*if (PRINT) {
				std::cout << "*************************dx = " << dx << std::endl;
				std::cout << "index = " << index << " origin = " << origin << std::endl;
			}*/
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
			
			/*if (PRINT) {
				minPath->print();
				//printMinPathOFlows(index);
				maxPath->print();
				//printMaxPathOFlows(index);
			}*/
		
			if (maxDist < minDist) {
				/*restoreFlows(minPath, minCopy);
				restoreFlowsOrigin(minPath, minCopyOrigin);
				restoreFlows(maxPath, maxCopy);
				restoreFlowsOrigin(maxPath, maxCopyOrigin); */
				//if (dx > 0.0) std::cout << "dx = " << dx << std::endl; 
				//if (PRINT) std::cout << "minDist = " << minDist << " maxDist = " << maxDist << " diff = " << maxDist - minDist << " origin = " << origin << " dest = " << index << std::endl;
				break;
			}
			
			minPath->setCurrCost(minDist); 
			maxPath->setCurrCost(maxDist); 
			if (useMultiStep_ == false) break;
			
		}
		//if (PRINT) std::cout << "-----------------------------min = " << minPath->getCurrCost() << " max = " << maxPath->getCurrCost() << "---------------------------" << std::endl;
	}
		
	delete minPath;
	delete maxPath;
	return canMoveFlow;
	
};//*/

void DAGraphB::printMinPathOFlows(int index) const{
	StarLink *link = getNode(index)->getMinLink();
	std::cout << "MIN PATH origin flows" << std::endl;
	while (link != NULL){
		std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] " << getOriginFlow(link->getIndex()) << " ";
		link = getNode(link->getNodeFromIndex())->getMinLink();
	}
	std::cout << std::endl;
};

void DAGraphB::printMaxPathOFlows(int index) const{
	StarLink *link = getNode(index)->getMaxLink();
	std::cout << "MAX PATH origin flows" << std::endl;
	while (link != NULL){
		std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] " << getOriginFlow(link->getIndex()) << " ";
		link = getNode(link->getNodeFromIndex())->getMaxLink();
	}
	std::cout << std::endl;	
};

FPType DAGraphB::calculateMinFlowMove(int index, FPType demand) const{
	StarLink *link = getNode(index)->getMaxLink();
	FPType minDx = demand;
	FPType flow = 0.0;
	while (link != NULL){
		flow = getOriginFlow(link->getIndex());
		if (flow < minDx) minDx = flow;
		link = getNode(link->getNodeFromIndex())->getMaxLink();
	}
	return minDx;
	
};

/*void DAGraphB::restoreFlows(Path *path, FPType *flowCopy){
	int i = 0;
	for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
		link->setFlow(flowCopy[i]);
		link->updateTime();
		++i;
	}
};

void DAGraphB::restoreFlowsOrigin(Path *path, FPType *flowCopy){
	int i = 0;
	for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
		originFlows_[link->getIndex()] = flowCopy[i];
		++i;
	}
};*/

FPType DAGraphB::calcDistGap(Path *path, FPType dist){
	FPType newDist = 0.0;
	for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
		newDist += link->getTime();
	}
	assert(newDist <= dist);
	return dist - newDist;
	
};

void DAGraphB::addFlow(StarLink *link, FPType dFlow){
	link->addFlow(dFlow);
	addOriginFlow(link->getIndex(), dFlow);
	if (fabs(link->getFlow()) <= zeroFlow_) {
		link->setFlow(0.0);
		setOriginFlow(link->getIndex(), 0.0);
	}
	//FPType prevTime = link->getTime();
	//std::cout << "new o-flow on link [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] is " << originFlows_[link->getIndex()] << std::endl;
	link->updateTime();
	//std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] prevTime = " << prevTime << " newTime = " << link->getTime() << std::endl;
	
};

FPType DAGraphB::calcFlowStep(Path* minPath, Path* maxPath, FPType minDx) const{
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
		//h += link->getDerivative(); 
		h += fnc->evaluateDerivative(flow);
		//std::cout << "flow = " << flow << " h = " << h << std::endl;
	}
	FPType minMove = std::numeric_limits<double>::max( ); //minDx;
	FPType oFlow = 0.0;
	for(StarLink *link = maxPath->beginLink(); link != NULL; link = maxPath->getNextLink()){
		fnc = link->getLinkFnc();
		flow = link->getFlow();
		oFlow = getOriginFlow(link->getIndex());
		//h += link->getDerivative(); 
		h += fnc->evaluateDerivative(flow);
		//if (originIndex_ == 38) std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] originFlow = " << originFlows_[link->getIndex()] << " ";
		if (oFlow < minMove) minMove = oFlow;
		//if (link->getFlow() < minMove) minMove = link->getFlow();
	}
	//if (originIndex_ == 38)  std::cout << std::endl;
	assert(h >= 0.0);
	FPType dx = g / h;
	//if (PRINT)  std::cout << "g = " << g << " h = " << h << " dx = " << dx << " minDx = " << minDx  << " minMove = " << minMove << std::endl; //if (PRINT) 
	if (dx > minMove) return minMove;
	return dx;
	
};


