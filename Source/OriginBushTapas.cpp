#include "OriginBushTapas.h"

ShortestPath * OriginBushTapas::shPath_ = NULL;
PASManager * OriginBushTapas::pasManager_ = NULL;
		
OriginBushTapas::OriginBushTapas(int index, StarNetwork *net, ShortestPath *shPath, PASManager *pasManager) : OriginBush(index, net), dag_(NULL) {
	shPath_ = shPath;
	pasManager_ = pasManager;
};

OriginBushTapas::~OriginBushTapas(){

};
		
DAGraph* OriginBushTapas::createNewDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol){
	dag_ = new DAGraphTapas(net, mat, zeroFlow, dirTol, index, shPath_, pasManager_); 
	return dag_; 
};

void OriginBushTapas::updateSet(){
	dag_->removeCyclicFlows();	
};

bool OriginBushTapas::improve(){
	return false;
};

// does nothing in case of TAPAS
void OriginBushTapas::removeUnusedLinks(){

};



