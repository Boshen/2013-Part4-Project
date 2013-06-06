#include "PAS.h"

#include <cassert>
#include <math.h>

FPType PAS::zeroFlow_ = 0.0;

PAS::PAS(int index, FPType zeroFlow) : index_(index), segCheap_(), segExp_(), relevantOrigins_(), lastIterMove_(0) {
	zeroFlow_ = zeroFlow;
}; 

PAS::~PAS() {

}; 

bool PAS::isUnused(int iter)const  {
	 if (iter - lastIterMove_ >= 2) { // flow was not moved for more than 2 consecutive iterations
	 	// check if expensive segment does not carry flow
	 	StarLink *link = NULL;
	 	for(std::list<StarLink*>::const_iterator it = segExp_.begin(); it != segExp_.end(); ++it){
			link = *it;
			if (fabs(link->getFlow()) > zeroFlow_) return false;
		}
		return true;
	 }
	 return false;
}; 

int PAS::getIndex()const  {
	 return index_;
}; 

void PAS::pushFrontToCheap(StarLink *link) {
	segCheap_.push_front(link);
}; 

void PAS::pushFrontToExp(StarLink *link) {
	segExp_.push_front(link);
}; 

void PAS::addOrigin(int index) {
	assert(index >= 0);
	relevantOrigins_.insert(index);
}; 

// TODO
void PAS::moveFlow(int iter) {
	lastIterMove_ = iter;
}; 

void PAS::print()const  {
	StarLink *link = NULL;
	std::cout << "cheap segment: ";
	for(std::list<StarLink*>::const_iterator it = segCheap_.begin(); it != segCheap_.end(); ++it){
		link = *it;
		std::cout << "[" << link->getNodeFromIndex() << " ," << link->getNodeToIndex() << "] ";
	}
	std::cout << std::endl;
	std::cout << "expensive segment: ";
	for(std::list<StarLink*>::const_iterator it = segExp_.begin(); it != segExp_.end(); ++it){
		link = *it;
		std::cout << "[" << link->getNodeFromIndex() << " ," << link->getNodeToIndex() << "] ";
	}
	std::cout << std::endl;
	std::cout << "Origins: ";
	for(std::set<int>::const_iterator it = relevantOrigins_.begin(); it != relevantOrigins_.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}; 

