#include "StarNode.h"

StarNode::StarNode(int id, bool isZone) : _id(id), _index(-1), _isZone(isZone){

};

StarNode::~StarNode(){

};

int StarNode::getID(){
	return _id;
};

bool StarNode::getIsZone(){
	return _isZone;
};

void StarNode::setIndex(int index){
	_index = index;
};

int StarNode::getIndex(){
	return _index;
};
