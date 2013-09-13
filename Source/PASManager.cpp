#include "PASManager.h"
#include "DAGraphTapas.h"

#include <cassert>
#include <list>
#include <math.h>

//FPType PASManager::RGAP0_ = 0.0;

PASManager::PASManager(const ShortestPath &shPath, FPType dirTol, int nbNodes, FPType mu, FPType v) : shPath_(shPath), listOfPas_(), dirTol_(dirTol), nbNodes_(nbNodes), mu_(mu), v_(v), setOfNodes_() {
	curPAS_ = listOfPas_.begin();
	srand (time(NULL));
}; 

PASManager::~PASManager() {
	for (std::list<PAS*>::iterator it = listOfPas_.begin(); it != listOfPas_.end(); ++it){
		delete *it;
	}
}; 

//void PASManager::setRGAP0(FPType value){
	//assert(value >= 0.0);
	//std::cout << "RGAP0_ = " << value << std::endl;
	//RGAP0_ = 10 * value;
//};

// This method must check if there is PAS whose segments end with merging links
PAS* PASManager::pasExist(StarLink* cheapLink, StarLink* expLink){
	//std::cout << "cheapLink = " << cheapLink << " expLink = " << expLink << std::endl;
	assert(cheapLink != NULL && expLink != NULL);
	//std::cout << "cheap link = " << cheapLink->getIndex() << " expLink = " << expLink->getIndex() << std::endl;
	for (PAS* pas = beginPAS(); pas != NULL; pas = getNextPAS()){
		pas->recalcPASCosts();
		if (pas->getLastCheapLink() == cheapLink && pas->getLastExpLink() == expLink) {
			return pas;
		}
	}
	return NULL;
}

// TODO: for now just go through all links and check explicitely if nodeIndex belongs to it
bool PASManager::nodeBelongsToShPath(int nodeIndex, int mergingNodeIndex){
	/*StarLink *link = shPath_.getInComeLink(mergingNodeIndex);
	int nextDest = link->getNodeFromIndex();
	bool tmp = false;
	while (true) {
		//std::cout << "now checking nextDest = " << nextDest << std::endl;
		if (nextDest == nodeIndex) {
			//std::cout << std::endl;
		//	std::cout << "**********************Found**************" << std::endl;
			tmp = true;
			break;
		}
		link = shPath_.getInComeLink(nextDest);
		if (link == NULL) { tmp = false; break;}
		nextDest = link->getNodeFromIndex();
		//std::cout << "next to check nextDest = " << nextDest << std::endl;
		//std::cout << link->getIndex() << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] " << std::endl;
	}
	//std::cout << std::endl;
	//return false;
	std::set<int>::iterator kt = setOfNodes_.find(nodeIndex);
	bool tmp2 = kt != setOfNodes_.end();
	if (tmp2) std::cout << "AHA: " << *kt << std::endl;
	if (tmp2 != tmp) {
		std::cout << "tmp = " << tmp << " tmp2 = " << tmp2 << std::endl;
		for (std::set<int>::iterator it = setOfNodes_.begin(); it != setOfNodes_.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "nodeIndex = " << nodeIndex << " mergingNodeIndex = " << mergingNodeIndex << " shortest path: " << std::endl;
	shPath_.printPath(mergingNodeIndex);
	}
	assert (tmp2 == tmp);*/
	return (setOfNodes_.find(nodeIndex) != setOfNodes_.end());
};

// Backtrack expensive segment from bfs-tree
void PASManager::createExpSegment(PAS *pas, const std::vector<StarLink*> &checkedLinks, int divergeNode, int mergingNodeIndex, DAGraphTapas *dag){
	assert(divergeNode >= 0 && divergeNode < checkedLinks.size() && mergingNodeIndex >= 0 && mergingNodeIndex < checkedLinks.size());
	int start = divergeNode;
	StarLink* link = NULL;
	while (start != mergingNodeIndex){
		link = checkedLinks[start];
		//std::cout << "link " << link->getIndex() << " has oFlow = " << dag->getOriginFlow(link->getIndex()) << std::endl;
		pas->pushBackToExp(link);
		start = link->getNodeToIndex();
	}
};

// Build cheap segement by starting from merging index and stop when divergeNode or origin is reached
void PASManager::createCheapSegment(PAS *pas, int divergeNode, int mergingNodeIndex){
	assert(divergeNode >= 0 && mergingNodeIndex >= 0 );
	StarLink *link = shPath_.getInComeLink(mergingNodeIndex);
	int nextDest = link->getNodeFromIndex();
	//std::cout << ">>>>>>>>>>>>>>>>>>>Cheap links: ";
	while (link != NULL) {
		pas->pushFrontToCheap(link);
		//std::cout << link->getIndex() << ": [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] ";
		
		nextDest = link->getNodeFromIndex();
		if (nextDest == divergeNode) break;
		link = shPath_.getInComeLink(nextDest);
	}
	//std::cout << std::endl;
};

//additional structure to ensure fast access to shortest path - at the moment it does not make a difference
void PASManager::prepareShPathStructure(int mergingNodeIndex){
 // for now does nothing
 	setOfNodes_.clear();
 	StarLink *link = shPath_.getInComeLink(mergingNodeIndex);
	int nextDest = link->getNodeFromIndex();
	while (true) {
		//std::cout << "now checking nextDest = " << nextDest << std::endl;
		setOfNodes_.insert(std::make_pair<int, int>(nextDest, nextDest));
		link = shPath_.getInComeLink(nextDest);
		if (link == NULL) break;
		nextDest = link->getNodeFromIndex();
		//std::cout << "next to check nextDest = " << nextDest << std::endl;
		//std::cout << link->getIndex() << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] " << std::endl;
	}
};

PAS* PASManager::createPAS(DAGraphTapas *dag, StarLink *expLink, int mergingNodeIndex, bool (*checkPtr)(FPType originFlow, FPType thr)){
	//std::cout << "Creating new PAS" << std::endl;
	//dag->print();
	// data for BFS
	std::list<std::pair<int, StarLink*> > bfsQueue;
	bfsQueue.push_back(std::make_pair(expLink->getNodeFromIndex(), expLink));
	std::vector<int> nodeState(nbNodes_, -1); // -1 - node was not investigated
	std::vector<StarLink*> checkedLinks(nbNodes_);
	for (int i = 0; i < nbNodes_; ++i)
		checkedLinks[i] = NULL;
	
	//std::cout << "PAS index = " << listOfPas_.size() << std::endl;
	PAS* pas = new PAS(dag->getZeroFlow(), dirTol_); 
	
	// here the most interesting part - creation of segments, BFS 
	prepareShPathStructure(mergingNodeIndex);
	std::list<StarLink*> inLinks;
	StarLink* link = NULL;
	int divergeNode = -1;
	FPType thr = v_ * dag->getOriginFlow(expLink->getIndex());
	while (true) {
		// pop the first element from queue for investigation
		assert(!bfsQueue.empty());
		//if (bfsQueue.empty()) break;
		std::pair<int, StarLink*> firstInQueue(bfsQueue.front());
	
		// copy poped element to checkedLinks
		//std::cout << "link = " << (firstInQueue.second)->getIndex() << " [" << (firstInQueue.second)->getNodeFromIndex() << " ," << (firstInQueue.second)->getNodeToIndex() << "]" << std::endl;
		checkedLinks[firstInQueue.first] = firstInQueue.second;
		bfsQueue.pop_front();
			
		// check if we can stop
		if (nodeBelongsToShPath(firstInQueue.first, mergingNodeIndex)) {
			divergeNode = firstInQueue.first;
			break;
		}
		
		// add new nodes from used links to the queue 
		dag->getInLinks(firstInQueue.first, inLinks);
		//bool isInside = false;
		for (std::list<StarLink*>::iterator it = inLinks.begin(); it != inLinks.end(); ++it){
     			link = *it;
     			FPType originFlow = dag->getOriginFlow(link->getIndex());
     			if (checkPtr(originFlow, thr)) { //(dag->getOriginFlow(link->getIndex()) >= thr){
	     			//std::cout << "checking link = " << link->getIndex() << std::endl;
	     			int nodeFromIndex = link->getNodeFromIndex();
	     			if (originFlow > dag->getZeroFlow() && nodeState[nodeFromIndex] == -1) {
	     				//isInside = true;
	     					//std::cout << "link was added " << link->getIndex() << " [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "]" << std::endl;
					bfsQueue.push_back(std::make_pair(nodeFromIndex, link));
					// update  node state
					
					nodeState[nodeFromIndex] = 1; // node is in the queue
					// copy poped element to checkedLinks
					checkedLinks[nodeFromIndex] = link;
					
					// check if we can stop
					if (nodeBelongsToShPath(nodeFromIndex, mergingNodeIndex)) { // this check is redundant. TODO: think how to make it better
						divergeNode = nodeFromIndex;
						break;
					}
				}
			}
		}
			
		//if (!isInside) {
		//	return NULL;
		//}
		// update  node state
		nodeState[firstInQueue.first] = 0; // node is visited
	
	}
		
	// create exp segemnt
 	createExpSegment(pas, checkedLinks, divergeNode, mergingNodeIndex, dag);
		
	// create cheap segment
	assert(divergeNode != -1);
	//std::cout << "--------------------divergeNode = " << divergeNode << std::endl;
	createCheapSegment(pas, divergeNode, mergingNodeIndex);
		
	// once cheap segment is created we need to add cheap links to the bush
	pas->addCheapLinksToBush(dag);
		
	pas->addOrigin(dag);
	//std::cout << "++++++++++++++++++++++++++++++++++" << std::endl;
	//pas->print();
	//std::cout << "++++++++++++++++++++++++++++++++++" << std::endl;
	listOfPas_.push_back(pas);

	//std::cout << "PAS after creation:--------------------------" << std::endl; 
	//pas->print();
	return pas;

};

FPType PASManager::calculateReducedCost(StarLink *expLink){
	return shPath_.getCost(expLink->getNodeFromIndex()) + expLink->getTime() - shPath_.getCost(expLink->getNodeToIndex());
};

FPType PASManager::calcThreshold(int iter){
	return 10 * pow(10, -iter); //dirTol_; //RGAP0_ * pow(10, -iter);
}; 

bool checkThreshold(FPType originFlow, FPType thr) {return (originFlow >= thr);};
		
bool checkThresholdFake(FPType originFlow, FPType thr) {return true;};
		
void PASManager::createNewPAS(DAGraphTapas *dag, StarLink *expLink, int mergingNodeIndex, int iter) {
	PAS* foundPAS = pasExist(shPath_.getInComeLink(mergingNodeIndex), expLink);
	bool isEffective = false;
	FPType reducedCost = calculateReducedCost(expLink);
	int expIndex = expLink->getIndex();
	bool (*fncPtr)(FPType originFlow, FPType thr);
	FPType redVal = mu_ * reducedCost;
	//std::cout << "reducedCost = " << reducedCost << " calcThreshold(iter) = " << calcThreshold(iter) << std::endl;
	if (foundPAS != NULL) {
		//std::cout << "PAS exists -----------------" << std::endl;
		if (foundPAS->addOrigin(dag) == true) { // dags are stored in the set, so if this gad is already
								// there, it won't be added	
			foundPAS->addCheapLinksToBush(dag);
		}
		isEffective = foundPAS->checkIfEffective(redVal, v_, expIndex, dag);
		//std::cout << "PAS exists" << std::endl;
		//std::cout << "Existing PAS: --------------------------------------------" << std::endl;
		//foundPAS->print();
		//std::cout << "--------------------------------------------" << std::endl;
	} else { //wew need to create a new PAS and add it to listOfPas_
		fncPtr = &checkThresholdFake;	
		PAS* pasTmp = createPAS(dag, expLink, mergingNodeIndex, fncPtr);
		isEffective = pasTmp->checkIfEffective(redVal, v_, expIndex, dag); 
	}
		
	
	if (reducedCost > calcThreshold(iter) && !isEffective) { // checks if link expLink is a problematic OLC
		//std::cout << "Effective PAS is required" << std::endl;
		fncPtr = &checkThreshold;
		createPAS(dag, expLink, mergingNodeIndex, fncPtr); // return value is ignored
		/*if (pas == NULL) {
			std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Cannot find flow effective PAS" << std::endl;
		} else {
			//pas->print();
		}*/
	}
}; 


void PASManager::deleteUnusedPASAndMoveFlow(int iter){
	PAS* pas = NULL;
	for (std::list<PAS*>::iterator it = listOfPas_.begin(); it != listOfPas_.end(); ++it){
		pas = *it;
		if (pas->isUnused(iter)) {
			//std::cout << "PAS was deleted*****************************************************" << std::endl;
			//pas->print();
			//pas->moveFlow(iter);
			pas->deleteLinksFromBushes(); // sometimes links that should not be deleted are deleted because expensive and cheap segments might exchange
			delete *it;
			it = listOfPas_.erase(it);
			--it;
		} else {
			pas->moveFlow(iter);
		}
	}
}; 

PAS* PASManager::beginPAS() const {
	 curPAS_ = listOfPas_.begin();
	 if (curPAS_ == listOfPas_.end()) return NULL;
	 return *curPAS_;
}; 

PAS* PASManager::getNextPAS() const {
	++curPAS_;
	if (curPAS_ == listOfPas_.end()) return NULL;
	return *curPAS_;
}; 

PAS* PASManager::getRandomPAS() const{
	std::list<PAS*>::const_iterator it = listOfPas_.begin();
	int s = (rand() % listOfPas_.size());
	//std::cout << "s = " << s << " listOfPas_.size() = " << listOfPas_.size() << std::endl;
	for (int i = 0; i < s; ++i) ++it;
	assert( it != listOfPas_.end());
	//(*it)->print();
	return *it;
};
		
int PASManager::getNbPAS()const  {
	return listOfPas_.size();
}; 

void PASManager::print()const  {
	for(PAS* pas = beginPAS(); pas != NULL; pas = getNextPAS()){
		pas->print();
	}
}; 

