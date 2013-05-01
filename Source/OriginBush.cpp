#include "OriginBush.h"

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>

// static data
bool OriginBush::wasInitialised_ = false;
StarNetwork* OriginBush::net_ = NULL;
FPType* OriginBush::linkFlows_ = NULL;
int OriginBush::state_ = 0;

void OriginBush::initialiseStaticMembers(StarNetwork *net){
	if (!wasInitialised_) {
		net_ = net;
		linkFlows_ = new FPType[net->getNbLinks()];
		wasInitialised_ = true;
	}
};

void OriginBush::allocateDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol){
	std::cout << "DAGraph allocated" << std::endl;
	daGraph_ = new DAGraph(net, mat, zeroFlow, dirTol, index);
};

OriginBush::OriginBush(int index, StarNetwork *net) : daGraph_(NULL), index_(index), topSortUpToDate_(false) {
	if (!wasInitialised_) initialiseStaticMembers(net);
	//daGraph_ = allocateDAG(index, net, mat, zeroFlow, dirTol);
	state_++;
};

OriginBush::~OriginBush(){
	state_--;
	delete daGraph_;
	if (state_ == 0) { // last object was deleted
		delete[] linkFlows_;
		linkFlows_ = NULL; // since we don't know when the static pointer will be deleted
	}
};

void OriginBush::updateLinkCosts(){
 	net_->calculateLinkCosts();
}; 

StarNetwork* OriginBush::getNet(){
	return net_;
};

void OriginBush::addOriginFlow(int linkIndex, FPType demand){
	daGraph_->addOriginFlow(linkIndex, demand);
};

void OriginBush::updateSet(){
	// call topological sort if some of the links were removed on previous call of mainLoop on this bush
	if (!topSortUpToDate_) {
		daGraph_->topologicalSort();
		topSortUpToDate_ = true;
	}
};

// TODO: to test
bool OriginBush::improve(){
	// add promising links to daGraph_
	assert(topSortUpToDate_ == true);
	// 1. calculate min- and max-trees - initialise u_i and U_i (it is assumed that topological order exists)
	daGraph_->buildMinMaxTrees(-1);
	
	// 2. traverse all links that are not in the set yet and check if it is worth adding
	bool wasImproved = daGraph_->addBetterLinks();
	// 3. if the bush was improved - topological sort - to build passes
	if (wasImproved) { 
		daGraph_->topologicalSort();
	}
	return wasImproved;
};

// TODO: test
bool OriginBush::equilibrate(bool wasImproved){
	
	// if the bush was improved - ascending pass - calculate min- and max-trees + other required information
	if (wasImproved) daGraph_->buildMinMaxTrees(-1);
	
	return daGraph_->moveFlow();
	// descending pass - perform flow shift: CAUTION - here new flows will be directly assigned to links;
	// 			 + recalculate travel times of all links whose flow changed (the easiest way - to do it on the fly)
};

void OriginBush::removeUnusedLinks(){
	// remove links with zero flow from daGraph_ AND maintain connectivity
	if (daGraph_->removeUnusedLinks()) topSortUpToDate_ = false;
};

void OriginBush::addLink(StarLink *link){
	assert(link != NULL);
	// add link to daGraph_ in such a way that topological order is maintained - // TODO
	daGraph_->addLink(link);
};

void OriginBush::print(){
	std::cout << "Origin: " << index_ << std::endl;
	daGraph_->print();
};

int OriginBush::getOriginIndex() const{
	return index_;
};

void OriginBush::printOriginFlow() const{
	daGraph_->printOriginFlow();
};

FPType OriginBush::getOriginFlow(int linkIndex) const{
	return daGraph_->getOriginFlow(linkIndex);
};
