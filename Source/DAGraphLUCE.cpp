#include "DAGraphLUCE.h"

#include <limits>
#include <math.h>
#include <cassert>

DAGraphLUCE::DAGraphLUCE(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex) : DAGraph(net, mat, zeroFlow, dirTol, originIndex),
													     nbNodes_(net->getNbNodes()), nbLinks_(net->getNbLinks()), derivatives_(net->getNbLinks(), 0.0), 
													     nodeFlowsInv_(net->getNbNodes(), 0.0), flowPortionsInv_(net->getNbLinks(), 0.0) { 
  // flowPortions_(net->getNbLinks(), 0.0), nodeFlows_(net->getNbNodes(), 0.0) {
	//std::cout << "nbNodes = " << net->getNbNodes() << std::endl;
	//std::cout << "NodeFlow size = " << nodeFlows_.size() << std::endl;
}; 

DAGraphLUCE::~DAGraphLUCE() {

}; 

bool DAGraphLUCE::moveFlow(int iter) {
	//std::cout << "Moving flow" << std::endl;
	std::vector<FPType> C(nbNodes_, 0.0);
	std::vector<FPType> G(nbNodes_, 0.0);
	computeAvCosts(C, G);
	
	std::vector<FPType> e_links(nbLinks_, 0.0);
	computeDirection(e_links, C, G);
	
	FPType stepSize = 1.0; 
	stepSize = computeStepSize(e_links); // if (iter == 1)
	
	// perform flow move
	assignNewFlow(stepSize, e_links);
	return false;
}; 

void DAGraphLUCE::computeAvCosts(std::vector<FPType> &C, std::vector<FPType> &G){

  // std::cout << "Computing average costs. C:" << std::endl;
  //print();
  StarLink* link = NULL;
  FPType flowPor = 0.0;
  int linkIndex = -1;
  int nodeFromIndex = -1;
  int i = beginAscPass();
  i = getNextAscPass(); // skip the origin
  for (; i != -1; i = getNextAscPass()){
    //std::cout << "i = " << i << " nodeFlowsInv_[i] = " << nodeFlowsInv_[i] << std::endl;
    if (nodeFlowsInv_[i] > 0.0) {
      //std::cout << "i = " << i << std::endl;
      std::list<StarLink*> inLinks;
      getInLinks(i, inLinks);
      assert(inLinks.size()); // if node flow is positive, it implies that there are out-going links!
      //std::cout << "outLinks size = " << outLinks.size() << std::endl;
      for (std::list<StarLink*>::iterator it = inLinks.begin(); it != inLinks.end(); ++it){
	link = *it;
	//std::cout << "link = " << link << std::endl;
	linkIndex = link->getIndex();
	nodeFromIndex = link->getNodeFromIndex();
	//std::cout << "linkIndex = " << linkIndex << " nodeToIndex = " << nodeToIndex << std::endl;
	flowPor = flowPortionsInv_[linkIndex];
	//std::cout << "flowPor = " << flowPor << std::endl;
	C[i] +=  flowPor * (link->getTime() + C[nodeFromIndex]);
	//std::cout << "C[i] = " << C[i] << std::endl;
	G[i] += flowPor * flowPor * (derivatives_[linkIndex] + G[nodeFromIndex]);
	if (G[i] != G[i]) std::cout << "Flow is positive G[i] = " << G[i] << " flowPor = " << flowPor << " der = " << derivatives_[linkIndex] << " G_prev = " <<  G[nodeFromIndex] << " from = " << nodeFromIndex << std::endl;

	//std::cout << "derivatives_[linkIndex] = " << derivatives_[linkIndex] << " G[nodeToIndex] = " << G[nodeToIndex] << "  G[i] = " << G[i] << std::endl;
      }
      //std::cout << "2" << std::endl;
    } else {
      // std::cout << "----------------" << std::endl;
     
      std::list<StarLink*> inLinks;
		    
      getOutLinks(i, inLinks);
      //std::cout << "outLinks size = " << outLinks.size() << std::endl;
      if (inLinks.size() == 0) {
	C[i] = 0.0;
	G[i] = 0.0;
	//if  (i == 856) std::cout  << "No income links, G is zero"<< std::endl;
      } else {
	FPType minVal = std::numeric_limits<FPType>::infinity();
	FPType val = 0.0;
	FPType sum1 = 0.0;
	FPType sum2 = 0.0;
	//	FPType sumPr = 0.0;	      
	for (std::list<StarLink*>::const_iterator it = inLinks.begin(); it != inLinks.end(); ++it){
	  link = *it;
	  linkIndex = link->getIndex();
	  nodeFromIndex = link->getNodeFromIndex();
	  val = link->getTime() + C[nodeFromIndex];
	  if (val < minVal) minVal = val;
	  //sumPr = sum1;
	  sum1 += val * (derivatives_[linkIndex] + G[nodeFromIndex]);
	  //link->getLinkFnc()->print();
	  //std::cout << "sum1 = " << sum1 << " val = " << val  << " linkIndex = " << linkIndex << " derivatives_[linkIndex] = " << derivatives_[linkIndex] << " G[nodeFromIndex] = " << G[nodeFromIndex] <<  " link->getTime() = " << link->getTime() <<  "  C[nodeFromIndex]; = " << C[nodeFromIndex] << std::endl;
	  //if (sum1 != sum1) std::cout << "sum1 = " << sum1 << " val = " << val  << " linkIndex = " << linkIndex << " derivatives_[linkIndex] = " << derivatives_[linkIndex] << " G[nodeFromIndex] = " << G[nodeFromIndex] <<  " link->getTime() = " << link->getTime() <<  "  C[nodeFromIndex]; = " << C[nodeFromIndex] << std::endl;
	  sum2 += val;
	}
	C[i] = minVal;
	if (sum2 == 0.0) {
	  G[i] = 0.0; // TODO: think about this case - zero derivative again
	} else {
	  G[i] = sum1 / sum2;
	}
	//if (i == 856) 
	if (G[i] != G[i]) {
	  std::cout << "Flow is zero G[i] = " << G[i] << " sum1 = " << sum1 << " sum2 = " << sum2 << std::endl;
	  assert(1 == 0);
	}
      }

      //std::cout << "4" << std::endl;
    }
    //std::cout << "i = " << i << " C[i] = " << C[i] << " G[i] = " << G[i] << std::endl;
   
    //std::cout << "going to the next i" << std::endl;
  }
  // std::cout << std::endl;//*/
	
    /*std::cout << "Computing average costs. C:" << std::endl;
	//print();
	StarLink* link = NULL;
	FPType flowPor = 0.0;
	int linkIndex = -1;
	int nodeToIndex = -1;
	for (int i = beginDescPass(); i != -1; i = getNextDescPass()){
		if (getDemand(i) == 0.0) { // is not a destination node: equality is used here because all nodes demands that are not destinations
						// are set to 0.0 -> we have the guarantee that it will evaluate to true 
		  //std::cout << "i = " << i << " nodeFlows_[i] = " << nodeFlows_[i] << std::endl;
		  if (nodeFlows_[i] > 0.0) {
		    //std::cout << "i = " << i << std::endl;
		    std::list<StarLink*> outLinks;
		    getOutLinks(i, outLinks);
		    assert(outLinks.size()); // if node flow is positive, it implies that there are out-going links!
		    //std::cout << "outLinks size = " << outLinks.size() << std::endl;
		    for (std::list<StarLink*>::iterator it = outLinks.begin(); it != outLinks.end(); ++it){
		      link = *it;
		      //std::cout << "link = " << link << std::endl;
		      linkIndex = link->getIndex();
		      nodeToIndex = link->getNodeToIndex();
		      //std::cout << "linkIndex = " << linkIndex << " nodeToIndex = " << nodeToIndex << std::endl;
		      flowPor = flowPortions_[linkIndex];
		      //std::cout << "flowPor = " << flowPor << std::endl;
		      C[i] +=  flowPor * (link->getTime() + C[nodeToIndex]);
		      //std::cout << "C[i] = " << C[i] << std::endl;
		      G[i] += flowPor * flowPor * (derivatives_[linkIndex] + G[nodeToIndex]);
		      //std::cout << "derivatives_[linkIndex] = " << derivatives_[linkIndex] << " G[nodeToIndex] = " << G[nodeToIndex] << "  G[i] = " << G[i] << std::endl;
		    }
		    //std::cout << "2" << std::endl;
		  } else {
		    std::cout << "----------------" << std::endl;
		    FPType minVal = std::numeric_limits<FPType>::infinity();
		    FPType val = 0.0;
		    FPType sum1 = 0.0;
		    FPType sum2 = 0.0;
		    std::list<StarLink*> outLinks;
		    
		    getOutLinks(i, outLinks);
		    //std::cout << "outLinks size = " << outLinks.size() << std::endl;
		    if (outLinks.size() == 0) {
		      C[i] = 0.0;
		      G[i] = 0.0;
		    } else {
		      
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

		    //std::cout << "4" << std::endl;
		  }
		  std::cout << "i = " << i << " C[i] = " << C[i] << " G[i] = " << G[i] << std::endl;
		}
		//std::cout << "going to the next i" << std::endl;
	}
	std::cout << std::endl;//*/
};

void DAGraphLUCE::computeDirection(std::vector<FPType> &e_links, const std::vector<FPType> &C, const std::vector<FPType> &G){
  // std::cout << "Computing direction of descent" << std::endl;
	
  StarNetwork *net = getNet();
  // load demands
  std::vector<FPType> e_nodes(nbNodes_, 0.0);
  std::vector<FPType> V(nbNodes_, 0.0);
	
  for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
    e_nodes[i] = getDemand(i);
  }
	
  bool lambda = false;
  FPType sum1 = 0.0;
  FPType sum2 = 0.0;
  FPType tmp = 0.0;
  StarLink *link = NULL;
  int nodeFromIndex = -1;
  int linkIndex = -1;
  std::list<StarLink*> inLinks;
  // bool linkAdded = false;
  int originIndex = getOriginIndex();
  for (int i =  beginDescPass(); i != -1; i = getNextDescPass()) {
    if (i != originIndex) { // if it is not a destination node
		  	
      inLinks = getInLinksCopy(i);
      //std::cout << "i = " << i << " nodeFlow = " << e_nodes[i] << std::endl;
      if (e_nodes[i] > getZeroFlow()) {
	//	std::cout << "i = " << i << " nodeFlow = " << e_nodes[i] << std::endl;
	assert(inLinks.size() > 0);		  	
	lambda = true;
			
	FPType sumFromNode = 0.0;
			
	while (lambda) {
	  lambda = false;
	  sum1 = 0.0;
	  sum2 = 0.0;
	  StarLink *link = NULL;
				
	  for (std::list<StarLink*>::const_iterator it = inLinks.begin(); it != inLinks.end(); ++it){
	    link = *it;
	    //std::cout << "link: " << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "]"  << " flow = " << link->getFlow() << std::endl;
	    nodeFromIndex = link->getNodeFromIndex();
	    linkIndex = link->getIndex();
	    tmp = derivatives_[linkIndex] + G[nodeFromIndex];
	    if (fabs(tmp) <= getZeroFlow()){
	      // TODO: think carefully about this case
	      tmp = 10.0;
	    }
	    sum1 += (link->getTime() +  C[nodeFromIndex]) / tmp - e_nodes[i] * flowPortionsInv_[linkIndex];
	    sum2 += 1.0 / tmp;
					   
	  }
			
	  V[i] = (e_nodes[i] + sum1) / sum2;
	  //std::cout << "V[i] = " << V[i] << " sum1 = " << sum1 << " sum2 = " << sum2 << std::endl;
	  sumFromNode = 0.0;
	  for (std::list<StarLink*>::iterator it = inLinks.begin(); it != inLinks.end(); ++it){
	    link = *it;
	    //std::cout << "link: " << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "]" << " flow = " << link->getFlow() << std::endl;
	    linkIndex = link->getIndex();
	    nodeFromIndex = link->getNodeFromIndex();
	    tmp = derivatives_[linkIndex] + G[nodeFromIndex];
	    if (fabs(tmp) <= getZeroFlow()){
	      // TODO: think carefully about this case
	      tmp = 10.0;
	    }  
	    
	    //if (linkIndex == 2289) 
	    //      std::cout << "tmp = " << tmp << " der = " << derivatives_[linkIndex] << " G = " << G[nodeFromIndex] << " from = " << nodeFromIndex << std::endl;
	      //std::cout << " tmp = " << tmp << " time = " << link->getTime() << " e_nodes[i] = " << e_nodes[i] << " flowPortions_[linkIndex] = " << flowPortionsInv_[linkIndex] << " V[i] / tmp = " << V[i] / tmp <<  "  (link->getTime() + C[nodeFromIndex]) / tmp = " <<  (link->getTime() + C[nodeFromIndex]) / tmp << " V[i] = " << V[i] << std::endl;
	    e_links[linkIndex] = V[i] / tmp - (link->getTime() + C[nodeFromIndex]) / tmp + e_nodes[i] * flowPortionsInv_[linkIndex];
	    //std::cout << "e_links[linkIndex] = " << e_links[linkIndex] << std::endl;
					
	    if (e_links[linkIndex] < 0.0) {
	      e_links[linkIndex] = 0.0;
	      it = inLinks.erase(it); 
	      --it;
	      lambda = true;
	    } 
					
	  }
	  sumFromNode = 0.0;
	  for (std::list<StarLink*>::iterator it = inLinks.begin(); it != inLinks.end(); ++it){
	    link = *it;
	    linkIndex = link->getIndex();
	    //std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << " e_links[linkIndex] = " << e_links[linkIndex] << std::endl;
	    sumFromNode += e_links[linkIndex];
	  }
				
				
	}
	//	std::cout << "********************************Flow entering node is: " << sumFromNode << std::endl;
			
	for (std::list<StarLink*>::iterator it = inLinks.begin(); it != inLinks.end(); ++it){
	  link = *it;
	  e_nodes[link->getNodeFromIndex()] += e_links[link->getIndex()];
	}
      } else {
	// reset to zero
	for (std::list<StarLink*>::iterator it = inLinks.begin(); it != inLinks.end(); ++it){
	  link = *it;
	  e_links[link->getIndex()] = 0.0;
	}
      }	
    }
  }
  //if (linkAdded) topologicalSort();
  // std::cout << "Direction of descent:" << std::endl;
  for(int i = 0; i < nbLinks_; ++i) {
    link = net->getLink(i);
    if (e_links[i] != e_links[i]) std::cout << "FOUND you = " << e_links[i] << " i = " << i << std::endl;
    //  if (e_links[i] > 0.0) std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] " << e_links[i] << " ";
  }
  // std::cout << std::endl;//*/

  /*std::cout << "Computing direction of descent" << std::endl;
	
	StarNetwork *net = getNet();
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
	bool linkAdded = false;
	for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
		if (getDemand(i) == 0.0) { // if it is not a destination node
		  	
		  	outLinks = getOutLinksCopy(i);
		  	std::cout << "i = " << i << " nodeFlow = " << e_nodes[i] << std::endl;
		  	if (e_nodes[i] > getZeroFlow()) {
			  	
			  	if (outLinks.size() == 0) { // special case: when link is not yet in the bush - but it has to be there in order to keep solution feasible
			  		net->beginNode(i);
			  		StarLink *minLink = NULL;
			  		FPType minDist = std::numeric_limits<FPType>::infinity();
			  		for (StarLink *link_tmp = net->beginLink(); link_tmp != NULL; link_tmp = net->getNextLink()) {
			  			if (link_tmp->getTime() < minDist) {
			  				minDist = link_tmp->getTime();
			  				minLink = link_tmp;
			  			}
			  		}
			  		assert(minLink != NULL);
			  		addLink(minLink);
			  		outLinks.push_back(minLink);
			  		linkAdded = true;
					std::cout << "******----------******** link was added ********----------********" << std::endl;
			  	}
				lambda = true;
			
				FPType sumFromNode = 0.0;
			
				while (lambda) {
					lambda = false;
					sum1 = 0.0;
					sum2 = 0.0;
					StarLink *link = NULL;
				
					for (std::list<StarLink*>::const_iterator it = outLinks.begin(); it != outLinks.end(); ++it){
					   link = *it;
					   //std::cout << "link: " << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "]"  << " flow = " << link->getFlow() << std::endl;
					   nodeToIndex = link->getNodeToIndex();
					   linkIndex = link->getIndex();
					   tmp = derivatives_[linkIndex] + G[nodeToIndex];
					   if (fabs(tmp) <= getZeroFlow()){
					     // TODO: think carefully about this case
					     tmp = 1.0;
					   }
					   sum1 += (link->getTime() +  C[nodeToIndex]) / tmp - e_nodes[i] * flowPortions_[linkIndex];
					   sum2 += 1.0 / tmp;
					   
					}
			
					V[i] = (e_nodes[i] + sum1) / sum2;
					//std::cout << "V[i] = " << V[i] << " sum1 = " << sum1 << " sum2 = " << sum2 << std::endl;
					sumFromNode = 0.0;
					for (std::list<StarLink*>::iterator it = outLinks.begin(); it != outLinks.end(); ++it){
						link = *it;
						//std::cout << "link: " << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "]" << " flow = " << link->getFlow() << std::endl;
						linkIndex = link->getIndex();
						nodeToIndex = link->getNodeToIndex();
						tmp = derivatives_[linkIndex] + G[nodeToIndex];
						if (fabs(tmp) <= getZeroFlow()){
						  // TODO: think carefully about this case
						  tmp = 1.0;
						}  
						//std::cout << " tmp = " << tmp << " time = " << link->getTime() << " e_nodes[i] = " << e_nodes[i] << " flowPortions_[linkIndex] = " << flowPortions_[linkIndex] << " V[i] / tmp = " << V[i] / tmp <<  "  (link->getTime() + C[nodeToIndex]) / tmp = " <<  (link->getTime() + C[nodeToIndex]) / tmp << " V[i] = " << V[i] << std::endl;
						e_links[linkIndex] = V[i] / tmp - (link->getTime() + C[nodeToIndex]) / tmp + e_nodes[i] * flowPortions_[linkIndex];
						//std::cout << "e_links[linkIndex] = " << e_links[linkIndex] << std::endl;
					
						if (e_links[linkIndex] < 0.0) {
						  e_links[linkIndex] = 0.0;
						  it = outLinks.erase(it); 
						  --it;
						  lambda = true;
						} 
					
					}
					sumFromNode = 0.0;
					for (std::list<StarLink*>::iterator it = outLinks.begin(); it != outLinks.end(); ++it){
					  link = *it;
					  linkIndex = link->getIndex();
					  std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << " e_links[linkIndex] = " << e_links[linkIndex] << std::endl;
					  sumFromNode += e_links[linkIndex];
					}
				
				
				}
				std::cout << "********************************Flow leaving node is: " << sumFromNode << std::endl;
			
				for (std::list<StarLink*>::iterator it = outLinks.begin(); it != outLinks.end(); ++it){
					link = *it;
					e_nodes[link->getNodeToIndex()] += e_links[link->getIndex()];
				}
			} else {
				// reset to zero
				for (std::list<StarLink*>::iterator it = outLinks.begin(); it != outLinks.end(); ++it){
					link = *it;
					e_links[link->getIndex()] = 0.0;
				}
			}	
		}
	}
	if (linkAdded) topologicalSort();
	std::cout << "Direction of descent:" << std::endl;
	for(int i = 0; i < nbLinks_; ++i) {
	  link = net->getLink(i);
	  std::cout << "[" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] " << e_links[i] << " ";
	}
	std::cout << std::endl;//*/
};

FPType DAGraphLUCE::computeStepSize(const std::vector<FPType> &e_links){
	
  //std::cout << "Computing step size" << std::endl;
	FPType alpha = 1.0;
	// TODO: maybe include condition for the first iteration
	FPType sum = 0.0;
	FPType sum2 = 0.0;
	FPType tmp = 0.0;
	LinkFnc *fnc = NULL;
	StarLink *link = NULL;
	int linkIndex = -1;
	bool t = true;
	for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
		std::list<StarLink*> outLinks;
		getOutLinks(i, outLinks);
		for (std::list<StarLink*>::const_iterator it = outLinks.begin(); it != outLinks.end(); ++it){
			link = *it;
			fnc = link->getLinkFnc();
			linkIndex = link->getIndex();
			tmp = e_links[linkIndex] - getOriginFlow(linkIndex);
			//std::cout << "(" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << " [" << e_links[linkIndex] << ", " <<  getOriginFlow(linkIndex) << "] diff = " << tmp << " ";
			//sum += fnc->evaluate(link->getFlow() + alpha * tmp) * tmp;
			//sum2 += link->getTime() * tmp;
			sum += link->getTime() * tmp;
			sum2 += fnc->evaluateDerivative(link->getFlow()) * tmp * tmp; //
			if (sum != sum && t) {
			  std::cout << "flow = " << link->getFlow() << " tmp = " << tmp << " linkInd = " << linkIndex << " e = " << e_links[linkIndex] << " oFlow = " <<  getOriginFlow(linkIndex) << " nbLinks = " << nbLinks_ << std::endl;
			  t = false;
			}
			
		}
	}
	//std::cout << std::endl;
	//std::cout << "sum = " << sum << " sum2 = " << sum2 << std::endl;
	//if (sum >= 0.0) {
	//	if (sum2 >= 0.0) {
	//	  alpha = 0.0;
	//	} else {
		  //alpha = 1.0 / (1 - sum / sum2);
	if (fabs(sum) <= 1e-15) {
	  //  	std::cout << "StepSize = " << 0.0 << std::endl;
		return 0.0;
	}
	if (sum >= 0.0) {
	  //std::cout << "StepSize = " << 0.0 << std::endl;
	  return 0.0;
	}
	alpha = -sum / sum2;
		 
	if (alpha > 1.0) alpha = 1.0;
		  //	}
		  //}
	//std::cout << "StepSize = " << alpha << " sum1 = " << sum << " sum2 = " << sum2 << std::endl;
	return alpha;
};

void DAGraphLUCE::assignNewFlow(FPType stepSize, const std::vector<FPType> &e_links){
  //std::cout << "Assigning new flow" << std::endl;
  StarLink *link = NULL;
  int linkIndex = -1;
  FPType dFlow = 0.0;
  for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
    std::list<StarLink*> outLinks;
    getOutLinks(i, outLinks);
    for (std::list<StarLink*>::const_iterator it = outLinks.begin(); it != outLinks.end(); ++it){
      link = *it;
      linkIndex = link->getIndex();
      dFlow = stepSize * (e_links[linkIndex] - getOriginFlow(linkIndex));
      if (fabs(dFlow) >= getZeroFlow()) {
      	if (dFlow + link->getFlow() <= getZeroFlow()) {
      		link->setFlow(0.0);
      		setOriginFlow(linkIndex, 0.0);
      	} else {
		addOriginFlow(linkIndex, dFlow);
		link->addFlow(dFlow);
	}
      }
      
    }
  }
  //	StarNetwork* net = getNet();
  //	net->print();
};
		
void DAGraphLUCE::update(){
  //std::cout << "Updating" << std::endl;
  StarNetwork* net = getNet();
  //std::cout << "2" << std::endl;
	
  //set to zero derivatives 
  for (int i = 0; i < nbLinks_; ++i){
    derivatives_[i] = 0.0;
  }

  FPType linkFlow = 0.0;
  //std::cout << "NodeFlow size = " << nodeFlows_.size() << std::endl;
  //std::cout << " der size = " <<  derivatives_.size() << std::endl;
  //for(StarNode *node = net->beginNode(); node != NULL; node = net->getNextNode()) {
    //nodeFlow = 0.0;
    //std::cout << "Node = " << node->getIndex();
    for(StarLink *link = net->beginOnlyLink(); link != NULL; link = net->getNextOnlyLink()) {
      //std::cout << "link = " << link->getIndex() << std::endl;
      linkFlow = link->getFlow();
      link->updateTime();
      derivatives_[link->getIndex()] = (link->getLinkFnc())->evaluateDerivative(linkFlow);
      //if (derivatives_[link->getIndex()] <= 1e-10) derivatives_[link->getIndex()] = 1e-7;
      // std::cout << derivatives_[link->getIndex()] << " ";
    }
    //
    //std::cout << "nodeFlow = " << nodeFlows_[node->getIndex()] << std::endl;
    //}
  //std::cout << std::endl;
	
};

void DAGraphLUCE::postUpdateCall(){
      // set nodeFlows to zero
  for (int j = 0; j < nbNodes_; ++j){
    nodeFlowsInv_[j] = 0.0;
  }

  // calculating node flows - for current BUSH
  FPType nodeFlow = 0.0;
  for (int i =  beginDescPass(); i != -1; i = getNextDescPass()) {
    std::list<StarLink*> inLinks;
    getInLinks(i, inLinks);
    nodeFlow = 0.0;
    for (std::list<StarLink*>::const_iterator it = inLinks.begin(); it != inLinks.end(); ++it){
      nodeFlow += getOriginFlow((*it)->getIndex());
    }
    nodeFlowsInv_[i] = nodeFlow;
    //std::cout << "i = " << i << " " << nodeFlowsInv_[i] << "; ";
  }
  //std::cout << std::endl;
  calcFlowPortions();//*/

  /* // set nodeFlows to zero
  for (int j = 0; j < nbNodes_; ++j){
    nodeFlows_[j] = 0.0;
  }

  // calculating node flows - for current BUSH
  FPType nodeFlow = 0.0;
  for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
    std::list<StarLink*> outLinks;
    getOutLinks(i, outLinks);
    nodeFlow = 0.0;
    for (std::list<StarLink*>::const_iterator it = outLinks.begin(); it != outLinks.end(); ++it){
      nodeFlow += getOriginFlow((*it)->getIndex());
    }
    nodeFlows_[i] = nodeFlow;
    std::cout << "i = " << i << " " << nodeFlows_[i] << "; ";
  }
  std::cout << std::endl;
  calcFlowPortions();
  //*/
};
		
void DAGraphLUCE::calcFlowPortions(){
  //std::cout << "Calculating flow portions" << std::endl;
	
  // set flow portions to zero
  for(int j = 0; j < nbLinks_; ++j){
    flowPortionsInv_[j] = 0.0;
  }

  StarLink *link = NULL;
  FPType nodeFlow = 0.0;
  int index = -1;
  for (int i =  beginDescPass(); i != -1; i = getNextDescPass()) {
    std::list<StarLink*> inLinks;
    getInLinks(i, inLinks);
    nodeFlow =  nodeFlowsInv_[i];
    for (std::list<StarLink*>::const_iterator it = inLinks.begin(); it != inLinks.end(); ++it){
      link = *it;
      //std::cout << " link = [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] "; 
      index = link->getIndex();
      if (nodeFlow > 0.0) {
	flowPortionsInv_[index] = getOriginFlow(index) / nodeFlow;
      } else {
	flowPortionsInv_[index] = 0.0;
      }
      //std::cout << flowPortionsInv_[index] << "; ";
    }
  }
  //std::cout << std::endl;//*/
    /*std::cout << "Calculating flow portions" << std::endl;
	
	// set flow portions to zero
	for(int j = 0; j < nbLinks_; ++j){
	  flowPortions_[j] = 0.0;
	}

	StarLink *link = NULL;
	FPType nodeFlow = 0.0;
	int index = -1;
	for (int i =  beginAscPass(); i != -1; i = getNextAscPass()) {
	  std::list<StarLink*> outLinks;
	  getOutLinks(i, outLinks);
	  nodeFlow =  nodeFlows_[i];
	  for (std::list<StarLink*>::const_iterator it = outLinks.begin(); it != outLinks.end(); ++it){
	    link = *it;
	    std::cout << " link = [" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << "] "; 
	    index = link->getIndex();
	    if (nodeFlow > 0.0) {
	      flowPortions_[index] = getOriginFlow(index) / nodeFlow;
	    } else {
	      flowPortions_[index] = 0.0;
	    }
	    std::cout << flowPortions_[index] << "; ";
	  }
	}
	std::cout << std::endl;//*/
};
