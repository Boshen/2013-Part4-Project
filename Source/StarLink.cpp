#include "StarLink.h"

#include <sstream>

StarLink::StarLink(int nodeFrom, int nodeTo, LinkFnc *fnc) : _index(-1),  _nodeFrom(nodeFrom), _nodeTo(nodeTo) ,
								_nodeFromIndex(-1), _nodeToIndex(-1), _flow(0.0), _fnc(fnc){
								//_der(0.0){
	updateTime();
};

StarLink::~StarLink(){
	delete _fnc;
	_fnc = NULL;
};

int StarLink::getNodeFrom() const{
	return _nodeFrom;
};

int StarLink::getNodeTo() const{
	return _nodeTo;
};

LinkFnc* StarLink::getLinkFnc() const{
	return _fnc;
};

FPType StarLink::getFlow() const{
	return _flow;
};

void StarLink::setFlow(FPType flow){
	_flow = flow;
};

int StarLink::getIndex() const{
	return _index;
};

void StarLink::setIndex(int index){
	_index = index;
};

int StarLink::getNodeFromIndex() const{
	return _nodeFromIndex;
};

int StarLink::getNodeToIndex() const{
	return _nodeToIndex;
};

FPType StarLink::getTime() const{
	return _time;
};
		
void StarLink::setNodeToIndex(int index){
	_nodeToIndex = index;
};

void StarLink::setNodeFromIndex(int index){
	_nodeFromIndex = index;
};

void StarLink::addFlow(FPType flow){
	_flow += flow;
};

void StarLink::updateTime(){
	_time = _fnc->evaluate(_flow);
	//_der = _fnc->evaluateDerivative(_flow);
};

/*FPType StarLink::getDerivative() const{
	return _der;
};*/

void StarLink::setFlowToZero(){
	_flow = 0.0;
};

std::string StarLink::toString() const{
	std::stringstream ss;
	ss << "Link: " << _index << " [" << _nodeFromIndex << ", " << _nodeToIndex << "]";
	return ss.str();
};
