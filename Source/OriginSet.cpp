#include "OriginSet.h"
#include "OriginBushLUCE.h"
#include "OriginBushB.h"

OriginSet::OriginSet(ODMatrix *mat, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType zeroFlow, FPType dirTol, bool useLUCE, bool useMultiStep) : net_(net), conv_(conv), currBushIndex_(-1) {
	nbOrigins_ = mat->getNbOrigins();
	bushes_ = new OriginBush*[nbOrigins_];
	indexes_ = new int[net->getNbNodes()];
	for (int j = 0;  j < net->getNbNodes(); j++) {
		indexes_[j] = -1;
	}
	int i = 0;
	for (Origin* origin = mat->beginOrigin(); origin != NULL; origin = mat->getNextOrigin()) {
		if (useLUCE) {
			bushes_[i] = new OriginBushLUCE(origin->getIndex(), net);
		} else {
			bushes_[i] = new OriginBushB(origin->getIndex(), net, useMultiStep);
		}
		//std::cout << " i = " << i << std::endl;
		bushes_[i]->allocateDAG(origin->getIndex(), net, mat, zeroFlow, dirTol);
		//bushes_[i]->print();
		indexes_[origin->getIndex()] = i; 
		i++;
	}
	aon_ = new AONAssignment(mat, shPath);
	nbLinks_ = net->getNbLinks();
};

OriginSet::~OriginSet(){
	for(int i = 0; i < nbOrigins_; i++){
		delete bushes_[i];
	}
	delete[] bushes_;
	delete aon_;
	delete[] indexes_;
};
		
void OriginSet::initialise(){
	
	OriginBush::updateLinkCosts();
	std::cout << "AFTER updating network. Flow is set to zero everywhere" << std::endl;
	std::cout << "AON" << std::endl;
	aon_->executeForOriginBasedAlgo(this, OriginBush::getNet());
	std::cout << "AON executed" << std::endl;
	loadOriginFlows();
	
};

bool OriginSet::isConverged(){
	bool val = conv_->isConverged();
	//std::cout << "***********************************************RGAP = " << conv_->getGap() << std::endl;
	return val;
};

FPType OriginSet::getGapVal() const{
	return conv_->getGap();
};
		
OriginBush* OriginSet::beginSet(){
	currBushIndex_ = 0;
	return bushes_[currBushIndex_];
};

OriginBush* OriginSet::getNextSet(){
	currBushIndex_++;
	if (currBushIndex_ == nbOrigins_) return NULL;
	return bushes_[currBushIndex_];
};

void OriginSet::initialiseItself(StarLink* link, PairOD *dest){
	int originIndex = dest->getOriginIndex();
	//std::cout << "inside initItself: originIndex = " << originIndex << " indexes_[originIndex] = " << indexes_[originIndex] << std::endl; 
	//bushes_[indexes_[originIndex]]->print();
	//std::cout << "print done" << std::endl; 
	bushes_[indexes_[originIndex]]->addLink(link);
	//std::cout << "addLink done : " << link->getIndex() << "---------------------------------------------" << std::endl; 

	if (dest->getODIndex() != -1) bushes_[indexes_[originIndex]]->addOriginFlow(link->getIndex(), dest->getDemand());
	//bushes_[indexes_[originIndex]]->addLink(net_->getLink(1));
	//bushes_[indexes_[originIndex]]->addOriginFlow(1, dest->getDemand() / 3.0);
	//bushes_[indexes_[originIndex]]->addLink(net_->getLink(2));
	//bushes_[indexes_[originIndex]]->addOriginFlow(2, dest->getDemand() / 3.0);
	//std::cout << "yohoo" << std::endl; 
};

void OriginSet::loadOriginFlows(){
	FPType flows[nbLinks_];
	for (int i = 0; i < nbLinks_; i++) {
		flows[i] = 0.0;
	}
	for (OriginBush* bush = beginSet(); bush != NULL; bush = getNextSet()){
		for (int i = 0; i < nbLinks_; i++) {
			flows[i] += bush->getOriginFlow(i);
		}
	}
	StarLink *link = NULL;
	for (int i = 0; i < nbLinks_; i++) {
		link = net_->getLink(i);
		link->setFlow(flows[i]);
	}
	OriginBush::updateLinkCosts();
};

void OriginSet::print(){
	for (OriginBush* bush = beginSet(); bush != NULL; bush = getNextSet()){
		bush->print();
	}
};

void OriginSet::printNet(){
	net_->print();
};

void OriginSet::printTotalOriginFlows(){
	FPType flows[nbLinks_];
	for (int i = 0; i < nbLinks_; i++) {
		flows[i] = 0.0;
	}
	for (OriginBush* bush = beginSet(); bush != NULL; bush = getNextSet()){
		for (int i = 0; i < nbLinks_; i++) {
			flows[i] += bush->getOriginFlow(i);
		}
	}
	for (int i = 0; i < nbLinks_; i++) {
		std::cout << flows[i] << " ";
	}
	std::cout << std::endl;
};
