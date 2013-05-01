#include "DAGraphLUCE.h"

#include <limits>
#include <math.h>

DAGraphLUCE::DAGraphLUCE(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex) : DAGraph(net, mat, zeroFlow, dirTol, originIndex),
				nbNodes_(net->getNbNodes()), nbLinks_(net->getNbLinks()), derivatives_(net->getNbLinks(), 0.0), flowPortions_(net->getNbLinks(), 0.0), 
				nodeFlows_(net->getNbNodes(), 0.0) {
	std::cout << "nbNodes = " << net->getNbNodes() << std::endl;
	std::cout << "NodeFlow size = " << nodeFlows_.size() << std::endl;
}; 

DAGraphLUCE::~DAGraphLUCE() {

}; 

bool DAGraphLUCE::moveFlow() {
	std::cout << "Moving flow" << std::endl;
	std::vector<FPType> C(nbNodes_, 0.0);
	std::vector<FPType> G(nbNodes_, 0.0);
	computeAvCosts(C, G);
	
	std::vector<FPType> e_links(nbLinks_, 0.0);
	computeDirection(e_links, C, G);
	
	FPType stepSize = computeStepSize(e_links);
	
	// perform flow move
	assignNewFlow(stepSize, e_links);
	return false;
}; 

void DAGraphLUCE::computeAvCosts(std::vector<FPType> &C, std::vector<FPType> &G){
	
	std::cout << "Computing average costs" << std::endl;
	StarLink* link = NULL;
	FPType flowPor = 0.0;
	int linkIndex = -1;
	int nodeToIndex = -1;
	for (int i = beginDescPass(); i != -1; i = getNextDescPass()){
		if (getDemand(i) == 0.0) { // is not a destination node: equality is used here because all nodes demands that are not destinations
						// are set to 0.0 -> we have the guarantee that it will evaluate to true 
			if (nodeFlows_[i] > 0.0) {
				const std::list<StarLink*> &outLinks = getOutLinks(i);
				for (std::list<StarLink*>::const_iterator it = outLinks.begin(); it != outLinks.end(); ++it){
					
					linkIndex = link->getIndex();
					nodeToIndex = link->getNodeToIndex();
					flowPor = flowPortions_[linkIndex];
					C[i] +=  flowPor * (link->getTime() + C[nodeToIndex]);
					G[i] += flowPor * flowPor * (derivatives_[linkIndex] + G[nodeToIndex]);
				}
			} else {
				FPType minVal = std::numeric_limits<FPType>::infinity();
				FPType val = 0.0;
				FPType sum1 = 0.0;
				FPType sum2 = 0.0;
				const std::list<StarLink*> &outLinks = getOutLinks(i);
				for (std::list<StarLink*>::const_iterator it = outLinks.begin(); it != outLinks.end(); ++it){
					link = *it;
					nodeToIndex = link->getNodeToIndex();
					val = link->getTime() + C[nodeToIndex];
					if (val < minVal) minVal = val;
					sum1 += val * (derivatives_[linkIndex] + G[nodeToIndex]);
					sum2 += val;
				}
				C[i] = val;
				G[i] = sum1 / sum2;
			}
		}
	}
};

void DAGraphLUCE::computeDirection(std::vector<FPType> &e_links, const std::vector<FPType> &C, const std::vector<FPType> &G){
	
	std::cout << "Computing direction of descent" << std::endl;
	
	// load demands
	FPType demand = 0.0;
	std::vector<FPType> e_nodes(nbNodes_, 0.0);
	std::vector<FPType> V(nbNodes_, 0.0);
	
	for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
		demand += getDemand(i);
	}
	e_nodes[getOriginIndex()] = demand; // TODO: maybe? I am not sure about this
	
	bool lambda = false;
	FPType sum1 = 0.0;
	FPType sum2 = 0.0;
	FPType tmp = 0.0;
	StarLink *link = NULL;
	int nodeToIndex = -1;
	int linkIndex = -1;
	std::list<StarLink*> outLinks;
	for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
		if (demand == 0.0) { // if it is not a destination node
			outLinks = getOutLinksCopy(i);
			sum1 = 0.0;
			sum2 = 0.0;
			// delete links without flow
			for (std::list<StarLink*>::iterator it = outLinks.begin(); it != outLinks.end(); ++it){
				link = *it;
				if (fabs(link->getFlow()) < getZeroFlow()) {
					it = outLinks.erase(it); 
				} else {
					nodeToIndex = link->getNodeToIndex();
					linkIndex = link->getIndex();
					tmp = derivatives_[linkIndex] + G[nodeToIndex];
					sum1 += (link->getTime() +  C[nodeToIndex]) / tmp - e_nodes[i] * flowPortions_[linkIndex];
					sum2 += 1.0 / tmp;
				}
			}
			
			lambda = true;
			while (lambda) {
				lambda = false;
				V[i] = (e_nodes[i] + sum1) / sum2;
				for (std::list<StarLink*>::iterator it = outLinks.begin(); it != outLinks.end(); ++it){
					link = *it;
					linkIndex = link->getIndex();
					nodeToIndex = link->getNodeToIndex();
					tmp = derivatives_[linkIndex] + G[nodeToIndex];
					e_links[linkIndex] = V[i] / tmp - (link->getTime() + C[nodeToIndex]) / tmp + e_nodes[i] * flowPortions_[linkIndex];
					if (e_links[linkIndex] < 0.0) {
						e_links[linkIndex] = 0.0;
						it = outLinks.erase(it); 
						lambda = true;
					} 
				}
			}
			
			for (std::list<StarLink*>::iterator it = outLinks.begin(); it != outLinks.end(); ++it){
				link = *it;
				e_nodes[link->getNodeToIndex()] += e_links[link->getIndex()];
			}	
		}
	}
};

FPType DAGraphLUCE::computeStepSize(const std::vector<FPType> &e_links){
	
	std::cout << "Computing step size" << std::endl;
	FPType alpha = 1.0;
	// TODO: maybe include condition for the first iteration
	FPType sum = 0.0;
	FPType sum2 = 0.0;
	FPType tmp = 0.0;
	LinkFnc *fnc = NULL;
	StarLink *link = NULL;
	int linkIndex = -1;
	for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
		const std::list<StarLink*> &outLinks = getOutLinks(i);
		for (std::list<StarLink*>::const_iterator it = outLinks.begin(); it != outLinks.end(); ++it){
			link = *it;
			fnc = link->getLinkFnc();
			linkIndex = link->getIndex();
			tmp = e_links[linkIndex] - getOriginFlow(linkIndex);
			sum += fnc->evaluate(link->getFlow() + alpha * tmp) * tmp;
			sum2 += link->getTime() * tmp;
		}
	}
	if (sum >= 0.0) {
		if (sum2 >= 0.0) {
			alpha = 0.0;
		} else {
			alpha = 1.0 / (1 - sum / sum2);
		}
	}
	return alpha;
};

void DAGraphLUCE::assignNewFlow(FPType stepSize, const std::vector<FPType> &e_links){
	std::cout << "Assigning new flow" << std::endl;
	StarLink *link = NULL;
	int linkIndex = -1;
	FPType dFlow = 0.0;
	for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
		const std::list<StarLink*> &outLinks = getOutLinks(i);
		for (std::list<StarLink*>::const_iterator it = outLinks.begin(); it != outLinks.end(); ++it){
			link = *it;
			linkIndex = link->getIndex();
			dFlow = stepSize * (e_links[linkIndex] - getOriginFlow(linkIndex));
			if (fabs(dFlow) >= getZeroFlow()) {
				addOriginFlow(linkIndex, dFlow);
				link->addFlow(dFlow);
			}
		}
	}
};
		
void DAGraphLUCE::update(){
	std::cout << "Updating" << std::endl;
	StarNetwork* net = getNet();
	std::cout << "2" << std::endl;
	FPType nodeFlow = 0.0;
	FPType linkFlow = 0.0;
	std::cout << "NodeFlow size = " << nodeFlows_.size() << std::endl;
	std::cout << " der size = " <<  derivatives_.size() << std::endl;
	for(StarNode *node = net->beginNode(); node != NULL; node = net->getNextNode()) {
		nodeFlow = 0.0;
		std::cout << "Node = " << node->getIndex();
		for(StarLink *link = net->beginLink(); link != NULL; link = net->getNextLink()) {
			std::cout << "link = " << link->getIndex() << std::endl;
			linkFlow = link->getFlow();
			nodeFlow += linkFlow;
			link->updateTime();
			derivatives_[link->getIndex()] = (link->getLinkFnc())->evaluateDerivative(linkFlow);
			std::cout << "der = " << derivatives_[link->getIndex()] << std::endl;
		}
		nodeFlows_[node->getIndex()] = nodeFlow;
		std::cout << "nodeFlow = " << nodeFlows_[node->getIndex()] << std::endl;
	}
	calcFlowPortions();
};
		
void DAGraphLUCE::calcFlowPortions(){
	std::cout << "Calculating flow portions" << std::endl;
	StarNetwork* net = getNet();
	FPType nodeFlow = 0.0;
	int index = -1;
	for(StarLink *link = net->beginOnlyLink(); link != NULL; link = net->getNextOnlyLink()) {
		nodeFlow =  nodeFlows_[link->getNodeFromIndex()];
		index = link->getIndex();
		if (nodeFlow > 0.0) {
			flowPortions_[index] = getOriginFlow(index) / nodeFlow;
		} else {
			flowPortions_[index] = 0.0;
		}
	}
};
