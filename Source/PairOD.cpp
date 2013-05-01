#include "PairOD.h"

#include <stdlib.h>
#include <iostream>
#include <cassert>

PairOD::PairOD(int id, FPType demand) : _destID(id), _index(-1), _demand(demand),  _odIndex(-1), _originIndex(-1){

};

PairOD::~PairOD(){

};

void PairOD::print(){
	std::cout << "odIndex = " << _odIndex << " destIndex = " << _index << " destID = " << _destID << " demand = " << _demand  << " _originIndex = " << _originIndex << std::endl;
};

int PairOD::getID() const{
	return _destID;
};

FPType PairOD::getDemand() const{
	return _demand;
};

int PairOD::getIndex() const{
	return _index;
};
	
void PairOD::setIndex(int index){
	_index = index;
};

int PairOD::getODIndex() const{
	return _odIndex;
};

void PairOD::setODIndex(int index){
	_odIndex = index;
};

void PairOD::setOriginIndex(int index){
	_originIndex = index;
};

int PairOD::getOriginIndex() const{
	return _originIndex;
};

