#include "Origin.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>

Origin::Origin(int id) : _id(id), _index(-1), _isEmpty(true),  _nbDest(0) {
	_destList.push_back(NULL);
	_it = _destList.begin();
};

Origin::~Origin(){
	PairOD *dest = beginDest();
	while (dest != NULL) {
		delete dest;
		dest = getNextDest(); 
	}
};

void Origin::addDestination(PairOD *dest){
	assert(dest != NULL);
	_isEmpty = false;
	_destList.push_front(dest);
	//dest->setOriginIndex(_index);
	_nbDest++;
};
	
PairOD* Origin::beginDest(){
	_it = _destList.begin();
	return *_it;
};

/** Caution: no check is performed if we are out of list. 
 *  Always check if NULL-pointer was return!
  */
PairOD* Origin::getNextDest(){
	_it++;
	return *_it;
};

int Origin::getID() const{
	return _id;
};

int Origin::getIndex() const{
	return _index;
};

bool Origin::isEmpty() const{
	return _isEmpty;
};

void Origin::setIndex(int index){
	_index = index;
};

int Origin::getNbDest() const{
	return _nbDest;
};
