#include "DAGraphNode.h"

#include <cassert>

DAGraphNode::DAGraphNode(int index, FPType demand) : minLink_(NULL), maxLink_(NULL), demand_(demand), nodeIndex_(index), pre_(0), post_(0), minDist_(0.0), 
							maxDist_(0.0) {

};

DAGraphNode::~DAGraphNode(){};

int DAGraphNode::getIndex() const {
	return nodeIndex_;
};

int DAGraphNode::getPre() const {
	return pre_;
};

int DAGraphNode::getPost() const {
	return post_;
};

FPType DAGraphNode::getMinDist() const {
	return minDist_;
};

FPType DAGraphNode::getMaxDist() const {
	return maxDist_;
};
		
void DAGraphNode::setPre(int pre) {
	pre_ = pre;
};

void DAGraphNode::setPost(int post) { 
	post_ = post; 
};

void DAGraphNode::setMinDist(FPType minDist){ 
	minDist_ = minDist;
};

void DAGraphNode::setMaxDist(FPType maxDist){ 
	maxDist_ = maxDist;
};

FPType DAGraphNode::getDemand() const{
	return demand_;
};

void DAGraphNode::setMinLink(StarLink* link){
	minLink_ = link;
};

void DAGraphNode::setMaxLink(StarLink* link){
	maxLink_ = link;
};
		
StarLink* DAGraphNode::getMinLink() const{
	return minLink_;
};

StarLink* DAGraphNode::getMaxLink() const{
	return maxLink_;
};
