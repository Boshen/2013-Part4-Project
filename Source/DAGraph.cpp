#include "DAGraph.h"
#include "Error.h"
//#include "AlgorithmB.h"

#include <cassert>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <limits>

#define PRINT false
//topOrder_.front() == ORIGIN

StarNetwork* DAGraph::net_ = NULL;
ODMatrix* DAGraph::mat_ = NULL;
bool DAGraph::wasInitialised_ = false;
FPType DAGraph::zeroFlow_ = 0.0;

DAGraph::DAGraph(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, int originIndex) : nodeSize_(0), originIndex_(originIndex),  addedFromP2_(false), linkSize_(0), clock_(1) {
	
	if (!wasInitialised_) initialiseStaticMembers(net, mat, zeroFlow);
	wasInitialised_ = true;
	
	int nbLinks = net->getNbLinks();
	originFlows_ = new FPType[nbLinks];
	
	int nbNodes = net->getNbNodes();
	
	nodes_ = new DAGraphNode*[nbNodes]; //flowMove_->allocateNodesArray(nbNodes); 
	nodeIndexes_ = new int[nbNodes];
	for (int i = 0; i < nbNodes; i++) {
		nodes_[i] = NULL;
		nodeIndexes_[i] = -1;
	}
	
	//if (originIndex == 0) std::cout << "****nbLinks = " << nbLinks << std::endl;
	links_ = new StarLink*[nbLinks];
	
	for (int i = 0; i < nbLinks; i++) {
		links_[i] = NULL;
		originFlows_[i] = 0.0;
	}
	//if (originIndex == 0) std::cout << " links[0] =  " << links_[0] << std::endl;
	
	currNode_ = topOrder_.begin();
	currNodeDesc_ = topOrder_.rbegin();
	
};

DAGraph::~DAGraph(){
	for (int i = 0; i < nodeSize_; i++) {
		delete nodes_[nodeIndexes_[i]];
	}
	delete[] nodes_;
	delete[] nodeIndexes_;
	delete[] links_;
	delete[] originFlows_;
};

StarNetwork* DAGraph::getNet() {
	return net_;
};

FPType DAGraph::getZeroFlow(){
	return zeroFlow_;
};

void DAGraph::initialiseStaticMembers(StarNetwork *net, ODMatrix *mat, FPType zeroFlow){
	net_ = net;
	mat_ = mat;
	zeroFlow_ = zeroFlow;
};

FPType DAGraph::getDemand(int nodeIndex) const{
	assert(nodeIndex >= 0 && nodeIndex <  net_->getNbNodes());
	return nodes_[nodeIndex]->getDemand();
};

/*void DAGraph::setOriginFlow(int index, FPType flow){
	assert(index >= 0 && index < net_->getNbLinks());
	originFlows_[index] = flow;
};*/

void DAGraph::setOriginFlowToZero(int linkIndex){
	assert(linkIndex >= 0 && linkIndex < net_->getNbLinks());
	originFlows_[linkIndex] = 0.0;
};

int DAGraph::getOriginIndex() const{
	return originIndex_;
};

void DAGraph::addOriginFlow(StarLink* link, FPType demand){
	assert(link != NULL);
	int index = link->getIndex();
	if (links_[index] == NULL) {
		addLink(link);
	}
	addOriginFlow(link->getIndex(), demand);
};

void DAGraph::addOriginFlow(int linkIndex, FPType demand){
	assert(linkIndex >= 0 && linkIndex < net_->getNbLinks());
	if (links_[linkIndex] == NULL) {
		std::cout << "linkIndex = " << linkIndex << " demand = " << demand << std::endl;
		print();
	}
	assert(links_[linkIndex] != NULL);
	originFlows_[linkIndex] += demand;
};

/*bool DAGraph::moveFlow(int iter){
	//int count = 0;
	bool canMove = false;
	bool canMoveTmp = false;
	for (int i = beginDescPass(); i != -1; i = getNextDescPass()){
		if (nodes_[i]->getDemand() > 0.0) { 
			//if (originIndex_ == 27) std::cout << "node = " << i << " demand = " << nodes_[i]->getDemand() << std::endl;
			//printShPath(i);
			//printMaxShPath(i);
			canMoveTmp = flowMove_->performFlowMove(i, originIndex_); 
			if (canMoveTmp) {
				canMove = true;
				buildMinMaxTrees(i);
			}
		}
		//++count;
		//if (count == 3) return;
	}
	return canMove;
};*/

bool DAGraph::handleBackEdge(StarLink* link){
	std::cout << "Back egde detected in DAG Link = " <<  link->getIndex() << " oflow = " << getOriginFlow(link->getIndex()) << " [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "]" << std::endl;
	throw Error("Back egde detected in DAG"); 
	return true;
};

bool DAGraph::explore(int vertex, bool *visited){
	
	visited[vertex] = true;
	//std::cout << "Visiting vertex = " << vertex << std::endl;
	preVisit(vertex);
	std::list<StarLink*> &linksList = (nodes_[vertex])->outLinks;
	int index = -1;
	bool backEdgeDetected = false;
	for(std::list<StarLink*>::iterator it = linksList.begin(); it != linksList.end(); it++){
		index = (*it)->getNodeToIndex();
		if (checkPositiveFlow((*it)->getIndex())) {//(getOriginFlow((*it)->getIndex()) > zeroFlow_){ // TODO: this condition is only for TAPAS!!!!!!!
			handleExploredLink(*it);
			//std::cout << "Exploring link " << (*it)->getIndex() << " [" << (*it)->getNodeFromIndex() << ", " << index << "] oFlow = " << getOriginFlow((*it)->getIndex()) << std::endl;
			if ((nodes_[index])->getPre() == 0) {
				backEdgeDetected = explore(index, visited);
				if (backEdgeDetected) return true;
			}
			if ((nodes_[index])->getPre() > 0 && (nodes_[index])->getPost() == 0) {
				/*int linkInd = (*it)->getIndex();
				std::cout << "Back egde detected in DAG Link = " <<  linkInd << " oflow = " << getOriginFlow(linkInd) << " [" << (*it)->getNodeFromIndex() << ", " << (*it)->getNodeToIndex() << "]" << std::endl;
				if (getOriginFlow(linkInd) <= zeroFlow_) {
					removeLink(linkInd);
					linkIndexes_.remove(linkInd);
					return true;
				} else {
					throw Error("Back egde detected in DAG"); 
				}*/
				bool tmp = handleBackEdge(*it);
				//std::cout << "return val = " << tmp << std::endl;
				return tmp;
			}
		} // TODO: only for TAPAS
	}
	postVisit(vertex);
	return false;
};

void DAGraph::preVisit(int vertex){
	(nodes_[vertex])->setPre(clock_);
	clock_++;
};

void DAGraph::postVisit(int vertex){
	(nodes_[vertex])->setPost(clock_);
	clock_++;
	topOrder_.push_front(vertex);
};
		
bool DAGraph::topologicalSort(){
	clock_ = 1;
	topOrder_.clear();
	bool visited[net_->getNbNodes()];
	for (int i = 0; i < net_->getNbNodes(); i++) {
		visited[i] = false;
	}
	int index = -1;
	for (int i = 0; i < nodeSize_; i++) {
		index = nodeIndexes_[i];
		(nodes_[index])->setPre(0);
		(nodes_[index])->setPost(0);
	}
	
	
	for (int i = 0; i < nodeSize_; i++) {
		index = nodeIndexes_[i];
		if (!visited[index]) {
			bool tmp = explore(index, visited);
			//std::cout << "explore return  = " << tmp << std::endl;
			if (tmp == true) {
				//std::cout << "We found back edge and return true" << std::endl;
				return true;
			}
		}
	}
	return false;
	
};

void DAGraph::buildMinMaxTrees(int destIndex){
	int index = -1;
	for (int i = 0; i < nodeSize_; i++) {
		index = nodeIndexes_[i];
		//std::cout << index << " ";
		nodes_[index]->setMinDist(std::numeric_limits<FPType>::infinity( ));
		nodes_[index]->setMaxDist(0.0);
		//nodes_[index]->setHasLinkWithFlow(false);
	}
	//std::cout << std::endl;
	nodes_[originIndex_]->setMinDist(0.0); // set to zero for origin 
	
	// find shortest and longest paths with positive flow
	FPType dist = 0.0;
	FPType time = 0.0;
	int i = beginAscPass();
	
	//if (originIndex_ != i) std::cout << "i = " << i << " originIndex = " << originIndex_ << std::endl;
	assert(originIndex_ == i); //-- TODO: theoretically there might be 
					// an alternative top order that starts with another node -- not clear what to do in this case
	StarLink* link = NULL;
	//StarLink* minLink = NULL;				
	//StarLink* maxLink = NULL;
	//std::cout << "Origin = " << originIndex_ << " ";
	for (; i != -1; i = getNextAscPass()) {
		std::list<StarLink*> &linksList = nodes_[i]->incomeLinks;
		//bool hasFlow = false;
		for (std::list<StarLink*>::iterator it = linksList.begin(); it != linksList.end(); it++) {
			link = *it;
			index = link->getNodeFromIndex();
			assert(nodes_[index] != NULL);
			time = link->getTime();
			dist = nodes_[index]->getMinDist() + time; // min dist
			if (dist < nodes_[i]->getMinDist()) {
				nodes_[i]->setMinDist(dist);
				nodes_[i]->setMinLink(link); //flowMove_->calcMinData(i, link);
				//minLink = link;
			}
			dist = nodes_[index]->getMaxDist() + time; // max dist
			if (dist >= nodes_[i]->getMaxDist()) {
				nodes_[i]->setMaxDist(dist);
				nodes_[i]->setMaxLink(link); //flowMove_->calcMaxData(i, link);
				//maxLink = link;
			}
			//if (originFlows_[link->getIndex()] > zeroFlow_) hasFlow = true;
			
		}
		
		//nodes_[i]->setHasLinkWithFlow(hasFlow);
		if (i == destIndex) break;
		
	}
	//std::cout << std::endl;
};

bool DAGraph::addBetterLinks(){
	bool wasImproved = false;
	addedFromP2_ = false;
	p2Cont_.clear();
	for (int linkIndex = getNextNotInSet(-1); linkIndex != -1; linkIndex = getNextNotInSet(linkIndex)) {
		StarLink *link = net_->getLink(linkIndex);
		if (isReachable(link) && worthAdding(link)) {
			addLink(link);
			//FPType timec = link->getTime();
			link->updateTime();
			wasImproved = true;
			
		}
	}
	if (!wasImproved) {
		wasImproved = addFromP2();
	}
	return wasImproved;
};

bool DAGraph::addFromP2(){
	bool wasImproved = false;
	if (!p2Cont_.empty()) {
		for (std::list<int>::iterator it = p2Cont_.begin(); it != p2Cont_.end(); it++) {
			addLink(net_->getLink(*it));
			wasImproved = true;
			addedFromP2_ = true;
		}
	}
	return wasImproved;
};

bool DAGraph::worthAdding(StarLink* link){ 
	//assert(linkIndex >= 0 && linkIndex < net_->getNbLinks());
	//StarLink* link = net_->getLink(linkIndex);
	assert(link);
	FPType linkTime = link->getTime();
	int nodeFromIndex = link->getNodeFromIndex();
	int nodeToIndex = link->getNodeToIndex();
	assert(nodes_[nodeFromIndex] && nodes_[nodeToIndex]);
	if ((nodes_[nodeFromIndex])->getMaxDist() + linkTime < (nodes_[nodeToIndex])->getMaxDist()) { // check p2
		p2Cont_.push_back(link->getIndex());
		if (linkTime + (nodes_[nodeFromIndex])->getMinDist() < (nodes_[nodeToIndex])->getMinDist()) { // check p1
			return true;
		}
	}
	return false;
};

bool DAGraph::isReachable(StarLink* link) const {
	//assert(linkIndex >= 0 && linkIndex < net_->getNbLinks());
	//StarLink* link = net_->getLink(linkIndex);
	assert(link);
	int nodeFromIndex = link->getNodeFromIndex();
	int nodeToIndex = link->getNodeToIndex();
	return (nodes_[nodeFromIndex] != NULL && nodes_[nodeToIndex] != NULL);
};

// Always check if both nodes are reachable from a given origin after returning the link that is not yet in the set!!!!
int DAGraph::getNextNotInSet(int startIndex) const{
	int nbLinks = net_->getNbLinks();
	assert(startIndex >= -1 && startIndex < nbLinks);
	if (startIndex == nbLinks - 1) return -1;
	int index = startIndex + 1;
	while (links_[index] != NULL) {
		index++;
		if (index == nbLinks) return -1;
	}
	return index;
};

void DAGraph::addLink(StarLink *link){
	assert(link !=  NULL);
	int index = link->getIndex();
	//std::cout << "links_[index]  = " << links_[index] << std::endl;
	//std::cout << "index = " << index << " link0 = " << links_[0] << std::endl;
	if (links_[index] == NULL) { // check if this link has already been added
		
		//std::cout << "Adding link: " << index << std::endl;
		int nodeFromIndex = link->getNodeFromIndex();
		//std::cout << "0.05" << std::endl;
		int nodeToIndex = link->getNodeToIndex();
		//if (originIndex_ == 0) std::cout << "nodeFromIndex = " << nodeFromIndex << " nodeToIndex = " << nodeToIndex << std::endl;
		StarNode *nodeFrom = net_->getNodeWithLinks(nodeFromIndex);
		//std::cout << "0.1" << std::endl;
		StarNode *nodeTo = net_->getNodeWithLinks(nodeToIndex);
		//std::cout << "0.2" << std::endl;
		// zones restriction: (!curNode->getIsZone() || (topNode == originIndex))
		FPType demandTo = mat_->getDemandByIndex(originIndex_, nodeToIndex);
		if ((nodeTo == NULL || !nodeTo->getIsZone() || demandTo > 0.0) && (nodeFrom == NULL || !nodeFrom->getIsZone() || nodeFrom->getIndex() == originIndex_)) {
		
			//std::cout << "Adding link 2: " << index << std::endl;
			links_[index] = link;
			linkSize_++;
			linkIndexes_.push_back(index);
		
			if (nodes_[nodeFromIndex] == NULL) {
				//std::cout << "1" << std::endl;
				FPType demandFrom = mat_->getDemandByIndex(originIndex_, nodeFromIndex);
				DAGraphNode *newNode = new DAGraphNode(nodeFromIndex, demandFrom); //flowMove_->createDagNode(nodeFromIndex, demandFrom);
				nodes_[nodeFromIndex] = newNode;
				nodeIndexes_[nodeSize_] = nodeFromIndex;
				nodeSize_++;
				//if (originIndex_ == 0) std::cout << "nodeFromIndex was added" << std::endl;
			}
			if (nodes_[nodeToIndex] == NULL) {
				//std::cout << "2" << std::endl;
				//FPType demandTo = mat_->getDemandByIndex(originIndex_, nodeToIndex);
				DAGraphNode *newNode = new DAGraphNode(nodeToIndex, demandTo); //flowMove_->createDagNode(nodeToIndex, demandTo);
				nodes_[nodeToIndex] = newNode;
				nodeIndexes_[nodeSize_] = nodeToIndex;
				nodeSize_++;
				//if (originIndex_ == 0) std::cout << "nodeToIndex was added" << std::endl;
			} 
			//std::cout << "3" << std::endl;
			(nodes_[nodeToIndex])->incomeLinks.push_back(link);
			(nodes_[nodeFromIndex])->outLinks.push_back(link);
			//std::cout << "4" << std::endl;
		}
	}
	//if (originIndex_ == 0) std::cout << "5" << std::endl;
	//if (originIndex_ == 0) print();
};

bool DAGraph::removeLink(int index){
	
	if (links_[index] != NULL) {
		FPType flow = originFlows_[index];
		if (fabs(flow) <= zeroFlow_){
			int nodeToIndex = (links_[index])->getNodeToIndex();
			int nodeFromIndex = (links_[index])->getNodeFromIndex();
			if ((nodes_[nodeToIndex])->incomeLinks.size() > 1) {
				(nodes_[nodeToIndex])->incomeLinks.remove(links_[index]);
				/*std::cout << "links coming to " << nodeToIndex << std::endl;
				for (std::list<StarLink*>::iterator kt = (nodes_[nodeToIndex])->incomeLinks.begin(); kt != (nodes_[nodeToIndex])->incomeLinks.end(); ++kt) {
					std::cout << (*kt)->getIndex() << " ";
				}
				std::cout << std::endl;*/
				(nodes_[nodeFromIndex])->outLinks.remove(links_[index]);
				/*std::cout << "links going from " << nodeFromIndex << std::endl;
				for (std::list<StarLink*>::iterator kt = (nodes_[nodeFromIndex])->outLinks.begin(); kt != (nodes_[nodeFromIndex])->outLinks.end(); ++kt) {
					std::cout << (*kt)->getIndex() << " ";
				}
				std::cout << std::endl;*/
				//it = linkIndexes_.erase(it);
				links_[index] = NULL;
				linkSize_--;
				//std::cout << "link " << index << " [" << nodeFromIndex << ", " << nodeToIndex << "] was deleted" << std::endl;
				//print();
				return true;
			}
		}
	}
	return false;
};


bool DAGraph::removeUnusedLinks(const std::list<StarLink*> &links){
	int index = -1;
	bool wasDeleted = false;
	for(std::list<StarLink*>::const_iterator it = links.begin(); it != links.end(); it++){
		index = (*it)->getIndex();
		wasDeleted = removeLink(index);
		if (wasDeleted) {
			linkIndexes_.remove(index);
		}
	}
	return wasDeleted;
	
};

void DAGraph::removeFromLinkIndexes(int index){
	linkIndexes_.remove(index);
};

// at the moment No topological order is maintained!
bool DAGraph::removeUnusedLinks(){
	//FPType flow = 0.0;
	bool wasDeleted = false;
	for(std::list<int>::iterator it = linkIndexes_.begin(); it != linkIndexes_.end(); it++){
		//index = *it;
		/*assert(links_[index] != NULL);
		flow = originFlows_[index];
		if (fabs(flow) <= zeroFlow_){
			int nodeToIndex = (links_[index])->getNodeToIndex();
			int nodeFromIndex = (links_[index])->getNodeFromIndex();
			if ((nodes_[nodeToIndex])->incomeLinks.size() > 1) {
				(nodes_[nodeToIndex])->incomeLinks.remove(links_[index]);
				(nodes_[nodeFromIndex])->outLinks.remove(links_[index]);
				it = linkIndexes_.erase(it);
				links_[index] = NULL;
				linkSize_--;
				wasDeleted = true;
			}
		}*/
		wasDeleted = removeLink(*it);
		if (wasDeleted) {
			it = linkIndexes_.erase(it);
			--it;
		}
	}
	return wasDeleted;
};

std::list<StarLink*> DAGraph::getOutLinksCopy(int nodeIndex) const{
	assert((nodeIndex >= 0) && (nodeIndex < net_->getNbNodes()));
	return (nodes_[nodeIndex])->outLinks;
};

std::list<StarLink*> DAGraph::getInLinksCopy(int nodeIndex) const{
	assert((nodeIndex >= 0) && (nodeIndex < net_->getNbNodes()));
	return (nodes_[nodeIndex])->incomeLinks;
};

void DAGraph::getOutLinks(int nodeIndex, std::list<StarLink*>& listRef) {
	assert((nodeIndex >= 0) && (nodeIndex < net_->getNbNodes()));
	//std::cout << "nodes_[nodeIndex] = " << nodes_[nodeIndex] << " nodeIndex = " << nodeIndex << std::endl;
	listRef = (nodes_[nodeIndex])->outLinks;
	/*for (std::list<StarLink*>::iterator it = listRef.begin();  it != listRef.end(); ++it){
		std::cout << "link: " << *it << std::endl;
	}*/
};

void DAGraph::getInLinks(int nodeIndex, std::list<StarLink*>& listRef) {
	assert((nodeIndex >= 0) && (nodeIndex < net_->getNbNodes()));
	//std::cout << "nodes_[nodeIndex] = " << nodes_[nodeIndex] << " nodeIndex = " << nodeIndex << std::endl;
	listRef = (nodes_[nodeIndex])->incomeLinks;
	/*for (std::list<StarLink*>::iterator it = listRef.begin();  it != listRef.end(); ++it){
		std::cout << "link: " << *it << std::endl;
	}*/
};

/*const std::list<StarLink*>& DAGraph::getIncomeLinks(int nodeIndex) const{
	assert((nodeIndex >= 0) && (nodeIndex <  net_->getNbNodes()));
	return (nodes_[nodeIndex])->incomeLinks;
};*/

int DAGraph::beginAscPass(){
	if (nodeSize_ == 0) return -1;
	currNode_ = topOrder_.begin();
	if (topOrder_.begin() == topOrder_.end()) return -1;
	return *currNode_;
};

int DAGraph::getNextAscPass(){
	currNode_++;
	if (currNode_ == topOrder_.end()) return -1;
	return *currNode_;
};

int DAGraph::beginDescPass(){
	if (nodeSize_ == 0) return -1;
	currNodeDesc_ = topOrder_.rbegin();
	if (topOrder_.rbegin() == topOrder_.rend()) return -1;
	return *currNodeDesc_;
};

int DAGraph::getNextDescPass(){
	currNodeDesc_++;
	if (currNodeDesc_ == topOrder_.rend()) return -1;
	return *currNodeDesc_;
};

void DAGraph::print() const{
	int index = -1;
	std::cout << "ORIGIN = " << getOriginIndex() << std::endl;
	for (int i = 0; i < nodeSize_; i++) {
		index = nodeIndexes_[i];
		//std::cout << "index = " << index << std::endl;
		//StarLink* link1 = (nodes_[index])->getMinLink();
		//StarLink* link2 = (nodes_[index])->getMaxLink();
		//if (link1 != NULL && link2 != NULL) {
			std::cout << "Node " << (nodes_[index])->getIndex(); // << " in-links: "; //" minLink: [" << link1->getNodeFromIndex() << ", " << link1->getNodeToIndex() << "]" << " maxLink: [" << link2->getNodeFromIndex() << ", " << link2->getNodeToIndex() << "]
			/*std::list<StarLink*> &links = (nodes_[index])->incomeLinks;
			for(std::list<StarLink*>::iterator it = links.begin(); it != links.end(); it++){
				std::cout << (*it)->getIndex() << ": (" << (*it)->getNodeFromIndex() << ", " << (*it)->getNodeToIndex() << ") OriginFlow = " << originFlows_[(*it)->getIndex()] << " ";
			}//*/
			std::cout << " out-links: ";
			std::list<StarLink*> &links2 = (nodes_[index])->outLinks;
			for(std::list<StarLink*>::iterator it = links2.begin(); it != links2.end(); it++){
				std::cout << "link " << (*it)->getIndex() << " (" << (*it)->getNodeFromIndex() << ", " << (*it)->getNodeToIndex() << ") OriginFlow = " << originFlows_[(*it)->getIndex()] << " ";
			}//*/
			std::cout << std::endl;
		//}
	}
};

void DAGraph::printOriginFlow() const{
	std::cout << "Origin = " << originIndex_ << " nbLinks = " << net_->getNbLinks() << std::endl;
	for (int i = 0; i < net_->getNbLinks(); i++) {
		std::cout << originFlows_[i] << " ";
	}
	std::cout << std::endl;
};

void DAGraph::setOriginFlow(int index, FPType flow){
	assert(index >= 0 && index < net_->getNbLinks());
	originFlows_[index] = flow;
};

FPType DAGraph::getOriginFlow(int linkIndex) const{
	assert(linkIndex >= 0 && linkIndex < net_->getNbLinks());
	return originFlows_[linkIndex];
};

void DAGraph::printShPath(int node){
	StarLink *prevMin = (nodes_[node])->getMinLink();
	int prevNode = -1; 
	std::cout << "Cost = " << (nodes_[node])->getMinDist() << std::endl;
	FPType cost = 0.0;
	while (prevMin != NULL){
		prevNode = prevMin->getNodeFromIndex();
		cost += prevMin->getTime();
		std::cout << "[" << prevMin->getNodeToIndex() << ", " << prevNode << "] " << prevMin->getFlow() << "-";//" minDist = " << (nodes_[prevNode])->getMinDist() << " - ";
		prevMin = (nodes_[prevNode])->getMinLink();
	}
	std::cout << std::endl;
	//std::cout << "dest = " << node << " COST = " << cost << std::endl;
};

void DAGraph::printMaxShPath(int node){
	StarLink *prevMax = (nodes_[node])->getMaxLink();
	int prevNode = -1; 
	std::cout << "Cost = " << (nodes_[node])->getMaxDist() << std::endl;
	FPType cost = 0.0;
	while (prevMax != NULL){
		prevNode = prevMax->getNodeFromIndex();
		cost += prevMax->getFlow() * prevMax->getTime();
		std::cout << "[" << prevMax->getNodeToIndex() << ", " << prevNode << "] " << prevMax->getFlow() << " - ";
		prevMax = (nodes_[prevNode])->getMaxLink();
	}
	std::cout << std::endl;
	//std::cout << "COST = " << cost << std::endl;
};	

DAGraphNode* const DAGraph::getNode(int index) const{
	assert(index >= 0 && index < net_->getNbNodes());
	return nodes_[index];
};

FPType DAGraph::checkOFlowsFeasibility(){
	FPType total[net_->getNbNodes()];
	for (int i = 0; i < net_->getNbNodes(); i++) {
		total[i] = 0.0;
	}
	// load demands
	for (Origin *origin = mat_->beginOrigin(); origin != NULL; origin = mat_->getNextOrigin()) {
		if (origin->getIndex() == originIndex_){
			for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
				FPType demand = dest->getDemand();
				total[origin->getIndex()] += demand;
				total[dest->getIndex()] -= demand;
			}
		}
	}
	/*for (int i = 0;  i < net_->getNbNodes(); ++i){
		if (total[i] != 0.0)
			std::cout << "i = " << i << " demand = " << total[i] << " ";
	}
	std::cout << std::endl;
	*/
	//travers network and check
	
	int i = -1;
	StarLink* link = NULL;
	std::list<StarLink*> inLinks;
	for (int j = 0; j < nodeSize_; ++j) {
	    	i = nodeIndexes_[j];
	    	getInLinks(i, inLinks);
	    	for (std::list<StarLink*>::iterator it = inLinks.begin(); it != inLinks.end(); ++it){
	      		link = *it;
			total[link->getNodeFromIndex()] -= getOriginFlow(link->getIndex());
			total[link->getNodeToIndex()] += getOriginFlow(link->getIndex());
			//std::cout << "i = " << link->getNodeFromIndex() << " d = " << total[link->getNodeFromIndex()]  << " j = " << link->getNodeToIndex() << " d = " << total[link->getNodeToIndex()] << "; ";
		}
	
	}
	//std::cout << std::endl;
	
	/*std::cout << "After check" << std::endl;
	for (int i = 0;  i < net_->getNbNodes(); ++i){
		if (total[i] != 0.0)
			std::cout << "i = " << i << " demand = " << total[i] << " ";
	}
	std::cout << std::endl;*/
		
	FPType max = 0.0;
	//int ind = -1;
		
	for (int i = 0; i < net_->getNbNodes(); i++) {
		if (fabs(total[i]) > max) {	
			max = fabs(total[i]);
			//ind = i;
		}
	}
	//std::cout << "Node Index = " << ind << std::endl;
	return max;
};
