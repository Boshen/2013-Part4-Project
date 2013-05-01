#include "DAGraph.h"
#include "Error.h"
#include "AlgorithmB.h"

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

DAGraph::DAGraph(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex) : originIndex_(originIndex),  addedFromP2_(false), 
							nodeSize_(0), linkSize_(0), clock_(1) {
	
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
	
	links_ = new StarLink*[nbLinks];
	
	for (int i = 0; i < nbLinks; i++) {
		links_[i] = NULL;
		originFlows_[i] = 0.0;
	}
	
	currNode_ = topOrder_.begin();
	currNodeDesc_ = topOrder_.rbegin();
	
	// TODO: depends on algo in params file
	flowMove_ = new AlgorithmB(originFlows_, originIndex, zeroFlow, dirTol, nodes_);
};

DAGraph::~DAGraph(){
	for (int i = 0; i < nodeSize_; i++) {
		delete nodes_[nodeIndexes_[i]];
	}
	delete[] nodes_;
	delete[] nodeIndexes_;
	delete[] links_;
	delete[] originFlows_;
	delete flowMove_;
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

int DAGraph::getOriginIndex() const{
	return originIndex_;
};

void DAGraph::addOriginFlow(int linkIndex, FPType demand){
	assert(linkIndex >= 0 && linkIndex < net_->getNbLinks());
	originFlows_[linkIndex] += demand;
};

bool DAGraph::moveFlow(){
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
};

void DAGraph::explore(int vertex, bool *visited){
	visited[vertex] = true;
	preVisit(vertex);
	std::list<StarLink*> &linksList = (nodes_[vertex])->outLinks;
	int index = -1;
	for(std::list<StarLink*>::iterator it = linksList.begin(); it != linksList.end(); it++){
		index = (*it)->getNodeToIndex();
		if ((nodes_[index])->getPre() == 0) explore(index, visited);
		if ((nodes_[index])->getPre() > 0 && (nodes_[index])->getPost() == 0) {
			std::cout << "Back egde detected in DAG Link = " <<  (*it)->getIndex() << std::endl;
			throw Error("Back egde detected in DAG"); 
		}
	}
	postVisit(vertex);
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
		
void DAGraph::topologicalSort(){
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
		if (!visited[index]) explore(index, visited);
	}
	
};

void DAGraph::buildMinMaxTrees(int destIndex){
	int index = -1;
	for (int i = 0; i < nodeSize_; i++) {
		index = nodeIndexes_[i];
		//std::cout << index << " ";
		nodes_[index]->setMinDist(std::numeric_limits<FPType>::infinity( ));
		nodes_[index]->setMaxDist(0.0);
		nodes_[index]->setHasLinkWithFlow(false);
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
		bool hasFlow = false;
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
			if (originFlows_[link->getIndex()] > zeroFlow_) hasFlow = true;
			
		}
		
		nodes_[i]->setHasLinkWithFlow(hasFlow);
		if (i == destIndex) break;
		
	}
	//std::cout << std::endl;
	
};

bool DAGraph::addBetterLinks(){
	bool wasImproved = false;
	addedFromP2_ = false;
	p2Cont_.clear();
	for (int linkIndex = getNextNotInSet(-1); linkIndex != -1; linkIndex = getNextNotInSet(linkIndex)) {
		if (isReachable(linkIndex) && worthAdding(linkIndex)) {
			addLink(net_->getLink(linkIndex));
			
			StarLink *link = net_->getLink(linkIndex);
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

bool DAGraph::worthAdding(int linkIndex){ 
	assert(linkIndex >= 0 && linkIndex < net_->getNbLinks());
	StarLink* link = net_->getLink(linkIndex);
	assert(link);
	FPType linkTime = link->getTime();
	int nodeFromIndex = link->getNodeFromIndex();
	int nodeToIndex = link->getNodeToIndex();
	assert(nodes_[nodeFromIndex] && nodes_[nodeToIndex]);
	if ((nodes_[nodeFromIndex])->getMaxDist() + linkTime < (nodes_[nodeToIndex])->getMaxDist()) { // check p2
		p2Cont_.push_back(linkIndex);
		if (linkTime + (nodes_[nodeFromIndex])->getMinDist() < (nodes_[nodeToIndex])->getMinDist()) { // check p1
			return true;
		}
	}
	return false;
};

bool DAGraph::isReachable(int linkIndex) const {
	assert(linkIndex >= 0 && linkIndex < net_->getNbLinks());
	StarLink* link = net_->getLink(linkIndex);
	assert(link);
	int nodeFromIndex = link->getNodeFromIndex();
	int nodeToIndex = link->getNodeToIndex();
	bool canReach = nodes_[nodeFromIndex] != NULL && nodes_[nodeToIndex] != NULL;
	return canReach; 
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
	int index = link->getIndex();
	if (links_[index] == NULL) { // check if this link has already been added
		
		int nodeFromIndex = link->getNodeFromIndex();
		int nodeToIndex = link->getNodeToIndex();
		StarNode *nodeFrom = net_->getNodeWithLinks(nodeFromIndex);
		StarNode *nodeTo = net_->getNodeWithLinks(nodeToIndex);
		
		// zones restriction: (!curNode->getIsZone() || (topNode == originIndex))
		if ((nodeTo == NULL || !nodeTo->getIsZone() || mat_->getDemandByIndex(originIndex_, nodeToIndex) > 0.0) && (nodeFrom == NULL || !nodeFrom->getIsZone() || nodeFrom->getIndex() == originIndex_)) {
		
			links_[index] = link;
			linkSize_++;
			linkIndexes_.push_back(index);
		
			if (nodes_[nodeFromIndex] == NULL) {
				FPType demandFrom = mat_->getDemandByIndex(originIndex_, nodeFromIndex);
				DAGraphNode *newNode = new DAGraphNode(nodeFromIndex, demandFrom); //flowMove_->createDagNode(nodeFromIndex, demandFrom);
				nodes_[nodeFromIndex] = newNode;
				nodeIndexes_[nodeSize_] = nodeFromIndex;
				nodeSize_++;
			}
			if (nodes_[nodeToIndex] == NULL) {
				FPType demandTo = mat_->getDemandByIndex(originIndex_, nodeToIndex);
				DAGraphNode *newNode = new DAGraphNode(nodeToIndex, demandTo); //flowMove_->createDagNode(nodeToIndex, demandTo);
				nodes_[nodeToIndex] = newNode;
				nodeIndexes_[nodeSize_] = nodeToIndex;
				nodeSize_++;
			} 
			(nodes_[nodeToIndex])->incomeLinks.push_back(link);
			(nodes_[nodeFromIndex])->outLinks.push_back(link);
		}
	}
};

// at the moment No topological order is maintained!
bool DAGraph::removeUnusedLinks(){
	FPType flow = 0.0;
	int index = -1;
	bool wasDeleted = false;
	for(std::list<int>::iterator it = linkIndexes_.begin(); it != linkIndexes_.end(); it++){
		index = *it;
		assert(links_[index] != NULL);
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
		}
	}
	return wasDeleted;
};

std::list<StarLink*> DAGraph::getOutLinksCopy(int nodeIndex) const{
	assert((nodeIndex >= 0) && (nodeIndex < net_->getNbNodes()));
	return (nodes_[nodeIndex])->outLinks;
};

const std::list<StarLink*>& DAGraph::getOutLinks(int nodeIndex) const{
	assert((nodeIndex >= 0) && (nodeIndex < net_->getNbNodes()));
	return (nodes_[nodeIndex])->outLinks;
};

const std::list<StarLink*>& DAGraph::getIncomeLinks(int nodeIndex) const{
	assert((nodeIndex >= 0) && (nodeIndex <  net_->getNbNodes()));
	return (nodes_[nodeIndex])->incomeLinks;
};

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
	for (int i = 0; i < nodeSize_; i++) {
		index = nodeIndexes_[i];
		StarLink* link1 = (nodes_[index])->getMinLink();
		StarLink* link2 = (nodes_[index])->getMaxLink();
		if (link1 != NULL && link2 != NULL) {
			std::cout << "Node " << (nodes_[index])->getIndex() << " minLink: [" << link1->getNodeFromIndex() << ", " << link1->getNodeToIndex() << "]" << " maxLink: [" << link2->getNodeFromIndex() << ", " << link2->getNodeToIndex() << "] links: ";
			std::list<StarLink*> &links = (nodes_[index])->incomeLinks;
			for(std::list<StarLink*>::iterator it = links.begin(); it != links.end(); it++){
				std::cout << "(" << (*it)->getNodeFromIndex() << ", " << (*it)->getNodeToIndex() << ") OriginFlow = " << originFlows_[(*it)->getIndex()] << " ";
			}
			std::cout << std::endl;
		}
	}
};

void DAGraph::printOriginFlow() const{
	std::cout << "Origin = " << originIndex_ << " nbLinks = " << net_->getNbLinks() << std::endl;
	for (int i = 0; i < net_->getNbLinks(); i++) {
		std::cout << originFlows_[i] << " ";
	}
	std::cout << std::endl;
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
