#include "PathDerivative.h"
#include "Utils.h"

PathDerivative::PathDerivative(int nbLinks){
	_nbLinks = nbLinks;
};

PathDerivative::~PathDerivative(){

};

FPType PathDerivative::calculate(Path *path, Path *minPath){
	std::list<StarLink*> list;
	Utils::getDisjointLinks(path, minPath, list, _nbLinks);
	FPType der = 0.0;
	StarLink* link = NULL;
	for (std::list<StarLink*>::iterator it = list.begin(); it != list.end(); it++) {
		link = *it;
		der += (link->getLinkFnc())->evaluateDerivative(link->getFlow());
	}
	return der;
};

