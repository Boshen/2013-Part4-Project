#include "PairOD.h"

#include <stdlib.h>
#include <iostream>
#include <cassert>

//_destID(id), int originIndex, , _originIndex(originIndex)
PairOD::PairOD(int index, FPType demand) : _index(index), _demand(demand),  _odIndex(-1) {

};

PairOD::~PairOD(){

};

void PairOD::print(){
	std::cout << "odIndex = " << _odIndex << " destIndex = " << _index << " demand = " << _demand  << std::endl; //" _originIndex = " << _originIndex 
};

//int PairOD::getID() const{
//	return _destID;
//};

FPType PairOD::getDemand() const{
	return _demand;
};

int PairOD::getIndex() const{
	return _index;
};
	
//void PairOD::setIndex(int index){
//	_index = index;
//};

int PairOD::getODIndex() const{
	return _odIndex;
};

void PairOD::setODIndex(int index){
	_odIndex = index;
};

//void PairOD::setOriginIndex(int index){
//	_originIndex = index;
//};

//int PairOD::getOriginIndex() const{
//	return _originIndex;
//};

