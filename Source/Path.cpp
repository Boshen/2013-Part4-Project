#include "Path.h"

#include <stdlib.h>
#include <iostream>

Path::Path() : _flow(0.0), _prevFlow(0.0), _currCost(0.0){ 
	_it = _links.begin();
};

Path::~Path(){

};

void Path::setPrevFlow(FPType flow){
	_prevFlow = flow;
};

void Path::setFlow(FPType flow){
	_flow = flow;
};

void Path::setCurrCost(FPType cost){
	_currCost = cost;
};

void Path::addLinkToPath(StarLink *link){
	_links.push_front(link);
};
		
// getters
FPType Path::getFlow() const{
	return _flow;
};

FPType Path::getCurrCost() const{
	return _currCost;
};
		
// go through path
StarLink* Path::beginLink() const{
	_it = _links.begin();
	if (_it != _links.end()) return *_it;
	return NULL;
};

// if NULL is returned, the path finished
StarLink* Path::getNextLink() const{
	_it++;
	if (_it != _links.end()) return *_it;
	return NULL;
}; 

void Path::print(){
    FPType cost = 0;
	std::cout << "flow = " << _flow  << " prevFlow = " << _prevFlow << " cost = " << _currCost << std::endl;;
	for (StarLink *link = beginLink(); link != NULL; link = getNextLink()) {
		std::cout << "(" << link->getNodeFromIndex() << ", " << link->getFlow() << " " << link->getTime() << ") ";
        cost += link->getTime();
		//std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] " << link->getFlow() << ", " << link->getTime() << " ";
		//std::cout << link->getNodeFromIndex() << " " << link->getNodeToIndex() << std::endl;
		//std::cout << link->getIndex() << " ";
	}//*/
	std::cout << cost << std::endl;
};

FPType Path::getPrevFlow() const{
	return _prevFlow;
};

bool Path::isEmpty() const{
	return  _links.empty();
};

int Path::size() const{
	return _links.size();
};
