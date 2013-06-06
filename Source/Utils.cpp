#include "Utils.h"
#include "UtilsString.h"
#include "Error.h"

#include <cstring>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <math.h>

#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

void Utils::getDisjointLinks(Path *path1, Path *path2, std::list<StarLink*> &list, int nbLinks){
	int indexes[nbLinks];
	for (int i = 0; i < nbLinks; i++) {
		indexes[i] = 0;
	}
	int index = -1;
	for (StarLink *link = path1->beginLink(); link != NULL; link = path1->getNextLink()) {
		index = link->getIndex();
		indexes[index] = 1;
	}
	for (StarLink *link = path2->beginLink(); link != NULL; link = path2->getNextLink()) {
		index = link->getIndex();
		if (indexes[index] == 0) {
			list.push_back(link);
		} else {
			indexes[index] = -1;
		}
	}
	for (StarLink *link = path1->beginLink(); link != NULL; link = path1->getNextLink()) {
		index = link->getIndex();
		if (indexes[index] == 1) {
			list.push_back(link);
		}
	}
	assert(list.size() > 0);
};

void Utils::getCommonLinks(PathBasedFlowMove *paths, std::list<StarLink*> &list, int nbLinks){
	int indexes[nbLinks];
	int indexesTmp[nbLinks];
	StarLink* links[nbLinks];
	int size = 0;
	for (int i = 0; i < nbLinks; i++) {
		indexes[i] = 0;
		indexesTmp[i] = 0;
		links[i] = NULL;
	}
	int index = -1;
	Path *path = NULL;
	int nbPaths = 0;
	for (PathAndDirection *pathDir = paths->beginPathDirection(); pathDir != NULL; pathDir = paths->getNextPathDirection()) {
		path = pathDir->getPath();
		nbPaths++;
		for(StarLink *link = path->beginLink(); link != NULL; link = path->getNextLink()){
			index = link->getIndex();
			if (indexes[index] == 0) {
				indexesTmp[size] = index;
				size++;
				links[index] = link;
			}
			indexes[index]++;
		}
	}
	for (int i = 0; i < size; i++) {
		index = indexesTmp[i];
		if (indexes[index] == nbPaths) {
			list.push_back(links[index]);
		}
	}
};

FPType Utils::checkFeasibility(StarNetwork *net, ODMatrix *mat){
	FPType total[net->getNbNodes()];
	for (int i = 0; i < net->getNbNodes(); i++) {
		total[i] = 0.0;
	}
	// load demands
	for (Origin *origin = mat->beginOrigin(); origin != NULL; origin = mat->getNextOrigin()) {
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			total[origin->getIndex()] += dest->getDemand();
			total[dest->getIndex()] -= dest->getDemand();
		}
	}
	
	//travers network and check
	
	for (StarLink *link = net->beginOnlyLink(); link != NULL; link = net->getNextOnlyLink()) {
		total[link->getNodeFromIndex()] -= link->getFlow();
		total[link->getNodeToIndex()] += link->getFlow();
	}
	FPType max = 0.0;
	for (int i = 0; i < net->getNbNodes(); i++) {
		if (fabs(total[i]) > max) max = fabs(total[i]);
	}
	return max;
};

int Utils::parseSpiessFnc(const std::string& input, SpiessFncCreator &spCreator, bool constFnc){
	 
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(" ", "()="); 
    tokenizer tokens(input, sep);
    int countBrace = 0;
    FPType freeFlow = -1.0;
    FPType capacity = -1.0;
    FPType alpha = -1.0;
    FPType beta = -1.0;
    FPType betaSq = -1.0;
    bool putFound = false;
    bool sqrtFound = false;
    bool delFound = false;
    int sqrtBrace = 0;
    int id = -1;
    int count = 0;
    if (constFnc) {
    	freeFlow = 1.0;
    	capacity = 0.0;
     	alpha = 0.0;
     	beta = 0.0;
     	betaSq = 0.0;
    }
    bool plusLinear = false;
    FPType addParam = 0.0;
    FPType multiplyParam = 0.0;
    
    for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
      //  std::cout << "<" << *tok_iter << "> " << std::endl;
     	std::string tmp = *tok_iter;
     	size_t pos = tmp.find("fd");
     	size_t posU = tmp.find("u");
     	if (pos != std::string::npos){
     		if (pos+2 >= tmp.length()) throw Error("Cannot parse current link cost function");
     		std::string idS = tmp.substr(pos+2);
     		if (!Utils::isInt(idS)) throw Error("Cannot parse current link cost function");
     		id = atoi(idS.c_str());
     		//std::cout << "id = " << id << std::endl;
     	} else if (tmp == "(") {
     		++countBrace;
     		++count;
     		if (sqrtFound) ++sqrtBrace;
     	} else if (tmp == ")") {
     		//if (countBrace < 3) --countBrace;
     		if (sqrtFound) --sqrtBrace;
     		--count;
     	} else if (Utils::isDigits(tmp)) {
     		//std::cout << "digits found = " << tmp << std::endl;
     		if (constFnc) {
	     		freeFlow = atof(tmp.c_str());
	     		break;
	     	} else if (countBrace == 1) {
     			freeFlow = atof(tmp.c_str());
     			//std::cout << "freeFlow = " << freeFlow << std::endl;
     		} else if (countBrace == 2) {
     			if (putFound) {
     				alpha = atof(tmp.c_str());
     				//std::cout << "alpha = " << alpha << std::endl;
     				beta = freeFlow;
     				freeFlow = 1.0;
     				//std::cout << "beta = " << beta << " freeFlow = 1" << std::endl;
     			} else {
     				beta = atof(tmp.c_str());
     				//std::cout << "beta = " << beta << std::endl;
     			}
     		} else if (putFound){
     			if (delFound) {
     				putFound = false;
     				capacity = atof(tmp.c_str());
     				//std::cout << "capacity = " << capacity << std::endl;
     			} else if (tmp != "1"){
     				alpha = atof(tmp.c_str());
     				//std::cout << "alpha = " << alpha << std::endl;
     			}
     		} else if (sqrtFound) {
     			if (sqrtBrace == 1) {
     				betaSq = atof(tmp.c_str());
     				//std::cout << "betaSq = " << betaSq << std::endl;
     				sqrtFound = false;
     			}
     		} else if (count == 0) {
     			//std::cout << "strange" << std::endl;
     			//return -1;
     			addParam = atof(tmp.c_str());
     		} /*else {
     			std::cout << "strange" << std::endl;
     			return -1;
     		}*/
     	} else if (tmp == "put") {
     		putFound = true;
     	} else if (tmp == "sqrt") {
     		sqrtFound = true;
     	} else if (tmp == "/" && putFound) {
     		delFound = true;
     	} else if (posU != std::string::npos && tmp != "volau") {
     		if (posU == 0) throw Error("There must be a number before u in link function description.");
     		std::string firstNum = tmp.substr(0, posU);
     		std::string secondNum = tmp.substr(posU + 1);
     		std::string newStr = firstNum + "." + secondNum;
     		//std::cout << "firstNum = |" << firstNum << "|, secondNum = |" << secondNum << "|" << " newStr = " << newStr << std::endl;
     		multiplyParam = atof(newStr.c_str()) * 1e-8;
     		plusLinear = true;
     	} 
     	
    }
    //std::cout << "countBrace = " << countBrace << std::endl;
    if (freeFlow < 0.0 || capacity < 0.0 || alpha < 0.0 || beta < 0.0 || betaSq < 0.0 || id == -1) throw Error("Parsing string failed");
    if (constFnc) {
    	spCreator.setParams(freeFlow);
    } else {
    	spCreator.setParams(freeFlow, capacity, alpha, beta, betaSq);
    }
    if (plusLinear) {
    	spCreator.setParamsLinear(addParam, multiplyParam);
    	printf("multiply = %e \n", multiplyParam);
    	std::cout << "PlusLinearFnc is parsed: add = " << addParam << " multiply = " << multiplyParam << std::endl;
    }
    return id;
};

/**  Checks that:
 **   -- the total flow in the paths of each ODSet add up to the demand from @mat
 **   -- all paths are valid as per Utils::checkPathIsValid(Path, int, int)
 **/
bool Utils::checkPathSetFeasibility(PathSet * pathSet, ODMatrix * mat, StarNetwork * net) {
	ODSet * odSet = pathSet->beginSet();
	for(Origin *origin = mat->beginOrigin(); origin != NULL; origin = mat->getNextOrigin()) {
		if(origin->isEmpty()) {
			continue;
		}
		for(PairOD * dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()) {
			FPType totalFlow = 0.0;
			for(Path * path = odSet->beginPath(); path != NULL; path = odSet->getNextPath()) {
				totalFlow += path->getFlow();
				if (!checkPathIsValid(path, origin->getIndex(), dest->getIndex(), net->getNbNodes())) {
					odSet->print();
					break;
					return false;
				}
			}
			if(fabs(totalFlow - dest->getDemand()) > 10e-6) {
				std::cout <<  "ODSet flow doesn't match OD demand. Demand = " << dest->getDemand() << ", OD Set :\n";
				odSet->print();
				return false;
				//throw Error("PathSet Infeasible");
			}
			odSet = pathSet->getNextSet();
		}
	}
	return true;
};

/**  Checks that:
 **   -- the path starts at @originIndex and ends at @destIndex
 **   -- the nodeFrom each link is equal to the nodeTo of the previous link
 **   -- each node along the path is visited only once
 **/
bool Utils::checkPathIsValid(Path * path, int originIndex, int destIndex, int nbNodes) {
	StarLink * prevLink = NULL;
	std::vector<bool> onceEachNode(nbNodes, false);
	for(StarLink * currLink = path->beginLink(); currLink != NULL; currLink = path->getNextLink()) {
		if(prevLink == NULL) {
			if(currLink->getNodeFromIndex() != originIndex) {
				std::cout << "Incorrect origin for path\n";
				return false;
			}
		} else if(prevLink->getNodeToIndex() != currLink->getNodeFromIndex()) {
			std::cout << "pTo " << prevLink->getNodeToIndex() << " : cFr " << currLink->getNodeFromIndex() << std::endl;
			std::cout << "pTo " << prevLink->getNodeTo() << " : cFr " << currLink->getNodeFrom() << std::endl;
			std::cout << "path not valid!\n";
			return false;
		}
		if(onceEachNode[currLink->getNodeFromIndex()]) {
			std::cout << "repeated node " << currLink->getNodeFrom() << ", index " << currLink->getNodeFromIndex() << std::endl;
			return false;
		}
		onceEachNode[currLink->getNodeFromIndex()] = true;
		prevLink = currLink;
	}
	if(prevLink->getNodeToIndex() != destIndex) {
		std::cout << "Incorrct destination for path\n";
		return false;
	}
	return true;
};
