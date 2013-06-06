#include "PASManager.h"

#include <cassert>

PASManager::PASManager(FPType *originFlows, const ShortestPath &shPath) : originFlows_(originFlows), shPath_(shPath), listOfPas_(), curPAS_(-1) {

}; 

PASManager::~PASManager() {

}; 

// TODO
void PASManager::createNewPAS(const DAGraph &dag, int mergingNodeIndex) {

}; 

void PASManager::deletePAS(int index) {
	assert(index >= 0 && index < listOfPas_.size());
	listOfPas_.erase(listOfPas_.begin() + index);
}; 

PAS* PASManager::beginPAS()const  {
	 curPAS_ = 0;
	 if (listOfPas_.empty()) return NULL;
	 return listOfPas_[0];
}; 

PAS* PASManager::getNextPAS()const  {
	++curPAS_;
	if (curPAS_ == listOfPas_.size()) return NULL;
	 return listOfPas_[curPAS_];
}; 

PAS* PASManager::getPASByIndex(int index)const  {
	assert(index >= 0 && index < listOfPas_.size());
	return listOfPas_[index];
}; 

int PASManager::getNbPAS()const  {
	return listOfPas_.size();
}; 

void PASManager::print()const  {
	int nbPAS = listOfPas_.size();
	for(int i = 0; i < nbPAS; ++i){
		listOfPas_[i]->print();
	}
}; 

