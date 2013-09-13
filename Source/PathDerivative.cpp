#include "PathDerivative.h"
#include "Utils.h"

PathDerivative::PathDerivative(int nbLinks) : _nbLinks(nbLinks){

};

PathDerivative::~PathDerivative(){

};

FPType PathDerivative::calculate(Path *path, Path *minPath){
	assert(_nbLinks > 0);
	std::list<StarLink*> list;
	Utils::getDisjointLinks(path, minPath, list, _nbLinks);
	return calculateForDisjoint(list);
	/*StarLink* link = NULL;
	for (std::list<StarLink*>::iterator it = list.begin(); it != list.end(); it++) {
		link = *it;
		//der += link->getDerivative(); 
		der += (link->getLinkFnc())->evaluateDerivative(link->getFlow());
	}*/
};

FPType PathDerivative::calculateForDisjoint(const std::list<StarLink*> &list){
	StarLink* link = NULL;
	FPType der = 0.0;
	for (std::list<StarLink*>::const_iterator it = list.begin(); it != list.end(); it++) {
		link = *it;
		//der += link->getDerivative(); 
		der += (link->getLinkFnc())->evaluateDerivative(link->getFlow());
	}
	return der;
};

FPType PathDerivative::calculateForDisjoint2(const std::list<StarLink*> &list1, const std::list<StarLink*> &list2){
	return calculateForDisjoint(list1) + calculateForDisjoint(list2);
};
